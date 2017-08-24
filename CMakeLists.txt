cmake_minimum_required(VERSION 3.5)
project(weis_award)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES WeisAward.cpp)
add_executable(weisAward ${SOURCE_FILES})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out)
target_compile_definitions(weisAward PUBLIC -DPROJECT_DIRECTORY="${CMAKE_SOURCE_DIR}")
