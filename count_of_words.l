%{
#include<stdio.h>
#include<string.h>    

int count = 0;
%}

%%
[a-zA-Z]+   {   if(!strcmp("hello", yytext))    count++;    }
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
    printf("Count : %d\n", count);
}