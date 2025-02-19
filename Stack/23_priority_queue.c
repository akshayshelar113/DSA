#include <stdio.h>
#include <malloc.h>
#define MAX 5

struct node
{
    int iData;
    int iPri;
    struct node *pNext;
};

void Display(struct node *);
void EnQueue(struct node **, int, int);
int IsQueueFull(struct node *);
int CountNodes(struct node *);
int DeQueue(struct node **);
void DeleteAll(struct node **);
void InsertFirst(struct node **, int, int);

void EnQueue(struct node **, int, int);

int main(void)
{
    int iDeQuedData;
    struct node *pPriority = NULL;

    EnQueue(&pPriority, 10, 3);
    EnQueue(&pPriority, 20, 2);
    EnQueue(&pPriority, 30, 4);
    EnQueue(&pPriority, 40, 5);
    EnQueue(&pPriority, 50, 1);
    Display(pPriority);

    iDeQuedData = DeQueue(&pPriority);
    if (iDeQuedData != -1)
        printf("\n\nDequed Higest priority data is: %d", iDeQuedData);
    printf("\nQueue after Deque is\n");
    Display(pPriority);

    printf("\n\nQueue after delete all\n");
    DeleteAll(&pPriority);
    Display(pPriority);

    return 0;
}

void EnQueue(struct node **ppHead, int iNo, int iPri)
{
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    if (NULL == *ppHead || iPri > (*ppHead)->iPri)
    {
        InsertFirst(ppHead, iNo, iPri);
        return;
    }

    pNewNode = (struct node *)malloc(sizeof(struct node));
    if (NULL == pNewNode)
    {
        printf("Memory allocation failed");
        return;
    }

    pNewNode->iData = iNo;
    pNewNode->iPri = iPri;

    pTemp = *ppHead;

    while (pTemp->pNext != NULL)
    {
        if (iPri > pTemp->pNext->iPri)
        {
            pNewNode->pNext = pTemp->pNext;
            pTemp->pNext = pNewNode;
            return;
        }
        pTemp = pTemp->pNext;
    }
    pNewNode->pNext = NULL;
    pTemp->pNext = pNewNode;
}
void InsertFirst(struct node **ppHead, int iNo, int iPri)
{
    struct node *pNewNode = NULL;

    if (IsQueueFull(*ppHead))
    {
        printf("\nQueue is Full\n");
        return;
    }

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("Memory allocation failed");
        return;
    }

    pNewNode->iData = iNo;
    pNewNode->iPri = iPri;

    if (NULL == *ppHead)
    {
        pNewNode->pNext = NULL;
        *ppHead = pNewNode;
        return;
    }

    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
}

int DeQueue(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp = NULL;

    if (IsQueueEmpty(*ppHead))
    {
        printf("\nQueue is empty\n");
        return -1;
    }

    pTemp = *ppHead;

    *ppHead = pTemp->pNext;
    iDelData = pTemp->iData;
    free(pTemp);

    return iDelData;
}

int IsQueueEmpty(struct node *pHead)
{
    if (NULL == pHead)
        return 1;
    return 0;
}

int IsQueueFull(struct node *pHead)
{
    if (CountNodes(pHead) == MAX)
        return 1;
    return 0;
}

int CountNodes(struct node *pHead)
{
    int iCount = 0;

    while (pHead != NULL)
    {
        iCount++;
        pHead = pHead->pNext;
    }
    return iCount;
}

void Display(struct node *pHead)
{
    if (NULL == pHead)
    {
        printf("Queue is empty");
        return;
    }
    while (pHead != NULL)
    {
        printf("|%d, %d|\t", pHead->iData, pHead->iPri);
        pHead = pHead->pNext;
    }
}

void DeleteAll(struct node **ppHead)
{
    struct node *pTemp = NULL;

    while (*ppHead != NULL)
    {
        pTemp = *ppHead;
        *ppHead = pTemp->pNext;
        free(pTemp);
    }
}