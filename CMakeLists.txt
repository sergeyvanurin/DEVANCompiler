cmake_minimum_required(VERSION 3.16)

project(DEVANCompiler)
set(
        HEADERS
        ${DEVANCompiler_SOURCE_DIR}/driver.hpp
        ${DEVANCompiler_SOURCE_DIR}/parser.hpp
)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

BISON_TARGET(
        MyParser
        parser.y
        ${DEVANCompiler_SOURCE_DIR}/parser.cpp
        COMPILE_FLAGS --graph
        DEFINES_FILE ${DEVANCompiler_SOURCE_DIR}/parser.hpp
)

FLEX_TARGET(
        MyScanner
        scanner.l
        ${DEVANCompiler_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

add_executable(
        Compiler
        main.cpp
        driver.cpp
        ${BISON_MyParser_OUTPUTS}
        ${FLEX_MyScanner_OUTPUTS}
)
target_include_directories(Compiler PRIVATE ${DEVANCompiler_SOURCE_DIR})

