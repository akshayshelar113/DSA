#include <stdio.h>
#include <malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};

void ConcatAtPosition(struct node **, struct node **, int);
void ConcateList(struct node **, struct node **);
void InsertLast(struct node **, int);
void Display(struct node *);
void DeleteAll(struct node **);

int main(void)
{
    struct node *pFirst = NULL;
    struct node *pSecond = NULL;

    InsertLast(&pFirst, 10);
    InsertLast(&pFirst, 20);
    InsertLast(&pFirst, 30);
    InsertLast(&pFirst, 40);
    printf("First List is\n");
    Display(pFirst);                     // |10|->|20|->|30|->|40|->

    InsertLast(&pSecond, 50);
    InsertLast(&pSecond, 60);
    InsertLast(&pSecond, 70);
    printf("\n\nSecond List is\n");
    Display(pSecond);                       // |50|->|60|->|70|->

    ConcatAtPosition(&pFirst, &pSecond, 2);
    printf("\n\nConcated list at position 2 is\n");
    Display(pFirst);                                 // |10|->|50|->|60|->|70|->|20|->|30|->|40|->

    if (pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }

    if (pSecond != NULL)
    {
        DeleteAll(&pSecond);
        pSecond = NULL;
    }

    printf("\n\nList after Deletion\n");
    Display(pFirst); // List is empty
    Display(pSecond); // List is empty

    return 0;
}

void ConcatAtPosition(struct node **ppHead1, struct node **ppHead2, int iPos)
{
    int iCount;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    iCount = CountNodes(*ppHead1);

    if (iPos <= 0 || iPos > iCount + 1)
    {
        printf("\n\nInvalid position");
        return;
    }

    if (NULL == *ppHead2)
        return;

    if (iPos == 1)
    {
        ConcateList(ppHead2, ppHead1);
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;
        return;
    }

    // if (iPos == iCount + 1)
    // {
    //     ConcateList(ppHead1, ppHead2);
    //     return;
    // }

    pTemp1 = *ppHead1;
    iCount = 1;

    while (iCount < iPos - 1)
    {
        iCount++;
        pTemp1 = pTemp1->pNext;
    }

    pTemp2 = *ppHead2;

    while (pTemp2->pNext != NULL)
        pTemp2 = pTemp2->pNext;

    pTemp2->pNext = pTemp1->pNext;
    pTemp1->pNext = *ppHead2;

    *ppHead2 = NULL;
}

void ConcateList(struct node **ppHead1, struct node **ppHead2)
{
    struct node *pTemp = NULL;

    if (NULL == *ppHead2)
        return;

    if (NULL == *ppHead1)
    {
        *ppHead1 = *ppHead2;
        *ppHead1 = NULL;
        return;
    }

    pTemp = *ppHead1;

    while (pTemp->pNext != NULL)
        pTemp = pTemp->pNext;

    pTemp->pNext = *ppHead2;
    *ppHead2 = NULL;
}

void InsertLast(struct node **ppHead, int iNo)
{
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("Memory allocaion fail");
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
        printf("\nList is Empty\n");
        return;
    }
    while (pHead != NULL)
    {
        printf("|%d|->", pHead->iData);

        pHead = pHead->pNext;
    }
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

//    Output

// First List is
// |10|->|20|->|30|->|40|->

// Second List is
// |50|->|60|->|70|->

// Concated list at position 2 is
// |10|->|50|->|60|->|70|->|20|->|30|->|40|->

// List after Deletion

// List is Empty