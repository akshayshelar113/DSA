#include <stdio.h>
#include <malloc.h>

struct node
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void InsertLast(struct node **, int);
void Display(struct node *);
void ReverseDisplay(struct node *);
void DeleteAll(struct node **);

int main(void)
{
    struct node *pFirst = NULL;

    InsertLast(&pFirst, 10);
    InsertLast(&pFirst, 20);
    InsertLast(&pFirst, 30);
    InsertLast(&pFirst, 40);
    printf("List is\n");
    Display(pFirst);                 //|10|<->|20|<->|30|<->|40|<->

    printf("\n\nReversed List is\n");
    ReverseDisplay(pFirst);            //|40|<->|30|<->|20|<->|10|<->

    printf("\n\nList after reverse display\n");
    Display(pFirst);                 //|10|<->|20|<->|30|<->|40|<->


    if (pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }

    printf("\n\nList after Deletion\n");
    Display(pFirst);                  // List is empty  

    return 0;
}

void ReverseDisplay(struct node *pHead)
{
    if (NULL == pHead)
    {
        printf("\nList is empty\n");
        return;
    }

    while (pHead->pNext != NULL)
        pHead = pHead->pNext;

    while (pHead != NULL)
    {
        printf("|%d|<->", pHead->iData);
        pHead = pHead->pPrev;
    }
}

void InsertLast(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("Memory allocation fail");
        return;
    }

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    if (NULL == *ppHead)
    {
        pNewNode->pPrev = NULL;
        *ppHead = pNewNode;
        return;
    }

    pTemp = *ppHead;
    while (pTemp->pNext != NULL)
        pTemp = pTemp->pNext;

    pTemp->pNext = pNewNode;
    pNewNode->pPrev = pTemp;
}

void Display(struct node *pHead)
{
    if (NULL == pHead)
    {
        printf("\nList is empty\n");
        return;
    }

    while (pHead != NULL)
    {
        printf("|%d|<->", pHead->iData);
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