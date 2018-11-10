cmake_minimum_required(VERSION 3.12)
project(GeneticAlgorithm)

set(CMAKE_CXX_STANDARD 14)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -pedantic -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(GeneticAlgorithm main.cpp City.cpp City.hpp Tour.cpp Tour.hpp Population.cpp Population.hpp GeneticAlgorithm.cpp GeneticAlgorithm.hpp RandomGenerator.cpp RandomGenerator.hpp)