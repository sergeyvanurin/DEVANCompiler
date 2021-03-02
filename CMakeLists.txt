cmake_minimum_required(VERSION 3.16)

include_directories(/usr/local/opt/flex/include)

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
        Expressions/AddExpression.cpp Expressions/AddExpression.h Expressions/Expression.h Bases/BaseElement.h Visitors/Visitor.h Visitors/ForwardDeclaration.h Expressions/SubExpression.cpp Expressions/SubExpression.h Expressions/MulExpression.cpp Expressions/MulExpression.h Expressions/DivClass.cpp Expressions/DivClass.h Statements/MainClass.cpp Statements/MainClass.h Statements/Statement.h Statements/Assert.cpp Statements/Assert.h Statements/VarDeclaration.cpp Statements/VarDeclaration.h Statements/IfElse.cpp Statements/IfElse.h Statements/While.cpp Statements/While.h Statements/VarAssignment.cpp Statements/VarAssignment.h AST/AST.cpp AST/AST.h Expressions/IdentExpression.cpp Expressions/IdentExpression.h Expressions/NumExpression.cpp Expressions/NumExpression.h)

target_include_directories(Compiler PRIVATE ${DEVANCompiler_SOURCE_DIR})

