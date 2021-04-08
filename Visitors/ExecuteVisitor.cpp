//
// Created by  on 08.04.2021.
//

#include "ExecuteVisitor.h"
#include "Elements.h"

void ExecuteVisitor::Visit(Program *program) {
    program->main_class->Accept(this);
}

void ExecuteVisitor::Visit(MainClass *main_class) {
    frame_pointer.push(0);
    main_class->statements->Accept(this);
}

void ExecuteVisitor::Visit(StatementList *statements) {
    for (auto statement: statements->statements) {
        statement->Accept(this);
        if (returning_)
            break;
    }
}

void ExecuteVisitor::Visit(ClassDeclaration *class_declaration) {
    throw std::runtime_error("ExecuteVisitor is forbidden to be here");
}

void ExecuteVisitor::Visit(ClassDeclarationList *class_declaration_list) {
    throw std::runtime_error("ExecuteVisitor is forbidden to be here");
}

void ExecuteVisitor::Visit(DeclarationList *statement) {
    throw std::runtime_error("ExecuteVisitor is forbidden to be here");
}

void ExecuteVisitor::Visit(MethodDeclaration *statement) {
    throw std::runtime_error("ExecuteVisitor is forbidden to be here");
}

void ExecuteVisitor::Visit(FieldDeclaration *statement) {
    throw std::runtime_error("ExecuteVisitor is forbidden to be here");
}

void ExecuteVisitor::Visit(Formal *formal) {
    throw std::runtime_error("ExecuteVisitor is forbidden to be here");
}

void ExecuteVisitor::Visit(Assert *statement) {
    statement->expr->Accept(this);
    if (!rax_->GetBool()) {
        std::cerr << statement->loc << std::endl;
        throw std::runtime_error("Assert failed");
    }
}

void ExecuteVisitor::Visit(IfElse *statement) {
    statement->expr->Accept(this);
    if (rax_->GetBool()) {
        statement->If->Accept(this);
    } else {
        statement->Else->Accept(this);
    }
}

void ExecuteVisitor::Visit(While *statement) {
    statement->expr->Accept(this);
    while (rax_->GetBool()) {
        statement->statement->Accept(this);
        statement->expr->Accept(this);
    }
}

void ExecuteVisitor::Visit(VarAssignment *statement) {
    statement->new_value->Accept(this);
    auto new_value = rax_;
    statement->var_name->Accept(this);
    *rax_ = *new_value;
}

void ExecuteVisitor::Visit(FormalsList *formals_list) {
    for (auto formal: formals_list->formals) {
        formal->Accept(this);
    }
}

void ExecuteVisitor::Visit(Print *statement) {
    if (statement->expr->GetType() == Type("int")) {
        statement->expr->Accept(this);
        std::cout << rax_->GetInt() << "\n";
    }
    if (statement->expr->GetType() == Type("bool")) {
        statement->expr->Accept(this);
        std::cout << (rax_->GetBool() ? "True" : "False") << "\n";
    }
}

void ExecuteVisitor::Visit(ExpressionList *statement) {
    for (auto expr: statement->expressions) {
        expr->Accept(this);
    }
}

void ExecuteVisitor::Visit(ScopeBlock *statement) {
    statement->statements->Accept(this);
}

void ExecuteVisitor::Visit(NumExpression *expression) {
    rax_ = std::make_shared<PhysicalVariable>(expression->GetValue());
}

std::pair< int, int > GetPairOfInts(BinaryExpression *expression, ExecuteVisitor* visitor){
    std::pair< int, int > ans;
    expression->expr1->Accept(visitor);
    ans.first = visitor->GetRes()->GetInt();
    expression->expr2->Accept(visitor);
    ans.second = visitor->GetRes()->GetInt();
    return ans;
}

void ExecuteVisitor::Visit(AddExpression *expression) {
    auto val = GetPairOfInts(expression, this);
    rax_ = std::make_shared<PhysicalVariable>(val.first + val.second);
}

void ExecuteVisitor::Visit(SubExpression *expression) {
    auto val = GetPairOfInts(expression, this);
    rax_ = std::make_shared<PhysicalVariable>(val.first - val.second);
}

void ExecuteVisitor::Visit(MulExpression *expression) {
    auto val = GetPairOfInts(expression, this);
    rax_ = std::make_shared<PhysicalVariable>(val.first * val.second);
}

void ExecuteVisitor::Visit(DivExpression *expression) {
    auto val = GetPairOfInts(expression, this);
    if (val.second == 0){
        std::cerr << expression->loc << std::endl;
        throw std::logic_error("division by zero");
    }
    rax_ = std::make_shared<PhysicalVariable>(val.first / val.second);
}

