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
        Expressions/BinaryExpression/ArithmeticExpressions/AddExpression.cpp Expressions/BinaryExpression/ArithmeticExpressions/AddExpression.h Expressions/Expression.h Bases/BaseElement.h Visitors/Visitor.h Visitors/ForwardDeclaration.h Expressions/BinaryExpression/ArithmeticExpressions/SubExpression.cpp Expressions/BinaryExpression/ArithmeticExpressions/SubExpression.h Expressions/BinaryExpression/ArithmeticExpressions/MulExpression.cpp Expressions/BinaryExpression/ArithmeticExpressions/MulExpression.h Expressions/BinaryExpression/ArithmeticExpressions/DivExpression.cpp Expressions/BinaryExpression/ArithmeticExpressions/DivExpression.h Expressions/BinaryExpression/ArithmeticExpressions/ModExpression.cpp Expressions/BinaryExpression/ArithmeticExpressions/ModExpression.h Statements/MainClass.cpp Statements/MainClass.h Statements/Statement.h Statements/Assert.cpp Statements/Assert.h Statements/VarDeclaration.cpp Statements/VarDeclaration.h Statements/IfElse.cpp Statements/IfElse.h Statements/While.cpp Statements/While.h Statements/VarAssignment.cpp Statements/VarAssignment.h AST/AST.cpp AST/AST.h Expressions/IdentExpression.cpp Expressions/IdentExpression.h Expressions/ConstantExpression/NumExpression.cpp Expressions/ConstantExpression/NumExpression.h Statements/Statement.cpp Statements/Program.cpp Statements/Program.h Statements/ClassDeclaration.cpp Statements/ClassDeclaration.h Statements/StatementList.cpp Statements/StatementList.h Visitors/PrintVisitor.cpp Visitors/PrintVisitor.h Visitors/Elements.h Statements/DeclarationList.cpp Statements/DeclarationList.h Statements/MethodDeclaration.cpp Statements/MethodDeclaration.h Expressions/IndexExpression.cpp Expressions/IndexExpression.h Expressions/BinaryExpression/LogicalExpression/LogicalAndExpression.cpp Expressions/BinaryExpression/LogicalExpression/LogicalAndExpression.h Expressions/BinaryExpression/LogicalExpression/LogicalOrExpression.cpp Expressions/BinaryExpression/LogicalExpression/LogicalOrExpression.h Expressions/BinaryExpression/ComparisonExpressions/LessExpression.cpp Expressions/BinaryExpression/ComparisonExpressions/LessExpression.h Expressions/BinaryExpression/ComparisonExpressions/GreaterExpression.cpp Expressions/BinaryExpression/ComparisonExpressions/GreaterExpression.h Expressions/BinaryExpression/EqualExpression.cpp Expressions/BinaryExpression/EqualExpression.h Expressions/UnaryExpression/NotExpression.cpp Expressions/UnaryExpression/NotExpression.h Expressions/ConstantExpression/TrueExpression.cpp Expressions/ConstantExpression/TrueExpression.h Expressions/ConstantExpression/FalseExpression.cpp Expressions/ConstantExpression/FalseExpression.h Expressions/FieldInvokeExpression.cpp Expressions/FieldInvokeExpression.h Statements/ClassDeclarationList.cpp Statements/ClassDeclarationList.h Statements/Formal.cpp Statements/Formal.h Statements/FormalsList.cpp Statements/FormalsList.h Statements/Print.cpp Statements/Print.h Statements/Return.cpp Statements/Return.h Statements/MethodInvocation.cpp Statements/MethodInvocation.h Statements/ExpressionList.cpp Statements/ExpressionList.h Expressions/LengthExpression.cpp Expressions/LengthExpression.h Expressions/ThisExpression.cpp Expressions/ThisExpression.h Visitors/InterpreterVisitor.cpp Visitors/InterpreterVisitor.h SymbolTable/SymbolTable.cpp SymbolTable/SymbolTable.h Symbols/BaseSymbol.cpp Symbols/BaseSymbol.h Objects/Object.cpp Objects/Object.h Objects/Int.cpp Objects/Int.h Objects/Bool.cpp Objects/Bool.h Symbols/STMethod.cpp Symbols/STMethod.h Symbols/STVariable.cpp Symbols/STVariable.h Symbols/STArgument.cpp Symbols/STArgument.h Statements/FormalsList.cpp Statements/FormalsList.h Statements/Formal.cpp Statements/Formal.h Symbols/STClass.cpp Symbols/STClass.h Visitors/SymbolTreeVisitor.cpp Visitors/SymbolTreeVisitor.h SymbolTable/ScopeLayer.cpp SymbolTable/ScopeLayer.h SymbolTable/ScopeLayerTree.cpp SymbolTable/ScopeLayerTree.h Expressions/BinaryExpression/BinaryExpression.cpp Expressions/BinaryExpression/BinaryExpression.h Expressions/BinaryExpression/ArithmeticExpressions/ArithmeticExpression.cpp Expressions/BinaryExpression/ArithmeticExpressions/ArithmeticExpression.h Expressions/BinaryExpression/LogicalExpression/LogicalExpression.cpp Expressions/BinaryExpression/LogicalExpression/LogicalExpression.h Expressions/BinaryExpression/ComparisonExpressions/ComparisonExpression.cpp Expressions/BinaryExpression/ComparisonExpressions/ComparisonExpression.h Symbols/Type.cpp Symbols/Type.h Bases/BaseElement.h)

target_include_directories(Compiler PRIVATE ${DEVANCompiler_SOURCE_DIR})

