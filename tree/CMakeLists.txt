cmake_minimum_required(VERSION 3.6)
project(tree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++03")
set(SOURCE_FILES CNode.h ESymbol.h CTree.cpp CTree.h CUnaryNode.h CBinaryNode.h ../utils.h ESymbol.cpp CNode.cpp CUnaryNode.cpp CBinaryNode.cpp)

add_library(tree ${SOURCE_FILES})