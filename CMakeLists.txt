cmake_minimum_required(VERSION 3.5.0)

project(JPEGreande CXX)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE CPP_FILES "src/*.cpp")

add_executable(JPEGrenade ${CPP_FILES})