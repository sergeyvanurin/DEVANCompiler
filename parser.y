%skeleton "lalr1.cc"
%require "3.7"

%define api.value.type variant
%define api.token.constructor
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
%nterm <int> global_body
%nterm binary_operator
%nterm main_class
%nterm class_declaration;
%nterm statement


%%

%left "+" "*";


%start program;

program: main_class class_declaration;

main_class:
    "class" "id" "{" "public static void main" "(" ")" "{" statement "}" "}"

class_declaration:
    %empty
  | class_declaration
  | "class" "id" "{" "}"

statement:


expr:
    expr binary_operator expr
  | "num"
  | "id"
  | "!" expr
  | "(" expr ")"
  | "true"
  | "false"

binary_operator:
        "&&"   |  "||"   |  "<"   | ">"   |  "=="   | "+"   |  "-"   | "*"  | "/"  | "%"
%%

void yy::parser::error(const std::string& m)
{
    std::cout << m << "\n";
}
