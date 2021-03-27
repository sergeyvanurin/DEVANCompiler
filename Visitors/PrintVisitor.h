//
// Created by Sergey Vanurin on 04.03.2021.
//


#include "Visitor.h"
#include <fstream>
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
    void Visit(IndexExpression* expression) override;
    void Visit(LogicalAndExpression* expression) override;
    void Visit(LogicalOrExpression* expression) override;
    void Visit(GreaterExpression* expression) override;
    void Visit(LessExpression* expression) override;
    void Visit(EqualExpression* expression) override;
    void Visit(NotExpression* expression) override;
    void Visit(TrueExpression* expression) override;
    void Visit(FalseExpression* expression) override;
    void Visit(ClassDeclarationList* class_declaration_list) override;
    void Visit(MethodDeclaration* statement) override;
    void Visit(Declarations* statement) override;


public:
    PrintVisitor(const std::string& filename);

private:
    void PrintTabs();
    std::ofstream stream;
    int num_tabs_ = 0;

};


#endif //DEVANCOMPILER_PRINTVISITOR_H
