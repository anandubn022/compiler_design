#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<stdbool.h>

#define SIZE 100
char stack[SIZE];
int top = -1;

int is_operator(char);
int precedence(char c);
void push(char);
char pop();

void infixtopostfix(char _infix[], char _postfix[])
{
    int i=0, j=0;
    push('(');
    strcat(_infix, ")");
    char item = _infix[i];
    while (item!='\0')
    {
        if(item == '(')
            push(item);

        else if(isdigit(item)||isalpha(item))
        {
            _postfix[j] = item;
            j++;
        }

        else if (is_operator(item))
        {
            char x = pop();
            while (is_operator(x) && precedence(x) >= precedence(item))
            {
                _postfix[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(item);
        }
        else if(item == ')')
        {
            char x = pop();
            while (x!='(')
            {
                _postfix[j] = x;
                j++;
                x = pop();
            }
            
        }
        else 
        {
            printf("invalid expression\n");
            exit(1);
        }
        i++;
        item = _infix[i];
    }

    if(top>0)
    {
        printf("ivalid expression\n");
        exit(1);
    }
    _postfix[j] = '$';
}

void main()
{
    char infix[SIZE], postfix[SIZE], x, y;
    printf("Enter the infix expression : ");
    scanf("%s", infix);
    infixtopostfix(infix, postfix);
    printf("postfix expression : %s\n", postfix);

    int i=0;
    while(postfix[i]!='$')
    {
        int k=1;
        if(isalpha(postfix[i]))
        {
            push(postfix[i]);
        }
        else if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='/'||postfix[i]=='*'||postfix[i]=='^')
        {
            x=pop();
            y=pop();
            if(x=='t')
            {
                printf("%c  %c  t%d    t%d\n", postfix[i], y, k, k+1);
                k++;
            }
            else if(y=='t')
            {
                printf("%c  t%d %c  t%d\n", postfix[i], k, x, k+1);
                k++;
            }
            else
            {
                printf("%c  %c  %c  t%d\n", postfix[i], y, x, k);
            }
            push('t');
        }
        i++;
    }
}

int is_operator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
        return 1;
    return 0;
}

int precedence(char c)
{
    if(c=='^')
        return 3;
    else if(c=='*'||c=='/')
        return 2;
    else if(c=='+'||c=='-')
        return 1;
    else
        return 0;
}

void push(char item)
{
    if(top>=SIZE-1)
        printf("Stack full");
    else
    {
        top++;
        stack[top]=item;
    }
}

char pop()
{
    if(top<0)
    {
        printf("stack empty");
        exit(1);
    }
    else
    {
        char item = stack[top];
        top--;
        return item;
    }
}