cmake_minimum_required(VERSION 3.6)
project(PostfixParser)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++03")
set(SOURCE_FILES main.cpp node/CNode.h CParser.h CParser.cpp node/ESymbol.h node/CTree.cpp node/CTree.h node/CUnaryNode.h node/CBinaryNode.h utils.h node/ESymbol.cpp node/CNode.cpp node/CUnaryNode.cpp node/CBinaryNode.cpp)

add_executable(PostfixParser ${SOURCE_FILES})