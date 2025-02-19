#include <stdio.h>
#include <math.h>
#include "24_stack.c"
#define MAX 50

int IsSpace(char);
int IsOperator(char);
long PostfixEvalution(const char *);
void InFixToPostfix(const char *, char *);

int main(void)
{
    int lResult;
    char szInfix[MAX] = {0};
    char szPostfix[MAX] = {0};

    printf("Enter Infix operation:\n");
    gets(szInfix);

    printf("Infix Operation is: %s", szInfix);

    InFixToPostfix(szInfix, szPostfix);
    printf("\nPostfix expression is: %s", szPostfix);

    lResult = PostfixEvalution(szPostfix);
    printf("\n\nResult is: %d", lResult);

    return 0;
}

void InFixToPostfix(const char *pszInfix, char *pszPostfix)
{
    int iCounter1;
    int iCounter2;
    int iPriority;
    char chSymbol;

    extern int g_iTop;
    extern int g_Stack[STACK_MAX];

    iCounter2 = 0;
    for (iCounter1 = 0; pszInfix[iCounter1] != '\0'; iCounter1++)
    {
        chSymbol = pszInfix[iCounter1];
        if (IsSpace(chSymbol))
            continue;

        if ((iPriority = IsOperator(chSymbol)) != 0)
        {
            while (!IsEmpty() && IsOperator(g_Stack[g_iTop]) >= iPriority)
                pszPostfix[iCounter2++] = Pop();

            Push(chSymbol);
        }

        else if (chSymbol == '(')
            Push(chSymbol);
        else if (chSymbol == ')')
        {
            while ((chSymbol = Pop()) != '(')
                pszPostfix[iCounter2++] = chSymbol;
        }
        else
        {
            pszPostfix[iCounter2++] = '[';
            while (1)
            {
                pszPostfix[iCounter2++] = chSymbol;
                chSymbol = pszInfix[++iCounter1];
                if (IsSpace(chSymbol) || IsOperator(chSymbol) || chSymbol == '\0' || chSymbol == ')')
                    break;
            }
            pszPostfix[iCounter2++] = ']';
            iCounter1--;
        }
    }
    while (!IsEmpty())
        pszPostfix[iCounter2++] = Pop();
    pszPostfix[iCounter2] = '\0';
}

long PostfixEvalution(const char *pszPostfix)
{
    int iCounter1;
    int iCounter2;
    char chSymbol;

    long lResult;
    long lOperand1;
    long lOperand2;

    char szTemp[50];

    for (iCounter1 = 0; pszPostfix[iCounter1] != '\0'; iCounter1++)
    {
        chSymbol = pszPostfix[iCounter1];

        if (IsOperator(chSymbol))
        {
            lOperand2 = Pop();
            lOperand1 = Pop();

            switch (chSymbol)
            {
            case '+':
                lResult = lOperand1 + lOperand2;
                break;
            case '-':
                lResult = lOperand1 - lOperand2;
                break;
            case '*':
                lResult = lOperand1 * lOperand2;
                break;
            case '/':
                lResult = lOperand1 / lOperand2;
                break;
            case '^':
                lResult = pow(lOperand1, lOperand2);
            }
            Push(lResult);
        }
        else
        {
            iCounter2 = 0;
            while (1)
            {
                chSymbol = pszPostfix[++iCounter1];
                if (chSymbol == ']')
                    break;
                szTemp[iCounter2++] = chSymbol;
            }
            szTemp[iCounter2] = '\0';
            Push(atol(szTemp));
        }
    }
    return Pop();
}

int IsOperator(char chSymbol)
{
    switch (chSymbol)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;

    default:
        return 0;
    }
}

int IsSpace(char chSymbol)
{
    if (chSymbol == ' ' || chSymbol == '\t')
        return 1;
    return 0;
}