%{
#include<stdio.h>
#include<string.h>
int comment = 0;    
%}
identifier  [a-zA-Z][a-zA-Z0-9_]*
%%
#.* {   if(!comment)printf("%s\tPreprocessor directive\n", yytext); }
int |
float   |
char    |
void    |
double  |
if  |
else    |
while   |
do  |
switch  |
for |
main    {   if(!comment)printf("%s\tKeyword\n", yytext);    }
\".*\"  {   if(!comment)printf("%s\tString\n", yytext); }
{identifier}    {   if(!comment)printf("%s\tIdentifier\n", yytext); }
\;  |
\(  |
\)  |
\,  {   if(!comment)printf("%s\tSpecial Character\n", yytext); }
\{  {   if(!comment)printf("%s\tBlcok Begins\n", yytext); }
\}  {   if(!comment)printf("%s\tBlock Ends\n", yytext); }
\+  |
\-  |
\*  |
\/  |
\%  {   if(!comment)printf("%s\tArithmetic Operators\n", yytext); }
\<  |
\>  |
\<= |
\>= |
==  {   if(!comment)printf("%s\tRelational Operators\n", yytext); }
=   {   if(!comment)printf("%s\tAssignment Operator\n", yytext); }
[0-9]+  {   if(!comment)printf("%s\tNumber\n", yytext); }
"/*"    {   comment = 1;    printf("%s\tComment\n", yytext); }
"*/"  {   comment = 0;    }
"//"    {   comment = 2;    printf("%s\tComment\n", yytext); }
[\n]    {   if(comment==2) comment=0;}
%%
int yywrap()
{   
    return 1;   
}
void main()
{
    FILE *file = fopen("input_lexical_analyser.txt","r");
    if(!file)
    {
        printf("File load error\n");
        exit(1);
    }
    else
        printf("File Loaded\n");
    yyin = file;
    yylex();
}