%skeleton "lalr1.cc"
%require "3.7"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert
%define parse.trace
%define parse.error verbose

%code requires {
    #include <string>
    #include <iostream>
    #include "Expressions/Expression.h"
    #include "Expressions/IdentExpression.h"
    #include "Expressions/AddExpression.h"
    #include "Expressions/MulExpression.h"
    #include "Expressions/DivExpression.h"
    #include "Expressions/ModExpression.h"
    #include "Expressions/IndexExpression.h"
    #include "Expressions/LogicalAndExpression.h"
    #include "Expressions/LogicalOrExpression.h"
    #include "Expressions/GreaterExpression.h"
    #include "Expressions/LessExpression.h"
    #include "Expressions/EqualExpression.h"
    #include "Expressions/NotExpression.h"
    #include "Expressions/TrueExpression.h"
    #include "Expressions/FalseExpression.h"
    #include "Expressions/SubExpression.h"
    #include "Expressions/NumExpression.h"
    #include "Statements/Assert.h"
    #include "Statements/IfElse.h"
    #include "Statements/MainClass.h"
    #include "Statements/Statement.h"
    #include "Statements/VarAssignment.h"
    #include "Statements/VarDeclaration.h"
    #include "Statements/While.h"
    #include "Statements/Scope.h"
    #include "Statements/StatementList.h"
    #include "Statements/Program.h"
    #include "Statements/ClassDeclaration.h"
    #include "Statements/ClassDeclarationList.h"
    class Scanner;
    class Driver;
}


%code {
    #include "location.hh"
    #include "driver.hpp"

    static yy::parser::symbol_type yylex(Scanner &scanner) {
        return scanner.ScanToken();
    }
}

%lex-param { Scanner& scanner }
%parse-param { Scanner& scanner }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
    END 0 "end of file"
    ASSIGN ":="
    PLUS "+"
    STAR "*"
    SLASH "/"
    MINUS "-"
    PERCENT "%"
    BOOLEQUALS "=="
    MORE ">"
    LESS "<"
    BITWISEOR "||"
    BITWISEAND "&&"
    LEFTFBRACKET "{"
    RIGHTFBRACKET "}"
    LBRACKET "("
    RBRACKET ")"
    COMMA ","
    SEMICOLON ";"
    LEFTSBRACKET "["
    RIGHTSBRACKET "]"
    EQUALS "="
    DOT "."
    BANG "!"
    CLASS "class"
    EXTENDS "extends"
    PUBLIC "public"
    INT "int"
    BOOLEAN "boolean"
    VOID "void"
    ASSERT "assert"
    IF "if"
    WHILE "while"
    ELSE "else"
    PRINT "System.out.println"
    RETURN "return"
    THISINV "this."
    THIS "this"
    LENGTH "length"
    NEW "new"
    TRUE "true"
    FALSE "false"
    BOYLERPLATE "public static void main"
    EMPTYBRACKETS "[]"
;

%token <std::string> IDENTIFIER "id"
%token <int> NUMBER "num"

%nterm <Expression*> expr
%nterm class_declaration
%nterm <Statement*> statement
%nterm <StatementList*> statements
%nterm <Program*> program
%nterm <MainClass*> main_class;
%nterm <Statement*> variable_declaration;
%nterm <Statement*> local_variable_declaration;


%%

%left ";";
%left "=";
%left "||";
%left "&&";
%left "==";
%left ">" "<";
%left "+" "-";
%left "*" "/" "%";
%left "(";
%left "[";

%left ".";

%left "!";


%nonassoc "then";
%nonassoc "else";

%start program;

program:
    main_class class_declarations {$$ = new Program($1, nullptr, driver.loc); driver.program = $$;};

class_declarations:
    %empty {}
    | class_declarations class_declaration {};

main_class:
    "class" "id" "{" "public static void main" "(" ")" "{" statements "}" "}" {$$ = new MainClass($8, nullptr, driver.loc);};

