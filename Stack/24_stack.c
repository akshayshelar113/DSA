#include "24_stack.h"

int g_iTop = -1;
int g_Stack[STACK_MAX];

void Push(long lSymbol)
{
    if (IsFull())
    {
        printf("Stack overflow");
        return;
    }

    g_Stack[++g_iTop] = lSymbol;
}

long Pop(void)
{
    if (IsEmpty())
        return -1;

    return g_Stack[g_iTop--];
}

int IsFull(void)
{
    if (g_iTop == STACK_MAX - 1)
        return 1;
    return 0;
}

int IsEmpty(void)
{
    if (g_iTop == -1)
        return 1;
    return 0;
}