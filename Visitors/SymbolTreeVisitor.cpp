//
// Created by deliza on 05.04.2021.
//


#include "SymbolTreeVisitor.h"
#include "Elements.h"

SymbolTreeVisitor::SymbolTreeVisitor(): tree_(new ScopeLayer) {
    current_layer_ = tree_.root_;
}

void SymbolTreeVisitor::Visit(ClassDeclaration *class_decl) {
    //current_layer_->DeclareClass(STClass(class_decl));
}

void SymbolTreeVisitor::Visit(AddExpression *expression) {
    expression->expr1->Accept(this);
    expression->expr2->Accept(this);
}

void SymbolTreeVisitor::Visit(Assert *statement) {
    return;
}

void SymbolTreeVisitor::Visit(DivExpression *expression) {
    return;
}

void SymbolTreeVisitor::Visit(IdentExpression *statement) {
    return;
}

void SymbolTreeVisitor::Visit(IfElse *statement) {

}

void SymbolTreeVisitor::Visit(MainClass *main_class) {
    main_class->statements->Accept(this);
}

void SymbolTreeVisitor::Visit(ModExpression *expression) {
    return;
}

void SymbolTreeVisitor::Visit(MulExpression *expression) {
    return;
}

void SymbolTreeVisitor::Visit(NumExpression *statement) {
    return;
}

void SymbolTreeVisitor::Visit(Program *program) {
    program->main_class->Accept(this);
}

void SymbolTreeVisitor::Visit(Scope *scope) {

}

void SymbolTreeVisitor::Visit(StatementList *statements) {
    for (auto & statement : statements->statements ){
        statement->Accept(this);
    }
}

void SymbolTreeVisitor::Visit(SubExpression *expression) {
    return;
}

void SymbolTreeVisitor::Visit(VarAssignment *statement) {
    return;
}

void SymbolTreeVisitor::Visit(VarDeclaration *var_decl) {
    current_layer_->DeclareVariable(STVariable(var_decl));
}

void SymbolTreeVisitor::Visit(While *statement) {
    return;
}

void SymbolTreeVisitor::Visit(IndexExpression *expression) {

}

void SymbolTreeVisitor::Visit(LogicalAndExpression *expression) {

}

void SymbolTreeVisitor::Visit(LogicalOrExpression *expression) {

}

void SymbolTreeVisitor::Visit(GreaterExpression *expression) {

}

void SymbolTreeVisitor::Visit(LessExpression *expression) {

}

void SymbolTreeVisitor::Visit(EqualExpression *expression) {

}

void SymbolTreeVisitor::Visit(NotExpression *expression) {

}

void SymbolTreeVisitor::Visit(TrueExpression *expression) {

}

void SymbolTreeVisitor::Visit(FalseExpression *expression) {

}

void SymbolTreeVisitor::Visit(ThisExpression *expression) {

}

void SymbolTreeVisitor::Visit(FieldInvocExpression *expression) {

}

void SymbolTreeVisitor::Visit(LengthExpression *expression) {

}

void SymbolTreeVisitor::Visit(ClassDeclarationList *class_declaration_list) {

}

void SymbolTreeVisitor::Visit(MethodDeclaration *statement) {

}

void SymbolTreeVisitor::Visit(DeclarationList *statement) {

}

void SymbolTreeVisitor::Visit(Formal *formal) {

}

void SymbolTreeVisitor::Visit(FormalsList *formals_list) {

}

void SymbolTreeVisitor::Visit(Print *statement) {

}

void SymbolTreeVisitor::Visit(Return *statement) {

}

void SymbolTreeVisitor::Visit(ExpressionList *statement) {

}

void SymbolTreeVisitor::Visit(MethodInvocation *statement) {

}

ScopeLayer *SymbolTreeVisitor::GetRoot() {
    return current_layer_;
}
