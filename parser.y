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
;

%token <std::string> IDENTIFIER "id"
%token <int> NUMBER "num"
%nterm <int> expr
%nterm <int> global_body

%%

%left "+" "*" "/";

%start program;

program: expr {std::cout << $1 << '\n';};


expr:
    "num" "+" "num" {
        $$ = $1 + $3;
    };

%%

void yy::parser::error(const std::string& m)
{
    std::cout << m << "\n";
}
