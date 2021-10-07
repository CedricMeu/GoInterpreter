cmake_minimum_required(VERSION 3.17)
project(GoInterpreter)

set(CMAKE_CXX_STANDARD 20)

find_package(BISON)
find_package(FLEX)

FLEX_TARGET(Lexer src/lexing/lexer.l ../src/lexing/lexer.cpp)
BISON_TARGET(Parser src/parsing/parser.y ../src/parsing/parser.cpp
        DEFINES_FILE ../include/parsing/parser.hpp
        VERBOSE)
ADD_FLEX_BISON_DEPENDENCY(Lexer Parser)

include_directories(include)
file(GLOB src src/**.cpp src/**.c)

add_executable(GoInterpreter
        ${FLEX_Lexer_OUTPUTS}
        ${BISON_Parser_OUTPUTS}
        ${src})