void ExecuteVisitor::Visit(ModExpression *expression) {
    auto val = GetPairOfInts(expression, this);
    if (val.second == 0){
        std::cerr << expression->loc << std::endl;
        throw std::logic_error("division by zero");
    }
    rax_ = std::make_shared<PhysicalVariable>(val.first % val.second);
}

void ExecuteVisitor::Visit(IndexExpression *expression) {
    expression->outer->Accept(this);
    auto array = rax_;
    expression->inner->Accept(this);
    rax_ = array->GetOnIndex(rax_->GetInt());
}

std::pair< bool, bool > GetPairOfBools(BinaryExpression *expression, ExecuteVisitor* visitor){
    std::pair< bool, bool > ans;
    expression->expr1->Accept(visitor);
    ans.first = visitor->GetRes()->GetBool();
    expression->expr2->Accept(visitor);
    ans.second = visitor->GetRes()->GetBool();
    return ans;
}

void ExecuteVisitor::Visit(LogicalAndExpression *expression) {
    auto val = GetPairOfBools(expression, this);
    rax_ = std::make_shared<PhysicalVariable>(val.first && val.second);
}

void ExecuteVisitor::Visit(LogicalOrExpression *expression) {
    auto val = GetPairOfBools(expression, this);
    rax_ = std::make_shared<PhysicalVariable>(val.first || val.second);
}

void ExecuteVisitor::Visit(GreaterExpression *expression) {
    auto val = GetPairOfInts(expression, this);
    rax_ = std::make_shared<PhysicalVariable>(val.first > val.second);
}

void ExecuteVisitor::Visit(LessExpression *expression) {
    auto val = GetPairOfInts(expression, this);
    rax_ = std::make_shared<PhysicalVariable>(val.first < val.second);
}

void ExecuteVisitor::Visit(NotExpression *expression) {
    expression->expr->Accept(this);
    rax_ = std::make_shared<PhysicalVariable>(!rax_->GetBool());
}

void ExecuteVisitor::Visit(TrueExpression *expression) {
    rax_ = std::make_shared<PhysicalVariable>(true);
}

void ExecuteVisitor::Visit(FalseExpression *expression) {
    rax_ = std::make_shared<PhysicalVariable>(false);
}

void ExecuteVisitor::Visit(ThisExpression *expression) {
    rax_ = stack_[frame_pointer.top() - 1];
}

void ExecuteVisitor::Visit(LengthExpression *expression) {
    expression->array_expr->Accept(this);
    rax_ = std::make_shared<PhysicalVariable>(rax_->GetLength());
}

void ExecuteVisitor::Visit(FieldInvokeExpression *expression) {
    rax_ = stack_[frame_pointer.top() - 1]->GetField(expression->field_name);
}

void ExecuteVisitor::Visit(AllocExpression *expression) {
    if (expression->size_expr) {
        expression->size_expr->Accept(this);
        int size = rax_->GetInt();
        rax_ = std::make_shared<PhysicalVariable>(expression->type, size);
    } else {
        rax_ = std::make_shared<PhysicalVariable>(expression->type);
    }
}

PhysicalVariable::PtrType ExecuteVisitor::GetRes() const {
    return rax_;
}

void ExecuteVisitor::Visit(EqualExpression *expression) {
    auto type = expression->expr1->GetType();
    if (type == Type("int")){
        auto val = GetPairOfInts(expression, this);
        rax_ = std::make_shared<PhysicalVariable>(val.first == val.second);
    } else if (type == Type("bool")){
        auto val = GetPairOfBools(expression, this);
        rax_ = std::make_shared<PhysicalVariable>(val.first == val.second);
    } else {
        expression->expr1->Accept(this);
        auto first = rax_;
        rax_ = std::make_shared<PhysicalVariable>(first == rax_);
    }
}

void ExecuteVisitor::Visit(Return *statement) {
    statement->expr->Accept(this);
    returning_ = true;
}

void ExecuteVisitor::Visit(MethodInvocation *statement) {
    for (auto expr: statement->arguments->expressions) {
        expr->Accept(this);
        stack_.push_back(rax_);
    }
    statement->class_expr->Accept(this);
    stack_.push_back(rax_);
    frame_pointer.push(stack_.size());
    auto type = statement->class_expr->GetType();
    statement->GetScope()->GetClassByName(type.type_name)->FindMethodByName(
            statement->method_name)->method_body->Accept(this);
    frame_pointer.pop();
    returning_ = false;
}

void ExecuteVisitor::Visit(LocalVarDeclaration *statement) {
    stack_.push_back(std::make_shared<PhysicalVariable>(statement->type));
}

void ExecuteVisitor::Visit(IdentExpression *expression) {
    size_t ind = frame_pointer.top() + expression->GetScope()->GetOffsetOfVariable(expression->var_name);
    rax_ = stack_[ind];
}