statements:
    %empty {driver.add_scope(); $$ = new StatementList(driver.get_scope(), driver.loc);} | statements statement {$1->statements.push_back($2); $$ = $1;};

class_declaration:
    "class" "id" "extends" "id" "{" declarations "}" {}
  | "class" "id" "{" declarations "}" {};

declarations:
    %empty {} | declarations declaration {};

declaration:
    variable_declaration {} | method_declaration {};

method_declaration:
    "public" type "id" "(" formals ")" "{" statements "}" {}
  | "public" type "id" "(" ")" "{" statements "}" {};

variable_declaration:
    type "id" ";" {$$ = new VarDeclaration($2, driver.get_scope(), driver.loc);};

formals:
    type "id" {} | formals "," type "id" {};

type:
    simple_type {} | array_type {};

simple_type:
    "int" {} | "boolean" {} | "void" {} | type_identifier {};

array_type:
    simple_type "[]" {};

type_identifier:
    "id" {};

statement:
    "assert" "(" expr ")" {$$ = new Assert($3, driver.get_scope(), driver.loc);}
  | local_variable_declaration {$$ = $1;}
  | "{" statements "}" {$$ = $2; driver.remove_scope();}
  | "if" "(" expr ")" statement {$$ = new IfElse($3, $5, nullptr, driver.get_scope(), driver.loc);}     %prec "then"
  | "if" "(" expr ")" statement "else" statement {$$ = new IfElse($3, $5, $7, driver.get_scope(), driver.loc);}
  | "while" "(" expr ")" statement {$$ = new While($3, $5, driver.get_scope(), driver.loc);}
  | "System.out.println" "(" expr ")" ";" {}
  | expr "=" expr ";" {$$ = new VarAssignment($1, $3, driver.get_scope(), driver.loc);}
  | "return" expr ";" {}
  | method_invocation ";" {};

local_variable_declaration:
    variable_declaration {$$ = $1;};

method_invocation:
    "this." "id" "(" ")" {}
  | "this." "id" "(" exprs ")" {};
  | expr "." "id" "(" ")" {}
  | expr "." "id" "(" exprs ")" {};


exprs:
    expr {} | exprs "," expr {};

field_invocation:
    "this." "id" {};

expr:
    expr "&&" expr {$$ = new LogicalAndExpression($1, $3, driver.loc);}
  | expr "||" expr {$$ = new LogicalOrExpression($1, $3, driver.loc);}
  | expr "<" expr {$$ = new LessExpression($1, $3, driver.loc);}
  | expr ">" expr {$$ = new GreaterExpression($1, $3, driver.loc);}
  | expr "==" expr {$$ = new EqualExpression($1, $3, driver.loc);}
  | expr "+" expr {$$ = new AddExpression($1, $3, driver.loc);}
  | expr "-" expr {$$ = new SubExpression($1, $3, driver.loc);}
  | expr "*" expr {$$ = new MulExpression($1, $3, driver.loc);}
  | expr "/" expr {$$ = new DivExpression($1, $3, driver.loc);}
  | expr "%" expr {$$ = new ModExpression($1, $3, driver.loc);}
  | expr "[" expr "]" {$$ = new IndexExpression($1, $3, driver.loc);}
  | expr "." "length" {}
  | "new" simple_type "[" expr "]" {}
  | "new" type_identifier "(" ")" {}
  | "!" expr {$$ = new NotExpression($2, driver.loc);}
  | "(" expr ")" {$$ = $2;}
  | "id" {$$ = new IdentExpression($1, driver.loc);}
  | "num" {$$ = new NumExpression($1, driver.loc);}
  | "this" {}
  | "true" {$$ = new TrueExpression(driver.loc);}
  | "false" {$$ = new FalseExpression(driver.loc);}
  | method_invocation {} | field_invocation {};


%%

void yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}