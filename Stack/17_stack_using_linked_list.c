#include <stdio.h>
#include <malloc.h>
#define MAX 5

struct node
{
    int iData;
    struct node *pNext;
};

int Pop(struct node **);
int IsFull(struct node *);
int IsEmpty(struct node *);
void Display(struct node *);
int CountNodes(struct node *);
void Push(struct node **ppHead, int);

int main(void)
{
    int iPopedData;
    struct node *pStack = NULL;

    Push(&pStack, 10);
    Push(&pStack, 20);
    Push(&pStack, 30);
    printf("Stack is\n");
    Display(pStack);

    iPopedData = Pop(&pStack);
    if (iPopedData != -1)
        printf("\n\nPopped data is: %d\n", iPopedData);

    printf("Stack after poped data\n");
    Display(pStack);

    if (pStack != NULL)
    {
        free(pStack);
        pStack = NULL;
    }

    return 0;
}

void Push(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;

    if (IsFull(*ppHead))
    {
        printf("\nStack overflow\n");
        return;
    }

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("Memory allocation  failed");
        return;
    }

    pNewNode->iData = iNo;

    if (NULL == *ppHead)
    {
        pNewNode->pNext = NULL;
        *ppHead = pNewNode;
        return;
    }

    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
}

int Pop(struct node **ppHead)
{
    int iPopedData;
    struct node *pTemp = NULL;

    if (IsEmpty(*ppHead))
    {
        printf("Stack is empty");
        return -1;
    }

    pTemp = *ppHead;

    *ppHead = pTemp->pNext;
    iPopedData = pTemp->iData;
    free(pTemp);

    return iPopedData;
}

int IsFull(struct node *pHead)
{
    if (CountNodes(pHead) == MAX)
        return 1;
    return 0;
}

int IsEmpty(struct node *pHead)
{
    if (NULL == pHead)
        return 1;
    return 0;
}

int CountNodes(struct node *pHead)
{
    int iCounter = 0;

    while (pHead != NULL)
    {
        iCounter++;
        pHead = pHead->pNext;
    }

    return iCounter;
}

void Display(struct node *pHead)
{
    if (NULL == pHead)
    {
        printf("Stack is empty");
        return;
    }

    while (pHead != NULL)
    {
        printf("|%d|", pHead->iData);
        pHead = pHead->pNext;
    }
}

// Output

// Stack is
// |30||20||10|

// Popped data is: 30
// Stack after poped data
// |20||10|