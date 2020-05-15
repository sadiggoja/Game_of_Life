cmake_minimum_required(VERSION 2.8.9)
project (Gol)



cmake_policy(SET CMP0076 NEW)


add_subdirectory(Game)
add_subdirectory(Drawing)

find_package(SDL2 CONFIG REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(Gol main.c)
target_link_libraries(Gol PUBLIC game draw )




set(Test_PROJECT libtest)
add_executable(${Test_PROJECT})
target_sources(${Test_PROJECT} PUBLIC cunit_t.c)
target_link_libraries(${Test_PROJECT} PUBLIC game draw cunit)

#Ctests

enable_testing()
add_test(NAME "MyTests1" COMMAND ${Test_PROJECT})

#Coverage

add_custom_target(cover 
COMMAND cmake --build  .  --target test
COMMAND gcovr -r ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR} $<TARGET_FILE:${Test_PROJECT}>
WORKING_DIRECTORY ${CMAKE_BINARY_DIR}	)

add_custom_target(cover_html
COMMAND cmake --build . --target test
COMMAND gcovr --html --html-detail -o index.html -r ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR} $<TARGET_FILE:${Test_PROJECT}>
WORKING_DIRECTORY ${CMAKE_BINARY_DIR}	)

#add_custom_target(dist ALL COMMAND tar -czvf Gol.taz.gz ${CMAKE_BINARY_DIR} )

#DOXYGEN
find_package(Doxygen)

if(DOXYGEN_FOUND)

 
  
    configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)


ADD_CUSTOM_TARGET(docs
   COMMAND echo "Creating html and latex documentation..."
   COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMAND firefox ${CMAKE_CURRENT_SOURCE_DIR}/Doc/html/index.html
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

endif(DOXYGEN_FOUND)

#TAR DIST

add_custom_target(dist  COMMAND
    ${CMAKE_COMMAND} -E tar "czvf" "Gameoflife.tgz" ${CMAKE_CURRENT_SOURCE_DIR} )



