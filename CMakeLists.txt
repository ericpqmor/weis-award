cmake_minimum_required(VERSION 3.5)
project(Weis_Award)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/WeisAward.cpp)
add_executable(Weis_Award ${SOURCE_FILES})


#Setting bin file
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH  ${CMAKE_SOURCE_DIR}/bin)

#Necessary for reading
target_compile_definitions(Weis_Award PUBLIC -DPROJECT_DIRECTORY="${CMAKE_SOURCE_DIR}/in-out")
