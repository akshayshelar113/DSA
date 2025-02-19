#include <stdio.h>
#include <malloc.h>

struct node
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void Display(struct node *);
int CountNodes(struct node *);
void DeleteAll(struct node **);
int DeleteLast(struct node **);
int DeleteFirst(struct node **);
void ReverseDisplay(struct node *);
void InsertLast(struct node **, int);
void PhysicalReverse(struct node **);
void InsertFirst(struct node **, int);
int DeleteAtPosition(struct node **, int);
int SearchLastOccurance(struct node *, int);
int SearchAllOccurances(struct node *, int);
int SearchFirstOccurance(struct node *, int);
void InsertAtPosition(struct node **, int, int);
void ConcatList(struct node **, struct node **);
void ConcatAtPosition(struct node **, struct node **, int);

int main(void)
{
    int iData;
    struct node *pFirst = NULL;
    struct node *pSecond = NULL;
    Display(pFirst);

    InsertFirst(&pFirst, 30);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 10);
    printf("\nInsert First\n");
    Display(pFirst);

    InsertLast(&pFirst, 40);
    InsertLast(&pFirst, 10);
    InsertLast(&pFirst, 60);
    printf("\n\nInsert Last\n");
    Display(pFirst);

    InsertAtPosition(&pFirst, 10, 4);
    printf("\n\nInsert %d at position %d\n", 10, 4);
    Display(pFirst);

    iData = DeleteFirst(&pFirst);
    if (iData != -1)
        printf("\n\nDeleted data from first position is: %d\n", iData);
    Display(pFirst);

    iData = DeleteLast(&pFirst);
    if (iData != -1)
        printf("\n\nDeleted data from first position is: %d\n", iData);
    Display(pFirst);

    iData = DeleteAtPosition(&pFirst, 2);
    if (iData != -1)
        printf("\n\nDeleted data from position %d is: %d\n", 2, iData);
    Display(pFirst);

    iData = SearchFirstOccurance(pFirst, 10);
    if (iData != -1)
        printf("\n\nFirst occurance of key %d is at %d position in below list\n", 10, iData);
    Display(pFirst);

    iData = SearchLastOccurance(pFirst, 10);
    if (iData != 0)
        printf("\n\nLast occurance of Key %d is at %d position in below list list\n", 10, iData);
    Display(pFirst);

    iData = SearchAllOccurances(pFirst, 10);
    if (iData != 0)
        printf("\n\nAll occurance of Key %d in list is %d\n", 10, iData);
    Display(pFirst);

    PhysicalReverse(&pFirst);
    printf("\n\nPhysically reversed list is\n");
    Display(pFirst);

    PhysicalReverse(&pFirst);
    printf("\n\nOriginal list is\n");
    Display(pFirst);

    printf("\n\nReverse Display list is\n");
    ReverseDisplay(pFirst);
    printf("\nOriginal list is\n");
    Display(pFirst);

    InsertLast(&pSecond, 100);
    InsertLast(&pSecond, 200);
    InsertLast(&pSecond, 300);
    printf("\n\nSecond list is\n");
    Display(pSecond);

    ConcatList(&pFirst, &pSecond);
    printf("\n\nConcated list is\n");
    Display(pFirst);
    printf("\nSecond list is");
    Display(pSecond);

    InsertLast(&pSecond, 400);
    InsertLast(&pSecond, 500);
    InsertLast(&pSecond, 600);
    printf("\nNew Second list is\n");
    Display(pSecond);

    printf("\n\nConcated list at position %d is\n", 3);
    ConcatAtPosition(&pFirst, &pSecond, 3);
    Display(pFirst);
    printf("\nSecond list is\n");
    Display(pSecond);

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
    printf("\n\nFirst list after delete all is\n");
    Display(pFirst);
    printf("\nSecond list after delete all is\n");
    Display(pSecond);

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

void InsertLast(struct node **ppHead, int iNo)
{
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("Memory  allocation failed");
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

void InsertAtPosition(struct node **ppHead, int iNo, int iPos)
{
    int iCount;

    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;

    iCount = CountNodes(*ppHead);

    if (iPos <= 0 || iPos > iCount + 1)
    {
        printf("Invalid position");
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(ppHead, iNo);
        return;
    }

    if (iPos == iCount + 1)
    {
        InsertLast(ppHead, iNo);
        return;
    }

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("Memory allocation failed");
        return;
    }

    pNewNode->iData = iNo;

    pTemp = *ppHead;
    iCount = 1;
    while (iCount < iPos - 1)
    {
        iCount++;
        pTemp = pTemp->pNext;
    }

    pNewNode->pNext = pTemp->pNext;
    pTemp->pNext->pPrev = pNewNode;
    pTemp->pNext = pNewNode;
    pNewNode->pPrev = pTemp;
}

int DeleteFirst(struct node **ppHead)
{
    int iDelData;

    if (NULL == *ppHead)
        return -1;

    iDelData = (*ppHead)->iData;

    if (NULL == (*ppHead)->pNext)
    {
        free(*ppHead);
        *ppHead = NULL;
    }
    else
    {
        *ppHead = (*ppHead)->pNext;
        free((*ppHead)->pPrev);
        (*ppHead)->pPrev = NULL;
    }

    return iDelData;
}

int DeleteLast(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp = NULL;

    if (NULL == *ppHead)
        return -1;

    pTemp = *ppHead;

    if (NULL == pTemp->pNext)
    {
        *ppHead = NULL;
    }
    else
    {
        while (pTemp->pNext != NULL)
            pTemp = pTemp->pNext;

        pTemp->pPrev->pNext = NULL;
    }
    iDelData = pTemp->iData;
    free(pTemp);
    return iDelData;
}

