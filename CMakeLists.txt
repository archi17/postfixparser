cmake_minimum_required(VERSION 3.6)
project(PostfixParser)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++03")
set(SOURCE_FILES main.cpp node/CNode.h CParser.h CParser.cpp ESymbol.h CLogEntry.cpp CLogEntry.h CTree.cpp CTree.h node/CUnaryNode.h node/CBinaryNode.h node/CPlusNode.cpp node/CPlusNode.h node/CMinusNode.cpp node/CMinusNode.h node/CTimesNode.cpp node/CTimesNode.h node/CDivideNode.cpp node/CDivideNode.h node/CTildeNode.cpp node/CTildeNode.h node/CVarNode.cpp node/CVarNode.h node/CNumNode.cpp node/CNumNode.h utils.h ESymbol.cpp node/CNode.cpp node/CUnaryNode.cpp node/CBinaryNode.cpp)

add_executable(PostfixParser ${SOURCE_FILES})