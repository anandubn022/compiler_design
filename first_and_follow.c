
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include<math.h>

int n, m, i, j;
char a[100][100], f[100], c, z;

void first(char c);
void follow(char c);
void firstT(char c, int x, int y);
void firstF(char c, char w, int x, int y);

void main()
{
    char ch;
    printf("enter the no of productions : ");
    scanf("%d", &n);
    printf("enter the productions : ");
    for (int q = 0; q < n; q++)
    {
        scanf("%s", a[q]); // This is fine
    }
    
    do
    {
        m=0;
        printf("enter the element : ");
        scanf(" %c", &c); // <-- FIX 1
        first(c);
        printf("first (%c) : ", c);
        for (int q=0; q<m; q++)
        {
            printf("%c", f[q]);
        }
        printf("\n");
        m=0;
        strcpy(f, "");
        follow(c);
        printf("follow (%c) : ", c); // <-- FIX 2
        for (int q=0; q<m; q++)
        {
            printf("%c", f[q]);
        }
        printf("\n");
        printf("continue?[y/n] : "); // Made prompt clearer
        scanf(" %c", &z); // This is fine
    } while (z=='y'||z=='Y');
    
}

void first(char c)
{
    if(!isupper(c))
    {
        f[m++] = c;
    }
    int k;
    for(k=0; k<n; k++)
    {
        if(a[k][0] == c)
        {
            if(a[k][2] == '#')
            {
                f[m++]='#';
            }
            else if(islower(a[k][2]))
            {
                f[m++]=a[k][2];
            }
            else
            {
                firstT(a[k][2], k, 3);
            }
        }
    }
}

void firstT(char c, int x, int y)
{
    if(!isupper(c))
    {
        f[m++]=c;
    }
    int k;
    for(k=0; k<n; k++)
    {
        if(a[k][0] == c)
        {
            if(a[k][2] == '#')
            {
                if(a[x][y]!='\0')
                {
                    firstT(a[x][y], x, y+1);
                }
                else 
                {
                    f[m++]='#';
                }
            }
            else if(islower(a[k][2]))
            {
                f[m++]=a[k][2];
            }
            else
            {
                firstT(a[k][2], k, 3);
            }
        }
    }
}

void follow(char c)
{
    if(a[0][0]==c)
    {
        f[m++] = '$';
    }
    for(i=0; i<n; i++)
    {
        for(j=2; j<strlen(a[i]); j++)
        {
            if(a[i][j] == c)
            {
                if(a[i][j+1]!='\0')
                {
                    firstF(a[i][j+1], a[i][0], i, j+2);
                }
                if(a[i][j+1]=='\0' && a[i][0]!=c)
                {
                    follow(a[i][0]);
                }
            }
        }
    }
}

void firstF(char c, char w, int x, int y)
{
    if(!isupper(c))
    {
        f[m++]=c;
    }
    int k;
    for(k=0; k<n; k++)
    {
        if(a[k][0] == c)
        {
            if(a[k][2] == '#')
            {
                if(a[x][y]!='\0')
                {
                    firstF(a[x][y], w, x, y+1);
                }
                else
                {
                    follow(a[x][0]);
                }
            }
            else if(islower(a[k][2]))
            {
                f[m++]= a[k][2];
            }
            else
            {
                firstF(a[k][2], a[k][0], k, 3);
            }
        }
    }
}