#include <stdio.h>
#include <malloc.h>
#define MAX 5

struct node
{
    int iData;
    struct node *pNext;
};

void EnQueue(struct node **, int);
int DeQueue(struct node **);
int IsQueueFull(struct node *);
int IsQueueEmpty(struct node *);
int CountNodes(struct node *);
void Display(struct node *);
void DeleteAll(struct node **);

int main(void)
{
    int iDequedData;
    struct node *pQueue = NULL;

    EnQueue(&pQueue, 10);
    EnQueue(&pQueue, 20);
    EnQueue(&pQueue, 30);
    EnQueue(&pQueue, 40);
    printf("Queue is\n");
    Display(pQueue);

    iDequedData = DeQueue(&pQueue);
    if (iDequedData != -1)
        printf("\n\nDequed data is: %d", iDequedData);
    printf("\n\nQueue after dequeue is\n");
    Display(pQueue);

    if (pQueue != NULL)
    {
        DeleteAll(&pQueue);
        pQueue = NULL;
    }
    printf("\n\nQueste after free\n");
    Display(pQueue);
    return 0;
}

void EnQueue(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    if (IsQueueFull(*ppHead))
    {
        printf("Queue is full");
        return;
    }

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("Memory allocation failed");
        return;
    }

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    if (NULL == *ppHead)
    {
        *ppHead = pNewNode;
        return;
    }

    pTemp = *ppHead;
    while (pTemp->pNext != NULL)
        pTemp = pTemp->pNext;

    pTemp->pNext = pNewNode;
}

int DeQueue(struct node **ppHead)
{
    int iDeQuedData;
    struct node *pTemp = NULL;

    if (IsQueueEmpty(*ppHead))
    {
        printf("\nQueue is empty\n");
        return -1;
    }

    pTemp = *ppHead;

    *ppHead = pTemp->pNext;

    iDeQuedData = pTemp->iData;
    free(pTemp);
    return iDeQuedData;
}

int IsQueueFull(struct node *pHead)
{
    if (CountNodes(pHead) == MAX)
        return 1;
    return 0;
}

int IsQueueEmpty(struct node *pHead)
{
    if (NULL == pHead)
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
        printf("|%d|", pHead->iData);
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

// Output

// Queue is
// |10||20||30||40|

// Dequed data is: 10

// Queue after dequeue is
// |20||30||40|

// Queste after free
// Queue is empty
