%skeleton "lalr1.cc"
%require "3.7"

%define api.value.type variant
%define api.token.constructor
%define parse.assert

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
;

%token <std::string> IDENTIFIER "id"
%token <int> NUMBER "num"
%nterm <int> expr

%%

%left "+" "*" "/";

%start program;

program: main_class {};

main_class: "class" "Main" "{" "public static void main" "(" ")" "{" global_body "}" "}"  {};

global_body:
    %empty {}
    | global_statement global_statement {};

global_statement:
    %empty {}
    | expr {
        std::cout << $1 << "\n";
    };

expr:
    "num" "+" "num" {
        $$ = $1 + $3;
    };

%%
