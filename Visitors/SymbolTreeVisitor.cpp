//
// Created by deliza on 05.04.2021.
//


#include "SymbolTreeVisitor.h"
#include "Elements.h"

SymbolTreeVisitor::SymbolTreeVisitor(): tree_(new ScopeLayer) {
    current_layer_ = tree_.root_;
}

void SymbolTreeVisitor::Visit(ClassDeclaration *class_decl) {
    current_layer_->DeclareClass(STClass(class_decl));
    NewLevelDown();
    class_decl->declaration_list->Accept(this);
    LevelUp();
    // done
}

void SymbolTreeVisitor::Visit(AddExpression *expression) {
    expression->GetType(current_layer_);
}

void SymbolTreeVisitor::Visit(Assert *statement) {
    statement->expr->GetType(current_layer_);
}

void SymbolTreeVisitor::Visit(DivExpression *expression) {
    expression->GetType(current_layer_);
}

void SymbolTreeVisitor::Visit(IdentExpression *expression) {
    expression->GetType(current_layer_);
}

void SymbolTreeVisitor::Visit(IfElse *statement) {
    statement->expr->GetType(current_layer_);
    NewLevelDown();
    statement->If->Accept(this);
    LevelUp();
    NewLevelDown();
    statement->Else->Accept(this);
    LevelUp();
}

void SymbolTreeVisitor::Visit(MainClass *main_class) {
    current_layer_->EnterClass(nullptr);
    main_class->statements->Accept(this);
}

void SymbolTreeVisitor::Visit(ModExpression *expression) {
    expression->GetType(current_layer_);
}

void SymbolTreeVisitor::Visit(MulExpression *expression) {
    expression->GetType(current_layer_);
}

void SymbolTreeVisitor::Visit(NumExpression *expression) {
    expression->GetType(current_layer_);
}

void SymbolTreeVisitor::Visit(Program *program) {

    program->main_class->Accept(this);
}

void SymbolTreeVisitor::Visit(Scope *scope) {
    // deprecated
}

void SymbolTreeVisitor::Visit(StatementList *statements) {
    for (auto & statement : statements->statements ){
        statement->Accept(this);
    }
    // done
}

void SymbolTreeVisitor::Visit(SubExpression *expression) {
    expression->GetType(current_layer_);
}

void SymbolTreeVisitor::Visit(VarAssignment *statement) {
    NewLevelDown();
    statement->var_name->Accept(this);
    LevelUp();
    NewLevelDown();
    statement->new_value->Accept(this);
    LevelUp();
}

void SymbolTreeVisitor::Visit(VarDeclaration *var_decl) {
    current_layer_->DeclareVariable(STVariable(var_decl));
}

void SymbolTreeVisitor::Visit(While *statement) {
    NewLevelDown();
    statement->expr->Accept(this);
    LevelUp();
    NewLevelDown();
    statement->statement->Accept(this);
    LevelUp();
}

void SymbolTreeVisitor::Visit(IndexExpression *expression) {
    expression->GetType(current_layer_);
}

void SymbolTreeVisitor::Visit(LogicalAndExpression *expression) {
    expression->GetType(current_layer_);
}

void SymbolTreeVisitor::Visit(LogicalOrExpression *expression) {
    expression->GetType(current_layer_);
}

void SymbolTreeVisitor::Visit(GreaterExpression *expression) {
    expression->GetType(current_layer_);
}

void SymbolTreeVisitor::Visit(LessExpression *expression) {
    expression->GetType(current_layer_);
}

void SymbolTreeVisitor::Visit(EqualExpression *expression) {
    expression->GetType(current_layer_);
}

void SymbolTreeVisitor::Visit(NotExpression *expression) {
    expression->GetType(current_layer_);
}

void SymbolTreeVisitor::Visit(TrueExpression *expression) {
    expression->GetType(current_layer_);
}

void SymbolTreeVisitor::Visit(FalseExpression *expression) {
    expression->GetType(current_layer_);
}

void SymbolTreeVisitor::Visit(ThisExpression *expression) {
    expression->GetType(current_layer_);
}

void SymbolTreeVisitor::Visit(FieldInvokeExpression *expression) {
    expression->GetType(current_layer_);
}

void SymbolTreeVisitor::Visit(LengthExpression *expression) {
    expression->GetType(current_layer_);
}

void SymbolTreeVisitor::Visit(ClassDeclarationList *class_declaration_list) {
    for (auto &declaration: class_declaration_list->class_declarations){
        declaration->Accept(this);
    }
}

void SymbolTreeVisitor::Visit(MethodDeclaration *statement) {
    current_layer_->DeclareMethod(STMethod(statement));
}

void SymbolTreeVisitor::Visit(DeclarationList *statement) {
    for (auto &declare: statement->declarations){
        try {
            std::get<VarDeclaration*>(declare)->Accept(this);
        }
        catch (const std::bad_variant_access&) {
            std::get<MethodDeclaration*>(declare)->Accept(this);
        }
    }
}

void SymbolTreeVisitor::Visit(Formal *formal) {
    // TODO type deduction
}

void SymbolTreeVisitor::Visit(FormalsList *formals_list) {
    for (auto &form: formals_list->formals){
        form->Accept(this);
    }
}

void SymbolTreeVisitor::Visit(Print *statement) {
    NewLevelDown();
    statement->expr->Accept(this);
    LevelUp();
}

void SymbolTreeVisitor::Visit(Return *statement) {
    NewLevelDown();
    statement->expr->Accept(this);
    LevelUp();
}

void SymbolTreeVisitor::Visit(ExpressionList *statement) {
    for (auto &expr: statement->expressions){
        expr->Accept(this);
    }
}

void SymbolTreeVisitor::Visit(MethodInvocation *statement) {
    statement->GetType(current_layer_);

}

ScopeLayer *SymbolTreeVisitor::GetRoot() {
    return current_layer_;
}

void SymbolTreeVisitor::NewLevelDown() {
    current_layer_ = current_layer_->AddChild(new ScopeLayer(current_layer_));
}

void SymbolTreeVisitor::LevelUp() {
    current_layer_ = current_layer_->GetParent();
}
