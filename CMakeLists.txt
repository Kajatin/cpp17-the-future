cmake_minimum_required(VERSION 3.10)
project(future VERSION 0.1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

message("-- Building using ${CMAKE_BUILD_TYPE} mode")

add_executable(future main.cpp)
#target_link_libraries(future lib)
