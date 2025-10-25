%{
#include<stdio.h>
#include<string.h>
int flag = 1;
%}
%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%%
ArithmeticExpression : E{
    printf("Result : %d\n", $$);
    return 0;
};
E:E'+'E {$$=$1+$3;}
|E'-'E  {$$=$1-$3;}
|E'*'E  {$$=$1*$3;}
|E'/'E  {$$=$1/$3;}
|'('E')'    {$$=$2;}
|NUMBER {$$=$1;};
%%
int yyerror()
{
    flag = 0;
    printf("Invalid Expression\n");
}
void main()
{
    printf("Enter arithmetic expression : ");
    yyparse();
    if(flag)
        printf("Valid Expression\n");
}