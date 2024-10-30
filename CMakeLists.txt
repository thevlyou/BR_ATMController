cmake_minimum_required(VERSION 3.29)
project(BearCodingTest)

set(CMAKE_CXX_STANDARD 20)

add_executable(BearCodingTest main.cpp
        ATMController.cpp
        ATMController.hpp
        testset.hpp)
