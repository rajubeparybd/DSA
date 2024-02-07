cmake_minimum_required(VERSION 3.27)
project(DSA)

set(CMAKE_CXX_STANDARD 17)

add_executable(DSA "maxHeap.cpp")
add_executable(knapsack "Greedy/knapsack.cpp")
add_executable(activitySelection "Greedy/activitySelection.cpp")
