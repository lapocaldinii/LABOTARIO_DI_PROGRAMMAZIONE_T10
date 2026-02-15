# CMakeLists.txt for Google Test

cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ESAME_LAB_P_CHT)

# Include GoogleTest as a subdirectory
add_subdirectory(googletest)

# Declare the testing executable
add_executable(runTests test_file.cpp)

# Link the Google Test libraries
target_link_libraries(runTests gtest gtest_main)

# Add a test
add_test(NAME sample_test COMMAND runTests)