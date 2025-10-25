%{
#include<stdio.h>
#include<string.h>
int flag=1;    
%}

%token letter digit

%%
start:letter s
s:letter s
|digit s
|
;
%%

int yyerror()
{
    flag = 0;
    printf("Invalid Identifier\n");
}

void main()
{
    printf("Enter the identifier : ");
    yyparse();
    if(flag)
        printf("Valid Identifier\n");
}