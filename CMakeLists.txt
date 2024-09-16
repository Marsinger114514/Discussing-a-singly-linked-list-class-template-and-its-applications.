cmake_minimum_required(VERSION 3.10)
project(work3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")
add_executable(work3 Main.cpp Test.cpp Admissioncard.cpp)
