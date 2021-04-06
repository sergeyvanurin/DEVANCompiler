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
    /*#include "Expressions/Expression.h"
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
    #include "Expressions/ThisExpression.h"
    #include "Expressions/SubExpression.h"
    #include "Expressions/NumExpression.h"
    #include "Expressions/FieldInvokeExpression.h"
    #include "Expressions/LengthExpression.h"
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
    #include "Statements/MethodDeclaration.h"
    #include "Statements/ClassDeclarationList.h"
    #include "Statements/DeclarationList.h"
    #include "Statements/FormalsList.h"
    #include "Statements/Print.h"
    #include "Statements/Return.h"
    #include "Statements/MethodInvocation.h"
    #include "Statements/ExpressionList.h"*/
    #include "Visitors/Elements.h"
    #include "Symbols/Type.h"
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
%nterm <ClassDeclarationList*> class_declarations
%nterm <ClassDeclaration*> class_declaration
%nterm <Statement*> statement
%nterm <StatementList*> statements
%nterm <Program*> program
%nterm <MainClass*> main_class;
%nterm <VarDeclaration*> variable_declaration;
%nterm <MethodDeclaration*> method_declaration;
%nterm <VarDeclaration*> local_variable_declaration;
%nterm <DeclarationList*> declarations;
%nterm <std::variant<VarDeclaration*, MethodDeclaration*>> declaration;
%nterm <FormalsList*> formals;
%nterm <FieldInvokeExpression*> field_invocation;
%nterm <MethodInvocation*> method_invocation;
%nterm <ExpressionList*> exprs;
%nterm <Type*> type;
%nterm <Type*> simple_type;
%nterm <Type*> array_type;
%nterm <std::string> type_identifier;

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
    %empty {$$ = new ClassDeclarationList(nullptr, driver.loc);}
    | class_declarations class_declaration {$1->AddClassDeclaration($2); $$ = $1;};

main_class:
    "class" "id" "{" "public static void main" "(" ")" "{" statements "}" "}" {$$ = new MainClass($8, nullptr, driver.loc);};

statements:
    %empty {driver.add_scope(); $$ = new StatementList(driver.get_scope(), driver.loc);}
   | statements statement {$1->AddStatement($2); $$ = $1;};

class_declaration:
    "class" "id" "extends" "id" "{" declarations "}" {$$ = new ClassDeclaration($2, $4, $6, nullptr, driver.loc);}
  | "class" "id" "{" declarations "}" {$$ = new ClassDeclaration($2, "", $4, nullptr, driver.loc);};

declarations:
    %empty {$$ = new DeclarationList(nullptr, driver.loc);}
   | declarations declaration {$1->AddDeclaration($2); $$ = $1;};

declaration:
    variable_declaration {$$ = $1;} | method_declaration {$$ = $1;};

method_declaration:
    "public" type "id" "(" formals ")" "{" statements "}" {$$ = new MethodDeclaration($3, $2, $5, $8, nullptr, driver.loc);}
  | "public" type "id" "(" ")" "{" statements "}" {$$ = new MethodDeclaration($3, $2, nullptr, $7, nullptr, driver.loc);};

variable_declaration:
    type "id" ";" {$$ = new VarDeclaration($2, driver.get_scope(), driver.loc);};

formals:
    type "id" {$$ = new FormalsList(nullptr, driver.loc); $$->AddFormal(new Formal($2, nullptr, driver.loc));}
   | formals "," type "id" {$1->AddFormal(new Formal($4, nullptr, driver.loc)); $$ = $1;};

type:
    simple_type { $$ = $1; } | array_type { $$ = $1; };

simple_type:
    "int" { $$ = new Type("int"); } | "boolean" {$$ = new Type("bool");} | "void" {$$ = new Type("void");} | type_identifier {$$ = new Type($1);};

array_type:
    simple_type "[]" { $$ = $1; $$->is_array = true; };

type_identifier:
    "id" { $$ = $1; };

statement:
    "assert" "(" expr ")" {$$ = new Assert($3, driver.get_scope(), driver.loc);}
  | local_variable_declaration {$$ = $1;}
  | "{" statements "}" {$$ = $2; driver.remove_scope();}
  | "if" "(" expr ")" statement {$$ = new IfElse($3, $5, nullptr, driver.get_scope(), driver.loc);}     %prec "then"
  | "if" "(" expr ")" statement "else" statement {$$ = new IfElse($3, $5, $7, driver.get_scope(), driver.loc);}
  | "while" "(" expr ")" statement {$$ = new While($3, $5, driver.get_scope(), driver.loc);}
  | "System.out.println" "(" expr ")" ";" {$$ = new Print($3, nullptr, driver.loc);}
  | expr "=" expr ";" {$$ = new VarAssignment($1, $3, driver.get_scope(), driver.loc);}
  | "return" expr ";" {$$ = new Return($2, nullptr, driver.loc);}
  | method_invocation ";" {$$ = $1;};

local_variable_declaration:
    variable_declaration {$$ = $1;};

method_invocation:
    "this." "id" "(" ")" {$$ = new MethodInvocation(nullptr, $2, nullptr, nullptr, driver.loc);}
  | "this." "id" "(" exprs ")" {$$ = new MethodInvocation(nullptr, $2, $4, nullptr, driver.loc);};
  | expr "." "id" "(" ")" {$$ = new MethodInvocation($1, $3, nullptr, nullptr, driver.loc);}
  | expr "." "id" "(" exprs ")" {$$ = new MethodInvocation($1, $3, $5, nullptr, driver.loc);};


exprs:
    expr {$$ = new ExpressionList(nullptr, driver.loc); $$->AddExpression($1);}
  | exprs "," expr {$1->AddExpression($3); $$ = $1;};

field_invocation:
    "this." "id" {$$ = new FieldInvokeExpression($2, driver.loc);};

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
  | expr "." "length" {$$ = new LengthExpression($1, driver.loc);}
  | "new" simple_type "[" expr "]" {}
  | "new" type_identifier "(" ")" {}
  | "!" expr {$$ = new NotExpression($2, driver.loc);}
  | "(" expr ")" {$$ = $2;}
  | "id" {$$ = new IdentExpression($1, driver.loc);}
  | "num" {$$ = new NumExpression($1, driver.loc);}
  | "this" {$$ = new ThisExpression(driver.loc);}
  | "true" {$$ = new TrueExpression(driver.loc);}
  | "false" {$$ = new FalseExpression(driver.loc);}
  | method_invocation {$$ = $1;}
  | field_invocation {$$ = $1;};


%%

void yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << "\n";
}