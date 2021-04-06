//
// Created by Sergey Vanurin on 04.03.2021.
//

#ifndef DEVANCOMPILER_ELEMENTS_H
#define DEVANCOMPILER_ELEMENTS_H

#include "Expressions/Expression.h"
#include "Expressions/IdentExpression.h"
#include "Expressions/AddExpression.h"
#include "Expressions/MulExpression.h"
#include "Expressions/DivExpression.h"
#include "Expressions/ModExpression.h"
#include "Expressions/IndexExpression.h"
#include "Expressions/LogicalAndExpression.h"
#include "Expressions/LogicalOrExpression.h"
#include "Expressions/GreaterExpression.h"
#include "Expressions/LessExpression.h"
#include "Expressions/EqualExpression.h"
#include "Expressions/NotExpression.h"
#include "Expressions/TrueExpression.h"
#include "Expressions/FalseExpression.h"
#include "Expressions/ThisExpression.h"
#include "Expressions/SubExpression.h"
#include "Expressions/NumExpression.h"
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
#include "Statements/Scope.h"
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

#endif //DEVANCOMPILER_ELEMENTS_H
