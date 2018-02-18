#include<stdio.h>
#include <ctype.h>
char stack[50];
int top = -1;
void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if (x == '(')
        return 0;
    else if (x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;
    else if(x == '^')
        return 3;
}

int main()
{
    char infix[50], postfix[50], x;
    int i, n = 0;
    printf("Siddharth Chandra, 16115078\n");
    printf("Enter infix expression: ");
    scanf("%s", infix);
    printf("\nInfix: %s", infix);
    for(i = 0; infix[i]!='\0'; i++)
    {
        if(isalnum(infix[i]))
            postfix[n++] = infix[i];
        else if(infix[i] == '(')
            push(infix[i]);
        else if(infix[i] == ')')
        {
            while(1)
            {
                x = pop();
                if (x != '(')
                    postfix[n++] = x;
                else
                    break;
            }
        }
        else if(infix[i] == ' ');
        else
        {
            while(priority(stack[top]) >= priority(infix[i]))
                postfix[n++] = pop();
            push(infix[i]);
        }
    }
    while(top != -1)
        postfix[n++] = pop();
    postfix[n] = '\0';
    printf("\nPostfix expression: %s", postfix);
    return 0;
}
