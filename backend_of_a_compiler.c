#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void main()
{
    char icode[100][100], str[100], op1[100];
    int i=0;

    printf("Enter intermediate code (terminated by exit) :");
    do
    {
        /* code */
        scanf("%s", icode[i]);
    } while (strcmp(icode[i++], "exit"));
    
    printf("Target code generation\n");
    i=0;
    do
    {
        /* code */
        switch (icode[i][3])
        {
        case '+':
            /* code */
            strcpy(op1, "ADD");
            break;

        case '-':
            /* code */
            strcpy(op1, "SUB");
            break;

        case '*':
            /* code */
            strcpy(op1, "MUL");
            break;

        case '/':
            /* code */
            strcpy(op1, "DIV");
            break;
        
        default:
            break;
        }

        printf("MOV %c, R%d \n", icode[i][2], i);
        printf("%s %c, R%d \n", op1, icode[i][4], i);
        printf("MOV R%d, %c \n", i, icode[i][0]);

    } while (strcmp(icode[++i], "exit")    );
    

}