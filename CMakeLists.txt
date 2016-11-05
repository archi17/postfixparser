cmake_minimum_required(VERSION 3.6)
project(PostfixParser)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++03")
set(SOURCE_FILES main.cpp CParser.h CParser.cpp utils.h CError.cpp CError.h)

add_subdirectory(tree)

find_package(Curses REQUIRED)
include_directories( ${CURSES_INCLUDE_DIRS} )

add_executable(PostfixParser ${SOURCE_FILES})
target_link_libraries(PostfixParser ${CURSES_LIBRARIES} tree)
