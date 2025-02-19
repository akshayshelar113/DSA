#include <stdio.h>
#include <malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **, int);
void InsertLast(struct node **, int);
void InserAtPosition(struct node **, int, int);

int DeleteFirst(struct node **);
int DeleteLast(struct node **);
int DeleteAtPosition(struct node **, int);

int SearchFirstOccurrrence(struct node *, int);
int SearchLastOccurrrence(struct node *, int);
int SearchAllOccurrences(struct node *, int);

void PhysicalReverse(struct node **);
void ReverseDisplay(struct node *);

void ConcatList(struct node **, struct node **);
void ConcatAtPosition(struct node **, struct node **, int);

void Display(struct node *);
int CountNodes(struct node *);
void DeleteAll(struct node **);

int main(void)
{
    int iNumber;
    struct node *pFirst = NULL;
    struct node *pSecond = NULL;

    Display(pFirst);

    InsertFirst(&pFirst, 30);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 20);
    printf("\nAfter Insert First\n");
    Display(pFirst);

    InsertLast(&pFirst, 40);
    InsertLast(&pFirst, 50);
    InsertLast(&pFirst, 20);
    InsertLast(&pFirst, 60);
    printf("\n\nAfter Insert Last\n");
    Display(pFirst);

    InserAtPosition(&pFirst, 70, 3);
    printf("\n\nInsert %d at position %d", 70, 3);
    printf("\nAfter Insert at position\n");
    Display(pFirst);

    iNumber = DeleteFirst(&pFirst);
    if (iNumber != -1)
        printf("\n\nDeleted data from first position is: %d\n", iNumber);
    printf("Updated list is\n");
    Display(pFirst);

    iNumber = DeleteLast(&pFirst);
    if (iNumber != -1)
        printf("\n\nDeleted data from last position is: %d\n", iNumber);
    printf("Updated list is\n");
    Display(pFirst);

    iNumber = DeleteAtPosition(&pFirst, 2);
    if (iNumber != -1)
        printf("\n\nDeleted data At Position %d is: %d\n", 2, iNumber);
    printf("Updated list is\n");
    Display(pFirst);

    iNumber = SearchFirstOccurrrence(pFirst, 20);
    if (iNumber != 0)
        printf("\n\nFirst occurance of %d at %d position\n", 20, iNumber);

    iNumber = SearchLastOccurrrence(pFirst, 20);
    if (iNumber != 0)
        printf("\nLast occurance of %d at %d position\n", 20, iNumber);

    iNumber = SearchAllOccurrences(pFirst, 20);
    if (iNumber != 0)
        printf("\n%d Found %d times\n", 20, iNumber);

    Display(pFirst);

    iNumber = CountNodes(pFirst);
    printf("\n\nTotal Node count is: %d", iNumber);

    PhysicalReverse(&pFirst);
    printf("\n\nReversed List is\n");
    Display(pFirst);
    PhysicalReverse(&pFirst);
    printf("\n\nReversed List is\n");
    Display(pFirst);
    printf("\n\nReverse Display\n");
    ReverseDisplay(pFirst);
    printf("\n\nList after Reverse display\n");
    Display(pFirst);

    InsertLast(&pSecond, 100);
    InsertLast(&pSecond, 200);
    InsertLast(&pSecond, 300);
    printf("\n\nSecond List is\n");
    Display(pSecond);

    ConcatList(&pFirst, &pSecond);
    printf("\n\nConcated list is\n");
    Display(pFirst);
    printf("\n\nSecond list after Concat List\n");
    Display(pSecond);

    InsertLast(&pSecond, 400);
    InsertLast(&pSecond, 500);
    InsertLast(&pSecond, 600);
    printf("\nNew Second list is\n");
    Display(pSecond);

    ConcatAtPosition(&pFirst, &pSecond, 3);
    printf("\n\nConcated list at position %d\n", 3);
    Display(pFirst);
    printf("\nSecond list after concat at position\n");
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

    printf("\npFirst after Delete All\n");
    Display(pSecond);
    printf("\npSecond after Delete All\n");
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

    if (NULL == *ppHead)
    {
        pNewNode->pNext = NULL;
        *ppHead = pNewNode;
        return;
    }

    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
}

