//Outputs but incorrect
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

int n, m, i, j, k, z;
char a[100][100], f[100], c;

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
        scanf("%s%c", a[q], &ch); // This is fine
    }
    printf("the productions : \n"); // Added \n for cleaner output
    for (int q = 0; q < n; q++)
    {
        printf("%s\n", a[q]);
    }
    
    do
    {
        m=0;
        strcpy(f, "");
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
        printf("continue?[1 for y/0 for n] : "); // Made prompt clearer
        scanf("%d%c", &z, &ch); // This is fine
    } while (z==1);
    
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

void first(char c)
{
    if(!isupper(c))
    {
        f[m++] = c;
    }
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

void firstF(char c, char w, int x, int y)
{
    if(!isupper(c))
    {
        f[m++]=c;
    }
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