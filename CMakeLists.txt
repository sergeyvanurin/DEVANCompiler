cmake_minimum_required(VERSION 3.16)

include_directories(/usr/local/opt/flex/include)
add_compile_options(-std=c++17)

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
        Expressions/AddExpression.cpp Expressions/AddExpression.h Expressions/Expression.h Bases/BaseElement.h Visitors/Visitor.h Visitors/ForwardDeclaration.h Expressions/SubExpression.cpp Expressions/SubExpression.h Expressions/MulExpression.cpp Expressions/MulExpression.h Expressions/DivExpression.cpp Expressions/DivExpression.h Expressions/ModExpression.cpp Expressions/ModExpression.h Statements/MainClass.cpp Statements/MainClass.h Statements/Statement.h Statements/Assert.cpp Statements/Assert.h Statements/VarDeclaration.cpp Statements/VarDeclaration.h Statements/IfElse.cpp Statements/IfElse.h Statements/While.cpp Statements/While.h Statements/VarAssignment.cpp Statements/VarAssignment.h AST/AST.cpp AST/AST.h Expressions/IdentExpression.cpp Expressions/IdentExpression.h Expressions/NumExpression.cpp Expressions/NumExpression.h Statements/Scope.cpp Statements/Scope.h Statements/Statement.cpp Statements/Program.cpp Statements/Program.h Statements/ClassDeclaration.cpp Statements/ClassDeclaration.h Statements/StatementList.cpp Statements/StatementList.h Visitors/PrintVisitor.cpp Visitors/PrintVisitor.h Visitors/Elements.h Statements/DeclarationList.cpp Statements/DeclarationList.h Statements/MethodDeclaration.cpp Statements/MethodDeclaration.h Expressions/IndexExpression.cpp Expressions/IndexExpression.h Expressions/LogicalAndExpression.cpp Expressions/LogicalAndExpression.h Expressions/LogicalOrExpression.cpp Expressions/LogicalOrExpression.h Expressions/LessExpression.cpp Expressions/LessExpression.h Expressions/GreaterExpression.cpp Expressions/GreaterExpression.h Expressions/EqualExpression.cpp Expressions/EqualExpression.h Expressions/NotExpression.cpp Expressions/NotExpression.h Expressions/TrueExpression.cpp Expressions/TrueExpression.h Expressions/FalseExpression.cpp Expressions/FalseExpression.h Expressions/FieldInvocExpression.cpp Expressions/FieldInvocExpression.h Statements/ClassDeclarationList.cpp Statements/ClassDeclarationList.h Statements/Formal.cpp Statements/Formal.h Statements/FormalsList.cpp Statements/FormalsList.h Statements/Print.cpp Statements/Print.h Statements/Return.cpp Statements/Return.h Statements/MethodInvocation.cpp Statements/MethodInvocation.h Statements/ExpressionList.cpp Statements/ExpressionList.h Expressions/LengthExpression.cpp Expressions/LengthExpression.h Expressions/ThisExpression.cpp Expressions/ThisExpression.h Visitors/InterpreterVisitor.cpp Visitors/InterpreterVisitor.h SymbolTable/SymbolTable.cpp SymbolTable/SymbolTable.h Symbols/BaseSymbol.cpp Symbols/BaseSymbol.h Objects/Object.cpp Objects/Object.h Objects/Int.cpp Objects/Int.h Objects/Bool.cpp Objects/Bool.h Symbols/STMethod.cpp Symbols/STMethod.h Symbols/STVariable.cpp Symbols/STVariable.h Symbols/STArgument.cpp Symbols/STArgument.h Statements/FormalsList.cpp Statements/FormalsList.h Statements/Formal.cpp Statements/Formal.h Symbols/STClass.cpp Symbols/STClass.h)

target_include_directories(Compiler PRIVATE ${DEVANCompiler_SOURCE_DIR})

