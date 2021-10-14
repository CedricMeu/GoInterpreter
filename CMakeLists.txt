cmake_minimum_required(VERSION 3.17)
project(GoInterpreter)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wno-writable-strings")

set(FLEX_LIB "/user/local/opt/flex/lib/libfl.a")
set(FLEX_INCLUDE "/user/local/opt/flex/include")
set(BISON_LIB "/user/local/opt/bison@2.7/lib/liby.a")
set(BISON_INCLUDE "/user/local/opt/bison@2.7/include")


add_custom_command(
        OUTPUT src/lexing/lexer.cpp
        COMMAND flex -o src/lexing/lexer.cpp src/lexing/lexer.l
        DEPENDS src/lexing/lexer.l)

add_custom_command(
        OUTPUT src/parsing/parser.cpp
        COMMAND bison -v -o src/parsing/parser.cpp src/parsing/parser.y 
        DEPENDS src/parsing/parser.y)

include_directories(include ${FLEX_INCLUDE} ${BISON_INCLUDE})
file(GLOB src src/*.c src/*.cpp src/*/*.cpp src/*/*.c)

add_executable(GoInterpreter ${src} src/lexing/lexer.cpp src/parsing/parser.cpp)