%{
    #include <cstring>
    #include <string>
    #include <iostream>
    #include "driver.hpp"
    #include "parser.hpp"
%}

%option noyywrap nounput noinput batch debug

%option c++
%option yyclass="Scanner"

id          [_a-zA-Z][_a-zA-Z0-9]*
number      [0-9]+
brackets    [\[][ ]*[\]]

%%

\n\r|\r\b|\n;

"public static void main"   return yy::parser::make_BOYLERPLATE();
{brackets}                  return yy::parser::make_EMPTYBRACKETS();

"+"                         return yy::parser::make_PLUS();
"*"                         return yy::parser::make_STAR();
"/"                         return yy::parser::make_SLASH();
"-"                         return yy::parser::make_MINUS();
"%"                         return yy::parser::make_PERCENT();
"=="                        return yy::parser::make_BOOLEQUALS();
">"                         return yy::parser::make_MORE();
"<"                         return yy::parser::make_LESS();
"||"                        return yy::parser::make_BITWISEOR();
"&&"                        return yy::parser::make_BITWISEAND();

"{"                         return yy::parser::make_LEFTFBRACKET();
"}"                         return yy::parser::make_RIGHTFBRACKET();
"("                         return yy::parser::make_LBRACKET();
")"                         return yy::parser::make_RBRACKET();
","                         return yy::parser::make_COMMA();
";"                         return yy::parser::make_SEMICOLON();
"["                         return yy::parser::make_LEFTSBRACKET();
"]"                         return yy::parser::make_RIGHTSBRACKET();
"="                         return yy::parser::make_EQUALS();
"."                         return yy::parser::make_DOT();
"!"                         return yy::parser::make_BANG();
"class"                     return yy::parser::make_CLASS();
"extends"                   return yy::parser::make_EXTENDS();
"public"                    return yy::parser::make_PUBLIC();
"int"                       return yy::parser::make_INT();
"boolean"                   return yy::parser::make_BOOLEAN();
"void"                      return yy::parser::make_VOID();
"assert"                    return yy::parser::make_ASSERT();
"if"                        return yy::parser::make_IF();
"while"                     return yy::parser::make_WHILE();
"else"                      return yy::parser::make_ELSE();
"System.out.println"        return yy::parser::make_PRINT();
"return"                    return yy::parser::make_RETURN();
"this"                      return yy::parser::make_THIS();
"length"                    return yy::parser::make_LENGTH();
"new"                       return yy::parser::make_NEW();
"true"                      return yy::parser::make_TRUE();
"false"                     return yy::parser::make_FALSE();

{number}                    return yy::parser::make_NUMBER(atoi(yytext));
{id}                        return yy::parser::make_IDENTIFIER(yytext);

%%