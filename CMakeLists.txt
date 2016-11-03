cmake_minimum_required(VERSION 3.6)
project(PostfixParser)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++03")

set(SOURCE_FILES main.cpp CParser.cpp CParser.h CNode.cpp CNode.h CToken.cpp CToken.h)
add_executable(PostfixParser ${SOURCE_FILES})