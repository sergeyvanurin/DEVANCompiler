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

%{
  yy::parser::symbol_type make_NUMBER (const std::string &s, const yy::parser::location_type& loc);
  void Scanner::UpdateLocation() {
      driver.loc.columns(yyleng);
   }
%}

id          [_a-zA-Z][_a-zA-Z0-9]*
number      [0-9]+
brackets    [\[][ ]*[\]]
this_invocation "this"[ ]*"."
blank       [ \t\r]

%{
  # define YY_USER_ACTION  loc.columns(yyleng);
%}

%%

%{
    yy::location& loc = driver.loc;
    loc.step();
%}

{blank}+                    loc.step();
\n+                         loc.lines(yyleng); loc.step();

"public static void main"   return yy::parser::make_BOYLERPLATE(loc);
{brackets}                  return yy::parser::make_EMPTYBRACKETS(loc);
{this_invocation}           return yy::parser::make_THISINV(loc);

"+"                         return yy::parser::make_PLUS(loc);
"*"                         return yy::parser::make_STAR(loc);
"/"                         return yy::parser::make_SLASH(loc);
"-"                         return yy::parser::make_MINUS(loc);
"%"                         return yy::parser::make_PERCENT(loc);
"=="                        return yy::parser::make_BOOLEQUALS(loc);
">"                         return yy::parser::make_MORE(loc);
"<"                         return yy::parser::make_LESS(loc);
"||"                        return yy::parser::make_BITWISEOR(loc);
"&&"                        return yy::parser::make_BITWISEAND(loc);

"{"                         return yy::parser::make_LEFTFBRACKET(loc);
"}"                         return yy::parser::make_RIGHTFBRACKET(loc);
"("                         return yy::parser::make_LBRACKET(loc);
")"                         return yy::parser::make_RBRACKET(loc);
","                         return yy::parser::make_COMMA(loc);
";"                         return yy::parser::make_SEMICOLON(loc);
"["                         return yy::parser::make_LEFTSBRACKET(loc);
"]"                         return yy::parser::make_RIGHTSBRACKET(loc);
"="                         return yy::parser::make_EQUALS(loc);
"."                         return yy::parser::make_DOT(loc);
"!"                         return yy::parser::make_BANG(loc);
"class"                     return yy::parser::make_CLASS(loc);
"extends"                   return yy::parser::make_EXTENDS(loc);
"public"                    return yy::parser::make_PUBLIC(loc);
"int"                       return yy::parser::make_INT(loc);
"boolean"                   return yy::parser::make_BOOLEAN(loc);
"void"                      return yy::parser::make_VOID(loc);
"assert"                    return yy::parser::make_ASSERT(loc);
"if"                        return yy::parser::make_IF(loc);
"while"                     return yy::parser::make_WHILE(loc);
"else"                      return yy::parser::make_ELSE(loc);
"System.out.println"        return yy::parser::make_PRINT(loc);
"return"                    return yy::parser::make_RETURN(loc);
"this"                      return yy::parser::make_THIS(loc);
"length"                    return yy::parser::make_LENGTH(loc);
"new"                       return yy::parser::make_NEW(loc);
"true"                      return yy::parser::make_TRUE(loc);
"false"                     return yy::parser::make_FALSE(loc);

{number}                    return yy::parser::make_NUMBER(atoi(yytext), loc);
{id}                        return yy::parser::make_IDENTIFIER(yytext, loc);

.                           {
                                throw yy::parser::syntax_error(loc, "invalid character: " + std::string(yytext));
                            }
<<EOF>>                     return yy::parser::make_END (loc);

%%
