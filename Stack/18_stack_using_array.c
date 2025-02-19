#include <stdio.h>
#define MAX 5

int IsFull(int);
int IsEmpty(int);
int Pop(int *, int *);
void Push(int *, int *, int);
void Display(const int *, int);

int main(void)
{
    int Stack[MAX];
    int iTop = -1;
    int iPopedData;

    Push(Stack, &iTop, 10);
    Push(Stack, &iTop, 20);
    Push(Stack, &iTop, 30);
    Push(Stack, &iTop, 40);
    printf("Stack using array is\n");
    Display(Stack, iTop);

    iPopedData = Pop(Stack, &iTop);
    if (iPopedData != -1)
        printf("\n\nPoped data is: %d", iPopedData);
    printf("\n\nStack after pop is\n");
    Display(Stack, iTop);

    return 0;
}

void Push(int *pStack, int *piTop, int iNo)
{
    if (IsFull(*piTop))
    {
        printf("Stack overflow");
        return;
    }

    pStack[++(*piTop)] = iNo;
}

int Pop(int *pPop, int *piTop)
{
    if (IsEmpty(*piTop))
    {
        printf("\nStack is empty\n");
        return -1;
    }

    return pPop[(*piTop)--];
}

int IsEmpty(int iTop)
{
    if (iTop == -1)
        return 1;
    return 0;
}

int IsFull(int iTop)
{
    if (iTop == MAX - 1)
        return 1;
    return 0;
}

void Display(const int *pStack, int iTop)
{
    int iCounter;

    for (iCounter = 0; iCounter <= iTop; iCounter++)
    {
        printf(" %d\t", pStack[iCounter]);
    }
}

// Output

// Stack using array is
//  10      20      30      40

// Poped data is: 40

// Stack after pop is
//  10      20      30