//
// Created by deliza on 05.04.2021.
//


#include "SymbolTreeVisitor.h"
#include "Elements.h"

SymbolTreeVisitor::SymbolTreeVisitor() : tree_(new ScopeLayer) {
    current_layer_ = tree_.root_;
}

void SymbolTreeVisitor::Visit(ClassDeclaration *class_decl) {
    current_layer_->DeclareClass(STClass(class_decl));
    NewLevelDown();
    class_decl->declaration_list->Accept(this);
    LevelUp();
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
    if (statement->expr->GetType(current_layer_) != Type("bool")) {
        std::cerr << statement->expr->loc << std::endl;
        throw std::runtime_error("Only bool may be in if expression");
    }
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
    program->class_declarations->Accept(this);
    program->main_class->Accept(this);
}

void SymbolTreeVisitor::Visit(StatementList *statements) {
    for (Statement *statement : statements->statements) {
        statement->Accept(this);
    }
}

void SymbolTreeVisitor::Visit(SubExpression *expression) {
    expression->GetType(current_layer_);
}

void SymbolTreeVisitor::Visit(VarAssignment *statement) {
    if (statement->var_name->GetType(current_layer_) != statement->new_value->GetType(current_layer_)) {
        std::cerr << statement->loc << std::endl;
        throw std::runtime_error(
                "Assigment types isn't equal types '" + statement->var_name->GetType(current_layer_).ToString() +
                "' and '" + statement->new_value->GetType(current_layer_).ToString() + "'");
    }
}

void SymbolTreeVisitor::Visit(LocalVarDeclaration *var_decl) {
    try {
        current_layer_->DeclareLocalVariable(STVariable(var_decl));
    } catch (const std::runtime_error &e) {
        std::cerr << var_decl->loc << std::endl;
        throw e;
    }
    // TODO FieldDeclaration
}

void SymbolTreeVisitor::Visit(While *statement) {
    if (statement->expr->GetType(current_layer_) != Type("bool")) {
        std::cerr << statement->expr->loc << std::endl;
        throw std::runtime_error("Only bool may be in while expression");
    }
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
    for (auto &declaration: class_declaration_list->class_declarations) {
        declaration->Accept(this);
    }
}

void SymbolTreeVisitor::Visit(MethodDeclaration *statement) {
    NewLevelDown();
    current_layer_->DeclareMethod(statement->method_name);
    statement->formals->Accept(this);
    statement->statements->Accept(this);
    LevelUp();
}

void SymbolTreeVisitor::Visit(DeclarationList *statement) {
    for (auto &declare: statement->declarations) {
        if (declare.index() == 0) {
            std::get<FieldDeclaration *>(declare)->Accept(this);
        }
    }
    for (auto &declare: statement->declarations) {
        if (declare.index() == 1) {
            std::get<MethodDeclaration *>(declare)->Accept(this);
        }
    }
}

void SymbolTreeVisitor::Visit(Formal *formal) {
    current_layer_->DeclareLocalVariable(STVariable(formal->name, formal->type));
}

void SymbolTreeVisitor::Visit(FormalsList *formals_list) {
    for (auto &form: formals_list->formals) {
        form->Accept(this);
    }
}

void SymbolTreeVisitor::Visit(Print *statement) {
    if (statement->expr->GetType(current_layer_) != Type("int") &&
        statement->expr->GetType(current_layer_) != Type("bool")) {
        std::cerr << statement->loc << std::endl;
        throw std::runtime_error(
                "Can print only 'int' or 'bool'. not '" + statement->expr->GetType(current_layer_).ToString() + "'");
    }
}

void SymbolTreeVisitor::Visit(Return *statement) {
    auto method_ptr = current_layer_->GetCurrentMethod();
    if (method_ptr == nullptr) {
        std::cerr << statement->expr->loc << std::endl;
        throw std::runtime_error("'return' must be in method scope");
    }
    if (method_ptr->return_type != statement->expr->GetType(current_layer_)) {
        std::cerr << statement->expr->loc << std::endl;
        throw std::runtime_error(
                "'return' in method '" + method_ptr->GetName() + "' expect '" + method_ptr->return_type.ToString() +
                "' but got '" + statement->expr->GetType(current_layer_).ToString() + "'");
    }
}

void SymbolTreeVisitor::Visit(ExpressionList *statement) {
    for (auto &expr: statement->expressions) {
        expr->Accept(this);
    }
}

void SymbolTreeVisitor::Visit(MethodInvocation *statement) {
    statement->GetType(current_layer_);
}

void SymbolTreeVisitor::Visit(ScopeBlock *statement) {
    NewLevelDown();
    statement->statements->Accept(this);
    LevelUp();
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

void SymbolTreeVisitor::Visit(AllocExpression *expression) {
    expression->GetType(current_layer_);
}

void SymbolTreeVisitor::Visit(FieldDeclaration *statement) {
    // nothing
}
