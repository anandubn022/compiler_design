#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>

void stack_push(char item);
char stack_pop();
int is_operator(char symbol);
int precedence(char symbol);
void infix_to_postfix(char infix_expression[], char postfix_expression[]);

char stack1[100], stack2[100];
int top = -1;
#define SIZE 100

void main()
{
    char infix_expression[SIZE], postfix_expression[100];
    printf("Enter the infix expression : ");
    scanf("%s", infix_expression);
    infix_to_postfix(infix_expression, postfix_expression);
    printf("The postfix expression : %s\n", postfix_expression);

    char x, y;
    int i=0, k=1;
    while (postfix_expression[i] != '$')
    {
        /* code */
        if (isalpha(postfix_expression[i] ))
        {
            /* code */
            stack_push(postfix_expression[i]);
        }
        else if (postfix_expression[i] == '+' || postfix_expression[i] == '-' || postfix_expression[i] == '*' || postfix_expression[i] == '/' || postfix_expression[i] == '^')
        {
            /* code */
            x = stack_pop();
            y = stack_pop();
            if (x=='t')
            {
                /* code */
                printf("%c %c t%d t%d \n", postfix_expression[i], y, k, k+1);
            }
            else if (y=='t')
            {
                /* code */
                printf("%c t%d %c t%d \n", postfix_expression[i], k, x, k+1);
            }
            
            else
                printf("%c %c %c t%d \n", postfix_expression[i], y, x, k);
            stack_push('t');
        }
        
        i++;
    }
    
}

int is_operator(char symbol)
{
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^')
    {
        /* code */
        return 1;
    }
    return 0;
    
}

int precedence(char symbol)
{
    if (symbol == '^')
    {
        /* code */
        return 3;
    }
    else if (symbol == '*' || symbol == '/')
    {
        /* code */
        return 2;
    }
    else if (symbol == '+' || symbol == '-')
    {
        /* code */
        return 1;
    }
    else
        return 0;
    
}

void infix_to_postfix(char infix_expression[], char postfix_expression[])
{
    int i=0, j=0;
    char item, x;

    stack_push('(');
    strcat(infix_expression, ")");
    item = infix_expression[i];
    while (item!='\0')
    {
        /* code */
        if (item == '(')
        {
            /* code */
            stack_push(item);
        }
        else if (isalpha(item) || isdigit(item))
        {
            /* code */
            postfix_expression[j] = item;
            j++;
        }
        else if (is_operator(item))
        {
            /* code */
            x = stack_pop();
            while (is_operator(x) && precedence(x) >= precedence(item))
            {
                /* code */
                postfix_expression[j] = x;
                j++;
                x = stack_pop();
            }
            
            stack_push(x);
            stack_push(item);
        }
        
        else if (item == ')')
        {
            /* code */
            x = stack_pop();
            while (x != '(')
            {
                /* code */
                postfix_expression[j] = x;
                j++;
                x = stack_pop();
            }
            
        }
        else
        {
            printf("Invalid Infix Expression\n");
            getchar();
            exit(1);
        }
        i++;
        item = infix_expression[i];
        
    }
    if (top > 0)
    {
        /* code */
        printf("Invalid Postfix Expression");
        getchar();
        exit(1);
    }

    postfix_expression[j] = '$';
    
}

void stack_push(char item)
{
    if (top >= SIZE - 1)
    {
        /* code */
        printf("Stack Overflow\n");
    }
    else
    {
        top += 1;
        stack1[top] = item;
    }
    
}

char stack_pop()
{
    char item;
    if (top < 0)
    {
        /* code */
        printf("Stack Underflow\n");
        getchar();
        exit(1);

    }
    item = stack1[top];
    top -= 1;
    return item;
}