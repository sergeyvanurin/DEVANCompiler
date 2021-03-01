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
    class Scanner;
    class Driver;
}


%code {

    #include "driver.hpp"

    static yy::parser::symbol_type yylex(Scanner &scanner) {
        return scanner.ScanToken();
    }
}

%lex-param { Scanner& scanner }
%parse-param { Scanner& scanner }
%parse-param { Driver &driver }

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
    THIS "this"
    LENGTH "length"
    NEW "new"
    TRUE "true"
    FALSE "false"
    BOYLERPLATE "public static void main"
;

%token <std::string> IDENTIFIER "id"
%token <int> NUMBER "num"
%nterm <int> expr
%nterm main_class
%nterm class_declaration
%nterm statement


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
    main_class class_declarations {};

class_declarations:
    %empty {}
    | class_declarations class_declaration {};

main_class:
    "class" "id" "{" "public static void main" "(" ")" "{" statements "}" "}" { std::cout << "main\n"; };

statements:
    %empty {} | statements statement {};

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
    type "id" ";" {
        driver.variables[$2] = 0;
    };

formals:
    type "id" {} | formals "," type "id" {};

type:
    simple_type {} | array_type {};

simple_type:
    "int" {} | "boolean" {} | "void" {} | type_identifier {};

array_type:
    simple_type "[" "]" {};

type_identifier:
    "id" {};

statement:
    "assert" "(" expr ")" { std::cout << "assert " << $3; }
  | local_variable_declaration {}
  | "{" statement "}" {}
  | "if" "(" expr ")" statement {}     %prec "then"
  | "if" "(" expr ")" statement "else" statement { if ($3) { std::cout << "true"; } else { std::cout << "false";} }
  | "while" "(" expr ")" statement {}
  | "System.out.println" "(" expr ")" ";" { std::cout << "print " << $3; }
  | lvalue "=" expr ";" {

    }
  | "return" expr ";" {}
  | method_invocation ";" {};

local_variable_declaration:
    variable_declaration {};

method_invocation:
    expr "." "id" "(" ")" {}
  | expr "." "id" "(" exprs ")" {};

exprs:
    expr {} | exprs "," expr {};

field_invocation:
    "this" "." "id" {} | "this" "." "id" "[" expr "]" {};

lvalue:
    "id" {} | "id" "[" expr "]" {} | field_invocation {};


expr:
    expr "&&" expr {}
  | expr "||" expr {}
  | expr "<" expr {}
  | expr ">" expr {}
  | expr "==" expr {}
  | expr "+" expr {}
  | expr "-" expr {}
  | expr "*" expr {}
  | expr "/" expr {}
  | expr "%" expr {}
  | expr "[" expr "]" {}
  | expr "." "length" {}
  | "new" simple_type "[" expr "]" {}
  | "new" type_identifier "(" ")" {}
  | "!" expr {}
  | "(" expr ")" {}
  | "id" {
        $$ = driver.variables[$1];
    }
  | "num" {
        $$ = $1;
    }
  | "this" {} | "true" {} | "false" {}
  | method_invocation {} | field_invocation {};


%%

void yy::parser::error(const std::string& m)
{
    std::cout << m << "\n";
}
