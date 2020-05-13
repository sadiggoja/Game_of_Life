# CMake generated Testfile for 
# Source directory: /home/sadig/Desktop/ufaz/dev/game_of_life/Game_of_Life
# Build directory: /home/sadig/Desktop/ufaz/dev/game_of_life/Game_of_Life/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(MyTests1 "/home/sadig/Desktop/ufaz/dev/game_of_life/Game_of_Life/build/libtest")
set_tests_properties(MyTests1 PROPERTIES  _BACKTRACE_TRIPLES "/home/sadig/Desktop/ufaz/dev/game_of_life/Game_of_Life/CMakeLists.txt;27;add_test;/home/sadig/Desktop/ufaz/dev/game_of_life/Game_of_Life/CMakeLists.txt;0;")
subdirs("Game")
subdirs("Drawing")