void InsertLast(struct node **ppHead, int iNo)
{
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("Memoru allocation failed");
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

void InserAtPosition(struct node **ppHead, int iNo, int iPos)
{
    int iCount;

    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;

    iCount = CountNodes(*ppHead);

    if (iPos <= 0 || iPos > iCount + 1)
    {
        printf("Invalid Position");
        return;
    }

    if (1 == iPos)
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
        printf("Memory allocation fail");
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
    pTemp->pNext = pNewNode;
}

int DeleteFirst(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp = NULL;

    if (NULL == *ppHead)
        return -1;

    pTemp = *ppHead;
    *ppHead = pTemp->pNext;

    iDelData = pTemp->iData;
    pTemp->pNext = NULL;
    free(pTemp);

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
        iDelData = pTemp->iData;
        free(pTemp);
        *ppHead = NULL;
    }
    else
    {

        while (pTemp->pNext->pNext != NULL)
            pTemp = pTemp->pNext;

        iDelData = pTemp->pNext->iData;
        free(pTemp->pNext);
        pTemp->pNext = NULL;
    }
    return iDelData;
}

int DeleteAtPosition(struct node **ppHead, int iPos)
{
    int iCount;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    iCount = CountNodes(*ppHead);

    if (iPos <= 0 || iPos > iCount)
    {
        printf("Invalid Position");
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

    pTemp1 = *ppHead;
    iCount = 1;

    while (iCount < iPos - 1)
    {
        iCount++;
        pTemp1 = pTemp1->pNext;
    }

    pTemp2 = pTemp1->pNext;

    pTemp1->pNext = pTemp2->pNext;
    iCount = pTemp2->iData;
    pTemp2->pNext = NULL;
    free(pTemp2);

    return iCount;
}

int SearchFirstOccurrrence(struct node *pHead, int iKey)
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

int SearchLastOccurrrence(struct node *pHead, int iKey)
{
    int iPos = 0, iLastOccurance = 0;

    while (pHead != NULL)
    {
        iPos++;
        if (pHead->iData == iKey)
            iLastOccurance = iPos;

        pHead = pHead->pNext;
    }
    return iLastOccurance;
}

int SearchAllOccurrences(struct node *pHead, int iKey)
{
    int iCount = 0;

    while (pHead != NULL)
    {
        if (pHead->iData == iKey)
            iCount++;

        pHead = pHead->pNext;
    }

    return iCount;
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

    PhysicalReverse(&pHead);
    Display(pHead);
    PhysicalReverse(&pHead);
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
    *ppHead2 = NULL;
}

void ConcatAtPosition(struct node **ppHead1, struct node **ppHead2, int iPos)
{
    int iCount;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    iCount = CountNodes(*ppHead1);

    if (iPos <= 0 || iPos > iCount + 1)
    {
        printf("\nInvalid position\n");
        return;
    }

    if (NULL == *ppHead2)
        return;

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
        *ppHead2 = NULL;
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
    pTemp1->pNext = *ppHead2;
    *ppHead2 = NULL;
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
        printf("|%d|->", pHead->iData);
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

// output

// List is empty

// After Insert First
// |20|->|10|->|20|->|30|->

// After Insert Last
// |20|->|10|->|20|->|30|->|40|->|50|->|20|->|60|->

// Insert 70 at position 3
// After Insert at position
// |20|->|10|->|70|->|20|->|30|->|40|->|50|->|20|->|60|->

// Deleted data from first position is: 20
// Updated list is
// |10|->|70|->|20|->|30|->|40|->|50|->|20|->|60|->

// Deleted data from last position is: 60
// Updated list is
// |10|->|70|->|20|->|30|->|40|->|50|->|20|->

// Deleted data At Position 2 is: 70
// Updated list is
// |10|->|20|->|30|->|40|->|50|->|20|->

// First occurance of 20 at 2 position

// Last occurance of 20 at 6 position

// 20 Found 2 times
// |10|->|20|->|30|->|40|->|50|->|20|->

// Total Node count is: 6

// Reversed List is
// |20|->|50|->|40|->|30|->|20|->|10|->

// Reversed List is
// |10|->|20|->|30|->|40|->|50|->|20|->

// Reverse Display
// |20|->|50|->|40|->|30|->|20|->|10|->

// List after Reverse display
// |10|->|20|->|30|->|40|->|50|->|20|->

// Second List is
// |100|->|200|->|300|->

// Concated list is
// |10|->|20|->|30|->|40|->|50|->|20|->|100|->|200|->|300|->

// Second list after Concat List
// List is empty

// New Second list is
// |400|->|500|->|600|->

// Concated list at position 3
// |10|->|20|->|400|->|500|->|600|->|30|->|40|->|50|->|20|->|100|->|200|->|300|->
// Second list after concat at position
// List is empty

// pFirst after Delete All
// List is empty

// pSecond after Delete All
// List is empty