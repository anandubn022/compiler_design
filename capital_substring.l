%{
#include<stdio.h>
#include<string.h>
%}

%%
hello   {   printf("HELLO");    }
.   {   printf("%s", yytext);   }
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
}