int DeleteAtPosition(struct node **ppHead, int iPos)
{
    int iCount;
    struct node *pTemp = NULL;

    iCount = CountNodes(*ppHead);

    if (iPos <= 0 || iPos > iCount)
    {
        printf("\nInvalid position\n");
        return -1;
    }

    if (iPos == 1)
    {
        return DeleteFirst(ppHead);
    }

    if (iPos == iCount)
    {
        return DeleteLast(ppHead);
    }

    pTemp = *ppHead;
    iCount = 1;

    while (iCount < iPos)
    {
        iCount++;
        pTemp = pTemp->pNext;
    }

    iCount = pTemp->iData;
    pTemp->pPrev->pNext = pTemp->pNext;
    pTemp->pNext->pPrev = pTemp->pPrev;
    pTemp->pPrev = NULL;
    pTemp->pNext = NULL;
    free(pTemp);

    return iCount;
}

int SearchFirstOccurance(struct node *pHead, int iKey)
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

int SearchLastOccurance(struct node *pHead, int iKey)
{
    int iPos = 0;
    int iCounter = 0;

    while (pHead != NULL)
    {
        iPos++;
        if (pHead->iData == iKey)
            iCounter = iPos;

        pHead = pHead->pNext;
    }

    return iCounter;
}

int SearchAllOccurances(struct node *pHead, int iKey)
{
    int iAllOccurences = 0;

    while (pHead != NULL)
    {
        if (pHead->iData == iKey)
            iAllOccurences++;

        pHead = pHead->pNext;
    }

    return iAllOccurences;
}

void PhysicalReverse(struct node **ppHead)
{
    struct node *pPrev = NULL;
    struct node *pCurrent = *ppHead;
    struct node *pNext = NULL;

    while (pCurrent != NULL)
    {
        pNext = pCurrent->pNext;
        pCurrent->pNext = pPrev;
        pCurrent->pPrev = pNext;
        pPrev = pCurrent;
        pCurrent = pNext;
    }

    *ppHead = pPrev;
}

void ReverseDisplay(struct node *pHead)
{
    if (NULL == pHead)
    {
        printf("List is empty");
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

void ConcatList(struct node **ppHead1, struct node **ppHead2)
{
    struct node *pTemp = NULL;

    if (NULL == *ppHead2)
        return;

    if (NULL == *ppHead1)
    {
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;
        return;
    }

    pTemp = *ppHead1;

    while (pTemp->pNext != NULL)
        pTemp = pTemp->pNext;

    pTemp->pNext = *ppHead2;
    (*ppHead2)->pPrev = pTemp;
    *ppHead2 = NULL;
}

void ConcatAtPosition(struct node **ppHead1, struct node **ppHead2, int iPos)
{
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;
    int iCount;

    iCount = CountNodes(*ppHead1);

    if (iPos <= 0 || iPos > iCount + 1)
    {
        printf("\n\nInalid position\n");
        return;
    }

    if (NULL == *ppHead2)
        return;

    if (NULL == *ppHead1)
    {
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;
        return;
    }

    if (iPos == 1)
    {
        ConcatList(ppHead2, ppHead1);
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;
        return;
    }

    if (iPos == iCount + 1)
    {
        ConcatList(ppHead1, ppHead2);
        return;
    }

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
    pTemp1->pNext->pPrev = pTemp2;
    pTemp1->pNext = *ppHead2;
    (*ppHead2)->pPrev = pTemp1;

    *ppHead2 = NULL;
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
        printf("List is empty\n");
        return;
    }

    while (pHead != NULL)
    {
        printf("|%d|<->", pHead->iData);
        pHead = pHead->pNext;
    }
}

// Output

// List is empty

// Insert First
// |10|<->|20|<->|30|<->

// Insert Last
// |10|<->|20|<->|30|<->|40|<->|10|<->|60|<->

// Insert 10 at position 4
// |10|<->|20|<->|30|<->|10|<->|40|<->|10|<->|60|<->

// Deleted data from first position is: 10
// |20|<->|30|<->|10|<->|40|<->|10|<->|60|<->

// Deleted data from first position is: 60
// |20|<->|30|<->|10|<->|40|<->|10|<->

// Deleted data from position 2 is: 30
// |20|<->|10|<->|40|<->|10|<->

// First occurance of key 10 is at 2 position in below list
// |20|<->|10|<->|40|<->|10|<->

// Last occurance of Key 10 is at 4 position in below list list
// |20|<->|10|<->|40|<->|10|<->

// All occurance of Key 10 in list is 2
// |20|<->|10|<->|40|<->|10|<->

// Physically reversed list is
// |10|<->|40|<->|10|<->|20|<->

// Original list is
// |20|<->|10|<->|40|<->|10|<->

// Reverse Display list is
// |10|<->|40|<->|10|<->|20|<->
// Original list is
// |20|<->|10|<->|40|<->|10|<->

// Second list is
// |100|<->|200|<->|300|<->

// Concated list is
// |20|<->|10|<->|40|<->|10|<->|100|<->|200|<->|300|<->
// Second list isList is empty

// New Second list is
// |400|<->|500|<->|600|<->

// Concated list at position 3 is
// |20|<->|10|<->|400|<->|500|<->|600|<->|40|<->|10|<->|100|<->|200|<->|300|<->
// Second list is
// List is empty


// First list after delete all is
// List is empty

// Second list after delete all is
// List is empty