cmake_minimum_required(VERSION 2.6)
project(hasher)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")

# Library

add_library(hashlib
	src/hash.cpp
	src/hash.h)

set_target_properties(hashlib PROPERTIES
	CXX_STANDARD 11
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO)

# Program itself

add_executable(hasher src/main.cpp)

add_dependencies(hasher hashlib)

set_target_properties(hasher PROPERTIES
	CXX_STANDARD 11
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO)

target_link_libraries(hasher hashlib)

# Unittests

add_executable(hashlib_unittests
	tests/main.cpp
	tests/hashlib_test.cpp)

set_target_properties(hashlib_unittests PROPERTIES
	CXX_STANDARD 11
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO)

target_include_directories(hashlib_unittests PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
	"${PROJECT_SOURCE_DIR}/tests/gtest/googletest"
	"${PROJECT_SOURCE_DIR}/tests/gtest/googletest/include")

add_dependencies(hashlib_unittests hashlib)
target_link_libraries(hashlib_unittests hashlib)

find_package(Threads REQUIRED)
target_link_libraries(hashlib_unittests ${CMAKE_THREAD_LIBS_INIT})
