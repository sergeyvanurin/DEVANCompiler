//
// Created by Sergey Vanurin on 04.03.2021.
//

#include "PrintVisitor.h"

#include "Elements.h"

void PrintVisitor::Visit(ClassDeclaration *class_declaration) {

}

void PrintVisitor::Visit(AddExpression *expression) {

}

void PrintVisitor::Visit(Assert *statement) {

}

void PrintVisitor::Visit(DivExpression *expression) {

}

void PrintVisitor::Visit(IdentExpression *statement) {

}

void PrintVisitor::Visit(IfElse *statement) {

}

void PrintVisitor::Visit(MainClass *main_class) {
    main_class->statements->Accept(this);

}

void PrintVisitor::Visit(ModExpression *expression) {

}

void PrintVisitor::Visit(MulExpression *expression) {

}

void PrintVisitor::Visit(NumExpression *statement) {

}

void PrintVisitor::Visit(Program *program) {
    program->main_class->Accept(this);


}

void PrintVisitor::Visit(Scope *scope) {

}

void PrintVisitor::Visit(Statements *scope) {

}

void PrintVisitor::Visit(SubExpression *expression) {

}

void PrintVisitor::Visit(VarAssignment *statement) {

}

void PrintVisitor::Visit(VarDeclaration *statement) {

}

void PrintVisitor::Visit(While *statement) {

}
