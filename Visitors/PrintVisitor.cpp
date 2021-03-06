//
// Created by Sergey Vanurin on 04.03.2021.
//

#include "PrintVisitor.h"

#include "Elements.h"

void PrintVisitor::Visit(ClassDeclaration *class_declaration) {

}

void PrintVisitor::Visit(AddExpression *expression) {
    PrintTabs();
    stream << "Add expression: " << std::endl;
    num_tabs_++;
    expression->expr1->Accept(this);
    expression->expr2->Accept(this);
    num_tabs_--;
}

void PrintVisitor::Visit(Assert *statement) {
    PrintTabs();
    stream << "Assert: ";
    num_tabs_++;
    statement->expr->Accept(this);
    stream << std::endl;
    num_tabs_--;
}

void PrintVisitor::Visit(DivExpression *expression) {
    PrintTabs();
    stream << "Div expression: " << std::endl;
    num_tabs_++;
    expression->expr1->Accept(this);
    expression->expr2->Accept(this);
    stream << std::endl;
    num_tabs_--;

}

void PrintVisitor::Visit(IdentExpression *statement) {
    PrintTabs();
    stream << statement->var_name << std::endl;

}

void PrintVisitor::Visit(IfElse *statement) {
    PrintTabs();
    stream << "If expression: " << std::endl;

    num_tabs_++;
    statement->expr->Accept(this);
    num_tabs_--;

    PrintTabs();
    stream << "If statements:" << std::endl;

    num_tabs_++;
    statement->If->Accept(this);
    num_tabs_--;

    PrintTabs();
    stream << "Else statements:" << std::endl;

    if (statement->Else != nullptr) {
        num_tabs_++;
        statement->Else->Accept(this);
        stream << std::endl;
    }
    num_tabs_--;
}

void PrintVisitor::Visit(MainClass *main_class) {
    main_class->statements->Accept(this);

}

void PrintVisitor::Visit(ModExpression *expression) {
    PrintTabs();
    stream << "Mod expression: " << std::endl;
    num_tabs_++;
    expression->expr1->Accept(this);
    expression->expr2->Accept(this);
    stream << std::endl;
    num_tabs_--;
}

void PrintVisitor::Visit(MulExpression *expression) {
    PrintTabs();
    stream << "Mull expression: " << std::endl;
    num_tabs_++;
    expression->expr1->Accept(this);
    expression->expr2->Accept(this);
    stream << std::endl;
    num_tabs_--;
}

void PrintVisitor::Visit(NumExpression *statement) {
    PrintTabs();
    stream << std::get<int>(statement->eval()) << std::endl;

}

void PrintVisitor::Visit(Program *program) {
    program->main_class->Accept(this);
}

void PrintVisitor::Visit(StatementList *statements) {
    for (auto &statement : statements->statements) {
        statement->Accept(this);
    }
}


void PrintVisitor::Visit(SubExpression *expression) {
    PrintTabs();
    num_tabs_++;
    stream << "Sub expression:" << std::endl;
    expression->expr1->Accept(this);
    expression->expr2->Accept(this);
    stream << std::endl;
    num_tabs_--;
}

void PrintVisitor::Visit(VarAssignment *statement) {
    PrintTabs();
    stream << "var assignment: " << std::get<std::string>(statement->var_name->eval()) << std::endl;
    PrintTabs();
    stream << "new Value: " << std::endl;
    num_tabs_++;
    statement->new_value->Accept(this);
    num_tabs_--;

}

void PrintVisitor::Visit(LocalVarDeclaration *statement) {
    PrintTabs();
    stream << "local var declaration: '" << statement->var_name << "' of type '" << statement->type.ToString() << "'"
           << std::endl;
}

void PrintVisitor::Visit(While *statement) {
    PrintTabs();
    stream << "while loop:" << std::endl << "expr tree: " << std::endl;
    num_tabs_++;
    statement->expr->Accept(this);
    num_tabs_--;
    PrintTabs();
    stream << "statement tree: " << std::endl;
    num_tabs_++;
    statement->statement->Accept(this);
    num_tabs_--;
    stream << std::endl;
}

void PrintVisitor::Visit(IndexExpression *expression) {
    PrintTabs();
    stream << "indexing: ";
    expression->outer->Accept(this);
    stream << std::endl << "by: ";
    num_tabs_++;
    expression->inner->Accept(this);
    num_tabs_--;

}

void PrintVisitor::Visit(LogicalAndExpression *expression) {
    PrintTabs();
    stream << "AND expression: " << std::endl;
    num_tabs_++;
    expression->expr1->Accept(this);
    expression->expr2->Accept(this);
    num_tabs_--;
}

void PrintVisitor::Visit(LogicalOrExpression *expression) {
    PrintTabs();
    stream << "OR expression: " << std::endl;
    num_tabs_++;
    expression->expr1->Accept(this);
    expression->expr2->Accept(this);
    num_tabs_--;
}

void PrintVisitor::Visit(GreaterExpression *expression) {
    PrintTabs();
    stream << "GREATER expression: " << std::endl;
    num_tabs_++;
    expression->expr1->Accept(this);
    expression->expr2->Accept(this);
    num_tabs_--;
}

void PrintVisitor::Visit(LessExpression *expression) {
    PrintTabs();
    stream << "LESS expression: " << std::endl;
    num_tabs_++;
    expression->expr1->Accept(this);
    expression->expr2->Accept(this);
    num_tabs_--;
}

void PrintVisitor::Visit(EqualExpression *expression) {
    PrintTabs();
    stream << "EQUAL expression: " << std::endl;
    num_tabs_++;
    expression->expr1->Accept(this);
    expression->expr2->Accept(this);
    num_tabs_--;
}

void PrintVisitor::Visit(NotExpression *expression) {
    PrintTabs();
    stream << "NOT expression: " << std::endl;
    num_tabs_++;
    expression->expr->Accept(this);
    num_tabs_--;
}

void PrintVisitor::Visit(TrueExpression *expression) {
    PrintTabs();
    stream << "TRUE ";
}

void PrintVisitor::Visit(FalseExpression *expression) {
    PrintTabs();
    stream << "FALSE ";
}

void PrintVisitor::Visit(ClassDeclarationList *class_declaration_list) {

}

void PrintVisitor::Visit(MethodDeclaration *statement) {

}

void PrintVisitor::Visit(DeclarationList *statement) {

}

void PrintVisitor::Visit(FormalsList *formals_list) {

}

void PrintVisitor::Visit(Formal *formal) {

}

void PrintVisitor::PrintTabs() {
    for (int i = 0; i < num_tabs_; i++) {
        stream << '\t';
    }
}


void PrintVisitor::Visit(Print *statement) {
    PrintTabs();
    stream << "PRINT: " << std::endl;
    num_tabs_++;
    statement->expr->Accept(this);
    num_tabs_--;
}

void PrintVisitor::Visit(Return *statement) {

}

void PrintVisitor::Visit(FieldInvokeExpression *expression) {

}

void PrintVisitor::Visit(ExpressionList *statement) {

}

void PrintVisitor::Visit(MethodInvocation *statement) {

}

void PrintVisitor::Visit(LengthExpression *expression) {

}

void PrintVisitor::Visit(ThisExpression *expression) {

}

PrintVisitor::PrintVisitor(const std::string &filename) : stream(filename) {}

void PrintVisitor::Visit(ScopeBlock *statement) {

}

void PrintVisitor::Visit(AllocExpression *expression) {

}

void PrintVisitor::Visit(FieldDeclaration *statement) {
    stream << "field declaration: '" << statement->var_name << "' of type '" << statement->type.ToString() << "'"
           << std::endl;
}
