cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(pokemon)

include(FetchContent)
FetchContent_Declare(
  googletest 
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
file(GLOB SOURCES "src/*.cpp")
add_executable(pokemon main.cpp src/trainer.cpp ${SOURCES})
target_compile_features(pokemon PRIVATE cxx_std_20)
target_include_directories(pokemon PRIVATE include)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(
	tests
	tests.cc
	src/trainer.cpp
)
target_link_libraries(
	tests
	GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(tests)
