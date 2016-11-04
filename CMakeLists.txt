cmake_minimum_required(VERSION 3.6)
project(PostfixParser)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++03")
set(SOURCE_FILES main.cpp CToken.h CToken.cpp CNode.h CNode.cpp CParser.h CParser.cpp CSymbol.h)

add_executable(PostfixParser ${SOURCE_FILES})