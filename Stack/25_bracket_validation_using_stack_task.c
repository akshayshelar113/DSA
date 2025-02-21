#include <stdio.h>
#define MAX 50
#include "24_stack.c"

int IsExpresionValid(const char *);

int main(void)
{
    int iCheck;
    char szInfix[MAX] = {0};
    printf("Enter string to check validation\n");
    gets(szInfix);

    iCheck = IsExpresionValid(szInfix);
    if (iCheck == 0)
        printf("Expression is invalid");
    else
        printf("Expression is valid");
}

int IsExpresionValid(const char *pInfix)
{
    int iCounter;
    int tempTop = -1;
    char tempStack[STACK_MAX];

    for (iCounter = 0; pInfix[iCounter] != '\0'; iCounter++)
    {
        if (pInfix[iCounter] == '(')

            tempStack[++tempTop] = '(';

        else if (pInfix[iCounter] == ')')
        {
            if (tempTop == -1)
                return 0;

            tempTop--;
        }
    }
    return (tempTop == -1);
}