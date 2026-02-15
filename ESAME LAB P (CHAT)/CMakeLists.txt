# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(YourProjectName)

# Other existing configurations

# Find GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add test directory
add_executable(runTests test/test.cpp)

target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

# Optionally add tests
enable_testing()
add_test(NAME exampleTest COMMAND runTests)