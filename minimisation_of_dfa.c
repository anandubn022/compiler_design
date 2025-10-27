#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

struct node
{
    int a, b, f, flag;
}a[100];
int n, m, j, k, l, i;

void replace(int x, int y)
{
    for(i=0; i<n; i++)
    {
        if(a[i].flag == 1)
        {
            if(a[i].a == y)
            {
                a[i].a = x;
            }
            if(a[i].b == y)
            {
                a[i].b = x;
            }
        }
    }
}

void minimise()
{
    int ch;
    do
    {
        ch=0;
        for(i=0; i<n; i++)
        {
            if(a[i].flag == 1)
            {
                k = a[i].a;
                l = a[i].b;
                m = a[i].f;
                for(j = i+1; j<n; j++)
                {
                    if(a[j].flag == 1)
                    {
                        if(a[j].a == k && a[j].b == l && a[j].f == m)
                        {
                            a[j].flag = 0;
                            replace(i, j);
                            ch = 1;
                        }
                    }
                }
            }
        }
    } while (ch == 1);
}

void unreachable()
{
    int ch, c;
    do
    {
        ch = 0;
        for(i=1; i<n; i++)
        {
            if(a[i].flag == 1)
            {
                c = 0;
                for(j = 0; j<n; j++)
                {
                    if(i!=j && a[i].flag == 1)
                    {
                        if(a[j].a == i || a[j].b == i)
                        {
                            c = 1;
                            break;
                        }
                    }
                }
            }
            if(c==0)
            {
                a[i].flag = 0;
                ch = 1;
            }
        }
    } while (ch == 1);
    
}

void main()
{
    printf("enter the no of states : ");
    scanf("%d", &n);
    printf("enter the transition table : \nstate\ta\tb\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d", &j, &k,&l);
        a[j].a = k;
        a[j].b = l;
        a[j].f = 0;
        a[j].flag = 1;
    }
    printf("enter no of final states : ");
    scanf("%d", &m);
    printf("enter the final states : ");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &j);
        a[j].f = 1;
    }
    unreachable();
    printf("unreachable eliminated");
    minimise();
    printf("dfa minimised");
    printf("minimised dfa : \nstate\ta\tb\n");
    for(i=0; i<n; i++)
    {
        if(a[i].flag==1)
        {
            printf("%d\t%d\t%d\n", i, a[i].a, a[i].b);
        }
    }
}