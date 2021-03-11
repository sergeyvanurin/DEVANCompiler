//
// Created by Sergey Vanurin on 04.03.2021.
//


#include "Visitor.h"
#ifndef DEVANCOMPILER_PRINTVISITOR_H
#define DEVANCOMPILER_PRINTVISITOR_H


class PrintVisitor: public Visitor {
    void Visit(ClassDeclaration *class_declaration) override;
    void Visit(AddExpression *expression) override;
    void Visit(Assert *statement) override;
    void Visit(DivExpression *expression) override;
    void Visit(IdentExpression *statement) override;
    void Visit(IfElse *statement) override;
    void Visit(MainClass *main_class) override;
    void Visit(ModExpression *expression) override;
    void Visit(MulExpression *expression) override;
    void Visit(NumExpression *statement) override;
    void Visit(Program *program) override;
    void Visit(Scope *scope) override;
    void Visit(StatementList *statements) override;
    void Visit(SubExpression *expression) override;
    void Visit(VarAssignment *statement) override;
    void Visit(VarDeclaration *statement) override;
    void Visit(While *statement) override;
};


#endif //DEVANCOMPILER_PRINTVISITOR_H
