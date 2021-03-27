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

}

void InterpreterVisitor::Visit(AddExpression *expression) {


}





