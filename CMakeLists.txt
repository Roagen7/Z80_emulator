cmake_minimum_required(VERSION 3.22)
project(z80)

set(CMAKE_CXX_STANDARD 20)

add_executable(z80 main.cpp Z80.cpp Z80.h type.h addressing_modes.cpp opcodes.cpp lookup.cpp Memory.h Memory.cpp)
