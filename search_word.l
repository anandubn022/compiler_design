%{
#include<stdio.h>
#include<string.h>    

int count = 0;
%}

%%
[a-zA-Z]+   {   if(!strcmp("hello", yytext)){    printf("word found\n");   exit(0);    }   }
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
    FILE * fp1 = fopen("input_count_of_words.txt", "r");
    if(!fp1)
        exit(1);
    yyin = fp1;
    yylex();
    printf("word not found\n");
}