#include <stdio.h>
#include <malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};

void InsertLast(struct node **, int);
void Display(struct node *);
int SearchLastOccurrence(struct node *, int);
void DeleteAll(struct node **);

int main(void)
{
    int iPos, iKey;
    struct node *pFirst = NULL;

    InsertLast(&pFirst, 10);
    InsertLast(&pFirst, 20);
    InsertLast(&pFirst, 30);
    InsertLast(&pFirst, 40);
    InsertLast(&pFirst, 50);
    InsertLast(&pFirst, 30);

    Display(pFirst);                            //|10|->|20|->|30|->|40|->|50|->|30|->

    iKey = 30;
    iPos = SearchLastOccurrence(pFirst, iKey);
    printf("\nLast position of key in list is: %d", iPos);   //Last position of key in list is: 6

    if (pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }

    printf("\n\nList after Deletion\n");
    Display(pFirst);                        // List is empty

    return 0;
}

void InsertLast(struct node **ppHead, int iNo)
{
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;

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
        *ppHead = pNewNode;
        return;
    }

    pTemp = *ppHead;

    while (pTemp->pNext != NULL)
        pTemp = pTemp->pNext;

    pTemp->pNext = pNewNode;
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

int SearchLastOccurrence(struct node *pHead, int iKey)
{
    int iPos = 0, iLastOccurrence = 0;

    while (pHead != NULL)
    {
        iPos++;
        if (pHead->iData == iKey)
            iLastOccurrence = iPos;

        pHead = pHead->pNext;
    }
    return iLastOccurrence;
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
