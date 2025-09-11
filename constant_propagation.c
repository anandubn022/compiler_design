#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct expression
{
    /* data */
    char op1[100], op2[100], op3[100], res[100];
    int flag;
}array[100];
int n;
void input();
void output();
void constant();
void change(int p, char * res);

void main()
{
    input();
    constant();
    output();
}

void input()
{
    printf("Enter the no of expression : ");
    scanf("%d", &n);
    printf("Enter the expressions :\n");
    for (int i = 0; i<n; i++)
    {
        scanf("%s", array[i].op1);
        scanf("%s", array[i].op2);
        scanf("%s", array[i].op3);
        scanf("%s", array[i].res);
        array[i].flag = 0;
    }
}

void constant()
{
    int _op2, _op3, _res;
    char _op1, _res1[100];

    for(int i=0; i<n; i++)
    {
        if(!strcmp(array[i].op1, "="))
        {
            _op1 = array[i].op1[0];
            _op2 = atoi(array[i].op2);
            _op3 = atoi(array[i].op3);
            _res = _op2;
            sprintf(_res1, "%d", _res);
            change(i, _res1);
            array[i].flag = 1;
        }
    }
}

void output()
{
    printf("Optimised Code : \n");
    for(int i=0; i<n; i++)
    {
        if(!array[i].flag)
        {
            printf("%s", array[i].op1);
            printf("\t");
            printf("%s", array[i].op2);
            printf("\t");
            printf("%s", array[i].op3);
            printf("\t");
            printf("%s", array[i].res);
            printf("\n");
        }
    }
}

void change(int p, char * res)
{
    for(int i=p+1; i<n; i++)
    {
        if(!strcmp(array[p].res, array[i].op2))
            strcpy(array[i].op2, res);
        if(!strcmp(array[p].res, array[i].op3))
            strcpy(array[i].op3, res);
    }
}