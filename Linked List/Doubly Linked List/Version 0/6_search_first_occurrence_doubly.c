#include <stdio.h>
#include <malloc.h>

struct node
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **, int);
void Display(struct node *);
int SearchFirstOccurrence(struct node *, int);
void DeleteAll(struct node **);

int main(void)
{
    int iPos, iKey;
    struct node *pFirst = NULL;

    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 30);
    InsertFirst(&pFirst, 40);
    InsertFirst(&pFirst, 20);

    Display(pFirst); //|20|<->|40|<->|30|<->|20|<->|10|<->

    iKey = 20;
    iPos = SearchFirstOccurrence(pFirst, iKey);

    if (iPos == 0)
        printf("\nKey not found in list");

    else
        printf("\nKey found at postion: %d", iPos); ////Key found at postion: 1

    if (pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }

    printf("\n\nList after Deletion\n");
    Display(pFirst); // List is empty

    return 0;
}

void InsertFirst(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("memory allocation fail");
        return;
    }

    pNewNode->iData = iNo;
    pNewNode->pPrev = NULL;

    if (NULL == *ppHead)
    {
        pNewNode->pNext = NULL;
        *ppHead = pNewNode;
        return;
    }

    pNewNode->pNext = *ppHead;
    (*ppHead)->pPrev = pNewNode;
    *ppHead = pNewNode;
}

void Display(struct node *pHead)
{
    if (NULL == pHead)
    {
        printf("List is empty");
        return;
    }

    while (pHead != NULL)
    {
        printf("|%d|<->", pHead->iData);
        pHead = pHead->pNext;
    }
}

int SearchFirstOccurrence(struct node *pHead, int iKey)
{
    int iPos = 0;

    while (pHead != NULL)
    {
        iPos++;
        if (pHead->iData == iKey)
            return iPos;

        pHead = pHead->pNext;
    }
    return 0;
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