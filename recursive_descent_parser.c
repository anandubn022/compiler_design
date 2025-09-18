#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char str[100];
int A();
int S();
int i;

void main()
{
    printf("Enter the input : ");
    scanf("%s", str);
    i=0;
    if(S() == 1 && str[i] == '\0')
    {
        printf("String Accepted\n");
    }
    else
    {
        printf("String not Accepted\n");
    }
}

int S()
{
    if(str[i] == 'c')
    {
        i++;
        if(A() == 1)
        {
            if(str[i] == 'd')
            {
                i++;
                return 1;
            }
        }
    }
    
    return 0;
}

int A()
{
    if(str[i] == 'a')
    {
        i++;
        if(str[i] == 'b')
        {
            i++;
            return 1;
        }
        return 1;
    }

    return 0;
}