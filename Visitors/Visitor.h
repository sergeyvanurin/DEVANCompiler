//
// Created by Sergey Vanurin on 01.03.2021.
//

#include "ForwardDeclaration.h"
#ifndef DEVANCOMPILER_VISITOR_H
#define DEVANCOMPILER_VISITOR_H


class Visitor {
public:
    virtual void Visit(AddExpression* expression) = 0;
    virtual void Visit(SubExpression* expression) = 0;
    virtual void Visit(MulExpression* expression) = 0;
    virtual void Visit(DivExpression* expression) = 0;
    virtual void Visit(ModExpression* expression) = 0;
    virtual void Visit(IndexExpression* expression) = 0;
    virtual void Visit(LogicalAndExpression* expression) = 0;
    virtual void Visit(LogicalOrExpression* expression) = 0;
    virtual void Visit(GreaterExpression* expression) = 0;
    virtual void Visit(LessExpression* expression) = 0;
    virtual void Visit(EqualExpression* expression) = 0;
    virtual void Visit(NotExpression* expression) = 0;
    virtual void Visit(Program* program) = 0;
    virtual void Visit(MainClass* main_class) = 0;
    virtual void Visit(ClassDeclaration* class_declaration) = 0;
    virtual void Visit(Assert* statement) = 0;
    virtual void Visit(VarDeclaration* statement) = 0;
    virtual void Visit(MethodDeclaration* statement) = 0;
    virtual void Visit(Declarations* statement) = 0;
    virtual void Visit(IfElse* statement) = 0;
    virtual void Visit(While* statement) = 0;
    virtual void Visit(VarAssignment* statement) = 0;
    virtual void Visit(IdentExpression* statement) = 0;
    virtual void Visit(NumExpression* statement) = 0;
    virtual void Visit(Scope* scope) = 0;
    virtual void Visit(Statements* statements) = 0;

};


#endif //DEVANCOMPILER_VISITOR_H
