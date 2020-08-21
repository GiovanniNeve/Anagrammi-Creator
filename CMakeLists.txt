cmake_minimum_required(VERSION 3.17)
project(Anagrammi_Creator)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Anagrammi_Creator
        CMakeLists.txt
        mainFile.cpp functions.h)

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
