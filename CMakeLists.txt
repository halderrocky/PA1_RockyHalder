cmake_minimum_required(VERSION 4.3)
project(pointers)

set(CMAKE_CXX_STANDARD 20)

add_executable(pointers main.cpp
        ArrayList.h
        node.h
        Data.h
        LinkedList.h
        List.h
        Player.h
)
