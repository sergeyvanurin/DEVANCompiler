//
// Created by Sergey Vanurin on 27.03.2021.
//

#include "InterpreterVisitor.h"
#include "Elements.h"


void InterpreterVisitor::Visit(VarDeclaration *statement) {
    variables[statement->var_name] = 0;
}

void InterpreterVisitor::Visit(Program *program) {
    program->main_class->Accept(this);

}

void InterpreterVisitor::Visit(MainClass *main_class) {
    main_class->statements->Accept(this);
}

void InterpreterVisitor::Visit(StatementList *statements) {
    for (auto & statement : statements->statements){
        statement->Accept(this);
    }
}

void InterpreterVisitor::Visit(VarAssignment *statement) {
    statement->new_value->Accept(this);
    int new_value = local_results.top();
    local_results.pop();
    variables[std::get<std::string>(statement->var_name->eval())] = new_value;
}

void InterpreterVisitor::Visit(AddExpression *expression) {
    expression->expr2->Accept(this);
    expression->expr1->Accept(this);
    int first = local_results.top();
    local_results.pop();
    int second = local_results.top();
    local_results.pop();
    local_results.push(first + second);

}

void InterpreterVisitor::Visit(IdentExpression *statement) {
    int value = variables[std::get<std::string>(statement->eval())];
    local_results.push(value);
}

void InterpreterVisitor::Visit(DivExpression *expression) {
    expression->expr2->Accept(this);
    expression->expr1->Accept(this);
    int first = local_results.top();
    local_results.pop();
    int second = local_results.top();
    local_results.pop();
    local_results.push(first / second);
}

void InterpreterVisitor::Visit(ModExpression *expression) {
    expression->expr2->Accept(this);
    expression->expr1->Accept(this);
    int first = local_results.top();
    local_results.pop();
    int second = local_results.top();
    local_results.pop();
    local_results.push(first % second);

}

void InterpreterVisitor::Visit(MulExpression *expression) {
    expression->expr2->Accept(this);
    expression->expr1->Accept(this);
    int first = local_results.top();
    local_results.pop();
    int second = local_results.top();
    local_results.pop();
    local_results.push(first * second);

}

void InterpreterVisitor::Visit(NumExpression *statement) {
    local_results.push(std::get<int>(statement->eval()));

}

void InterpreterVisitor::Visit(SubExpression *expression) {
    expression->expr2->Accept(this);
    expression->expr1->Accept(this);
    int first = local_results.top();
    local_results.pop();
    int second = local_results.top();
    local_results.pop();
    local_results.push(first - second);

}

void InterpreterVisitor::Visit(While *statement) {
    statement->expr->Accept(this);
    int statement_value = local_results.top();
    local_results.pop();
    while (statement_value){
        statement->statement->Accept(this);
        statement->expr->Accept(this);
        statement_value = local_results.top();
        local_results.pop();
    }
}

void InterpreterVisitor::Visit(DeclarationList *statement) {

}

void InterpreterVisitor::Visit(MethodDeclaration *statement) {

}

void InterpreterVisitor::Visit(ClassDeclarationList *class_declaration_list) {

}

void InterpreterVisitor::Visit(FalseExpression *expression) {
    local_results.push(0);
}

void InterpreterVisitor::Visit(TrueExpression *expression) {
    local_results.push(1);
}

void InterpreterVisitor::Visit(NotExpression *expression) {
    expression->expr->Accept(this);
    int expr = local_results.top();
    local_results.pop();
    local_results.push(!expr);
}

void InterpreterVisitor::Visit(EqualExpression *expression) {
    expression->expr1->Accept(this);
    expression->expr2->Accept(this);
    int second = local_results.top();
    local_results.pop();
    int first = local_results.top();
    local_results.pop();
    local_results.push(first == second);
}

void InterpreterVisitor::Visit(LessExpression *expression) {
    expression->expr1->Accept(this);
    expression->expr2->Accept(this);
    int second = local_results.top();
    local_results.pop();
    int first = local_results.top();
    local_results.pop();
    local_results.push(first < second);
}

void InterpreterVisitor::Visit(GreaterExpression *expression) {
    expression->expr1->Accept(this);
    expression->expr2->Accept(this);
    int second = local_results.top();
    local_results.pop();
    int first = local_results.top();
    local_results.pop();
    local_results.push(first > second);
}

void InterpreterVisitor::Visit(LogicalOrExpression *expression) {
    expression->expr1->Accept(this);
    expression->expr2->Accept(this);
    int second = local_results.top();
    local_results.pop();
    int first = local_results.top();
    local_results.pop();
    local_results.push(first || second);
}

void InterpreterVisitor::Visit(LogicalAndExpression *expression) {
    expression->expr1->Accept(this);
    expression->expr2->Accept(this);
    int second = local_results.top();
    local_results.pop();
    int first = local_results.top();
    local_results.pop();
    local_results.push(first && second);
}

void InterpreterVisitor::Visit(IndexExpression *expression) {

}

void InterpreterVisitor::Visit(IfElse *statement) {
    statement->expr->Accept(this);
    int expr = local_results.top();
    local_results.pop();
    if (expr){
        statement->If->Accept(this);
    }
    else{
        if (statement->Else != nullptr){
            statement->Else->Accept(this);
        }
    }

}

void InterpreterVisitor::Visit(Assert *statement) {

}

void InterpreterVisitor::Visit(ClassDeclaration *class_declaration) {

}

void InterpreterVisitor::Visit(Print *statement) {
    statement->expr->Accept(this);
    int value = local_results.top();
    local_results.pop();
    std::cout << value << '\n';

}

void InterpreterVisitor::Visit(MethodInvocation *statement) {
    local_results.push(0);
}

void InterpreterVisitor::Visit(ExpressionList *statement) {

}

void InterpreterVisitor::Visit(Return *statement) {

}

void InterpreterVisitor::Visit(FormalsList *formals_list) {

}

void InterpreterVisitor::Visit(Formal *formal) {

}

void InterpreterVisitor::Visit(LengthExpression *expression) {

}

void InterpreterVisitor::Visit(FieldInvokeExpression *expression) {

}

void InterpreterVisitor::Visit(ThisExpression *expression) {

}

void InterpreterVisitor::Visit(ScopeBlock *statement) {

}

void InterpreterVisitor::Visit(AllocExpression *expression) {
    local_results.push(0);
}





