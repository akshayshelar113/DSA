#include <stdio.h>
#include <malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **, int);
void Display(struct node *);
int SearchFirstOccurrence(struct node *, int);
void DeleteAll(struct node **);

int main(void)
{
    int ipos, iKey = 20;
    struct node *pFirst = NULL;

    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 30);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 40);

    Display(pFirst); //|40|->|20|->|30|->|20|->|10|->

    ipos = SearchFirstOccurrence(pFirst, iKey);

    if (ipos == 0)
        printf("\nKey not found in list");

    else
        printf("\nKey is at postion: %d", ipos); // Key is at postion: 2

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
        printf("Memory allocation fail");
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

void Display(struct node *pHead)
{
    if (NULL == pHead)
    {
        printf("List is empty");
        return;
    }

    while (pHead != NULL)
    {
        printf("|%d|->", pHead->iData);
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
