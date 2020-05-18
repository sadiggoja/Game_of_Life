# Game_of_Life

Conwoy's Game of Life in C with SDL

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

What things you need to install the software and how to install them (for Ubuntu)

```
Simple DirectMedia Layer : 
  sudo apt-get install libsdl2-2.0 libsdl2-dev
CUnit: 
  sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev
  sudo apt-get install gcovr ( It's for cover & cover_html targets )
CMake: 
  wget https://github.com/Kitware/CMake/releases/download/v3.17.1/cmake-3.17.1.tar.gz
  tar -zxvf cmake-3.17.1.tar.gz
  cd cmake-3.17.1
  ./bootstrap
  make
  sudo make install
Doxygen:( It's for docs target)  
  sudo apt install doxygen
```
### Installing

A step by step series of examples that tell you how to get a development env running

Say what the step will be ( After opening terminal in source folder ( root folder of the project)

```
mkdir build
cd build
cmake ..
make
```
## Custom Targets and run steps of Game_of_Life
### Doc folder
There is a Doc folder pregenerated for u, that you can observe source documentation before using it.
With html and latex pages.
### Branches
In branch Makefile 
```
make all 
make docs ( Creates source documentation a Doxygen folder which includes html and latex pages)
make dist ( Creates tar file )
make clean 
```
In master
```
make cover
make cover_html
make dist
make docs
```
Running : Gol target (main target of the game )
```
./Gol [OPTION]
  [OPTION]: 0 for clipped, 1 for circular.
```
input the type if [OPTION] is not added from terminal
input size
input selection for SDL 

## Running the tests

```
ctest -V
```
see results in Testing folder

## Continuous Integration

You can already find binary zip folder in the Action section of the repository , which includes all the main targets itself.

## Authors or just students of UFAZ Computer Science L2
* **Javid Guliyev**
* **Sadig Gojayev**
