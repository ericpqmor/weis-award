# Weis Award
Weis Award is a prize created to reward ITA (Aeronautics Institute of Technology) best teachers. The award is set every semester by ITA's DA (Academic Department).
This software was made as an improve to Weis Award, allowing the results to be generated in a second, sparing the time necessary to count every student's vote. Also the software has a statistics tool to register vote percentages and useful data.

## Requirements and Installing: 
The simulator was developed in Ubuntu 14.04 platform. For any other Operational System the software code is not garanteed to work properly. For Linux-based systems, the steps regarding dependecies installing may vary.

* To be able to compile the project, you need CMake. It may be installed automatically by
```sh
$ sudo apt-get install cmake
```
It is required a minimal version of CMake 3.5 to build the project. If apt-get doesn't install a sufficiently new version, please refer to the official website https://cmake.org/ to a newer version.

To check your CMake version, just type
```
$ cmake --version
```

## Building the project:
* If everything is in its place and you have already cloned the repository, you may set the building process simply by opening the created "Source" folder in console and typing
```sh
$ cmake .
```
* This will automatically generate a Makefile file. To finally build the project and execute the program just invoke make and execute the binary
```sh
$ make
$ ./bin/Weis_Award
```
