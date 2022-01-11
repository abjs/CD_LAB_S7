(if.l)

ALPHA [A-Za-z]
DIGIT [0-9]
%%
[ \t\n]
if                return IF;
then                return THEN;
{DIGIT}+            return NUM;
{ALPHA}({ALPHA}|{DIGIT})*         return ID;
"<="                return LE;
">="                return GE;
"=="                return EQ;
"!="                return NE;
"||"                return OR;
"&&"                return AND;
.                return yytext[0];
%%          

(if.y)

%{
#include <stdio.h>
#include <stdlib.h>
%}
%token ID NUM IF THEN LE GE EQ NE OR AND
%right '='
%left AND OR
%left '<' '>' LE GE EQ NE
%left '+''-'
%left '*''/'
%right UMINUS
%left '!'
%%
S   : ST {printf("Input accepted.\n");exit(0);};
ST  :    IF '(' E2 ')' THEN ST1';'
    ;
ST1 : ST
    | E
    ;      
E   : ID'='E
    | E'+'E
    | E'-'E
    | E'*'E
    | E'/'E
    | E'<'E
    | E'>'E
    | E LE E
    | E GE E
    | E EQ E
    | E NE E
    | E OR E
    | E AND E
    | ID
    | NUM
    ;
E2  : E'<'E
    | E'>'E
    | E LE E
    | E GE E
    | E EQ E
    | E NE E
    | E OR E
    | E AND E
    | ID
    | NUM
    ;
%%

#include "lex.yy.c"

main()
{
printf("Enter the statement: ");
yyparse();
}  
