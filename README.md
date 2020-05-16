# Game_of_Life

Conwoy's Game of Life in C with SDL

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

What things you need to install the software and how to install them (for Ubuntu)

```
Simple DirectMedia Layer : 
  sudo apt-get install libsdl2-2.0
CUnit: 
  sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev
CMake: 
  wget https://github.com/Kitware/CMake/releases/download/v3.15.2/cmake-3.15.2.tar.gz
  tar -zxvf cmake-3.15.2.tar.gz
  cd cmake-3.15.2
  ./bootstrap
  make
  sudo make install
  
```

### Installing

A step by step series of examples that tell you how to get a development env running

Say what the step will be

```
mkdir build
cd build
cmake ..
make
```

And running 
```
./Gol [OPTION]
  [OPTION]: 0 for clipped, 1 for circular.
```


## Running the tests

```
cmake -V
```


