cmake_minimum_required(VERSION 3.22)
project(2_4_0)

set(CMAKE_CXX_STANDARD 20)

add_executable(2_4_0 main.cpp
        BinarySearchTree/BinarySearchTree.cpp BinarySearchTree/BinarySearchTree.h
        Data/Data.cpp Data/Data.h)
