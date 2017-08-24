cmake_minimum_required(VERSION 3.5)
project(weis_award)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES WeisAward.cpp)
add_executable(weisAward ${SOURCE_FILES})

#Setting bin file
install(TARGETS weisAward DESTINATION bin)

#Necessary for reading
target_compile_definitions(weisAward PUBLIC -DPROJECT_DIRECTORY="${CMAKE_SOURCE_DIR}/in-out")
