%{
    #include <cstring>
    #include <string>
    #include <iostream>
    #include "driver.hpp"
    #include "parser.h"
%}

%option noyywrap nounput noinput batch debug

%option c++
%option yyclass="Scanner"

id          [_a-zA-Z][_a-zA-Z0-9]*
number      [0-9]+

%%

\n\r|\r\b|\n;

{number}            {
                        return yy::parser::make_NUMBER(atoi(yytext));
                    }

{id}                {
                        return yy::parser::make_IDENTIFIER(yytext);
                    }
"+"                 return yy::parser::make_PLUS();
"*"                 return yy::parser::make_STAR();
"/"                 return yy::parser::make_SLASH();
":="                return yy::parser::make_ASSIGN();


