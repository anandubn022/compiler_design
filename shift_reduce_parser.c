#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char input[100], stk[100];
int i=0, j=0, c=0;

void check()
{
    for(int z=0; z<c; z++)
    {
        if(stk[z]=='i' && stk[z+1]=='d')
        {
            stk[z] = 'E';
            stk[z+1] = '\0';
            printf("%s\t%s\tReduce to E\n", stk, input);
            j++;
        }
    }

    for(int z=0; z<c; z++)
    {
        if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='E'){
            stk[z]='E';
            stk[z+1]='\0';
            stk[z+2]='\0';
            printf("%s\t%s\tReduce to E\n", stk, input);
            i-=2;
        }
    }

    for(int z=0; z<c; z++)
    {
        if(stk[z]=='E' && stk[z+1]=='*' && stk[z+2]=='E'){
            stk[z]='E';
            stk[z+1]='\0';
            stk[z+2]='\0';
            printf("%s\t%s\tReduce to E\n", stk, input);
            i-=2;
        }
    }

    for(int z=0; z<c; z++)
    {
        if(stk[z]=='(' && stk[z+1]=='E' && stk[z+2]==')'){
            stk[z]='E';
            stk[z+1]='\0';
            stk[z+2]='\0';
            printf("%s\t%s\tReduce to E\n", stk, input);
            i-=2;
        }
    }
    
}

void main()
{
    printf("The Grammar is \nE->E+E\tE->E*E\tE->(E)\tE->id\n");
    printf("Enter the input string : ");
    scanf("%s", input);
    c=strlen(input);

    printf("Stack\tInput\tAction\n");
    for (j < c; i++, j++)
    {
        if (input[j]=='i' && input[j+1]=='d')
        {
            stk[i]=input[j];
            stk[i+1]=input[j+1];
            stk[i+2]='\0';
            input[j]=' ';
            input[j+1]=' ';
            printf("%s\t%s\tSHIFT->id\n", stk, input);
            check();
        }

        else
        {
            stk[i]=input[j];
            stk[i+1]='\0';
            printf("%s\t%s\tSHIFT->symbols\n", stk, input);
            check();
        }
        
    }
    
}