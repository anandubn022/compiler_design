#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void main()
{
    FILE * file = fopen("input_lexical_analyser.txt", "r");
    if(!file)
    {
        printf("File not loaded\n");
        exit(1);
    }

    char c=fgetc(file);
    while(c!=EOF)
    {
        if(c=='/')
        {
            c=fgetc(file);
            if(c=='/')
            {
                do
                {
                    c=fgetc(file);
                } while (c!='\n' && c!=EOF);
                
            }
            else
            {
                printf("/\tOperator\n");
                c=fgetc(file);
            }
        }
        else if(c=='+'||c=='-'||c=='*'||c=='/'||c=='%')
        {
            printf("%c\tOperator\n", c);
            c=fgetc(file);
        }
        else if(isalpha(c) && c!=' ' && c!='\n')
        {
            int i=0;
            char token[100];
            while (isalpha(c) && c!=' ' && c!='\n')
            {
                token[i++]=c;
                c=fgetc(file);
            }
            token[i]='\0';
            if (!strcmp("main", token) || !strcmp("int", token) || !strcmp("float", token) || !strcmp("char", token))
            {
                printf("%s\tKeyword\n", token);
            }
            else
            {
                printf("%s\tIdentifier\n", token);
            }
        }
        else if(isdigit(c) && c!=' ' && c!='\n')
        {
            int i=0;
            char token[100];
            while(isdigit(c) && c!=' ' && c!='\n')
            {
                token[i++]=c;
                c=fgetc(file);
            }
            token[i]='\0';
            printf("%s\tNumber\n", token);
        }
        else if(c=='('||c==')'||c=='{'||c=='}'||c==';')
        {
            printf("%c\tSpecial Character\n", c);
            c=fgetc(file);
        }
        else
        {
            c=fgetc(file);
        }
    }

}