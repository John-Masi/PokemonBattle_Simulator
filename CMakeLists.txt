cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(pokemon)


file(GLOB SOURCES "src/*.cpp")
add_executable(pokemon test.cpp ${SOURCES})
target_compile_features(pokemon PRIVATE cxx_std_20)
