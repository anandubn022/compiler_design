%{
#include<stdio.h>
#include<string.h>

int count = 0;    
%}

digit [0-9]
letter[a-zA-Z_]

%%
{letter}({letter}|{digit})*   {   count++;    }
[\n]    ;
[\t]    ;
.   ;
%%

int yywrap()
{
    return 1;
}

void main()
{
    yylex();
    printf("Count : %d\n", count);
}