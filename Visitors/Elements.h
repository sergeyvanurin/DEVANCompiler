//
// Created by Sergey Vanurin on 04.03.2021.
//

#ifndef DEVANCOMPILER_ELEMENTS_H
#define DEVANCOMPILER_ELEMENTS_H

#include "Expressions/Expression.h"
#include "Expressions/IdentExpression.h"
#include "Expressions/BinaryExpression/ArithmeticExpressions/AddExpression.h"
#include "Expressions/BinaryExpression/ArithmeticExpressions/MulExpression.h"
#include "Expressions/BinaryExpression/ArithmeticExpressions/DivExpression.h"
#include "Expressions/BinaryExpression/ArithmeticExpressions/ModExpression.h"
#include "Expressions/IndexExpression.h"
#include "Expressions/BinaryExpression/LogicalExpression/LogicalAndExpression.h"
#include "Expressions/BinaryExpression/LogicalExpression/LogicalOrExpression.h"
#include "Expressions/BinaryExpression/ComparisonExpressions/GreaterExpression.h"
#include "Expressions/BinaryExpression/ComparisonExpressions/LessExpression.h"
#include "Expressions/BinaryExpression/EqualExpression.h"
#include "Expressions/UnaryExpression/NotExpression.h"
#include "Expressions/ConstantExpression/TrueExpression.h"
#include "Expressions/ConstantExpression/FalseExpression.h"
#include "Expressions/ThisExpression.h"
#include "Expressions/BinaryExpression/ArithmeticExpressions/SubExpression.h"
#include "Expressions/ConstantExpression/NumExpression.h"
#include "Expressions/FieldInvokeExpression.h"
#include "Expressions/LengthExpression.h"
#include "Statements/Assert.h"
#include "Statements/IfElse.h"
#include "Statements/MainClass.h"
#include "Statements/Statement.h"
#include "Statements/VarAssignment.h"
#include "Statements/VarDeclaration.h"
#include "Statements/MethodDeclaration.h"
#include "Statements/While.h"
#include "Statements/StatementList.h"
#include "Statements/Program.h"
#include "Statements/ClassDeclaration.h"
#include "Statements/ClassDeclarationList.h"
#include "Statements/DeclarationList.h"
#include "Statements/Formal.h"
#include "Statements/FormalsList.h"
#include "Statements/Print.h"
#include "Statements/Return.h"
#include "Statements/MethodInvocation.h"
#include "Statements/ExpressionList.h"
#include "Statements/ScopeBlock.h"

#endif //DEVANCOMPILER_ELEMENTS_H
