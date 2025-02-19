#include <stdio.h>
#include <malloc.h>

struct node
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void Display(struct node *, struct node *);
int CountNodes(struct node *, struct node *);
int DeleteLast(struct node **, struct node **);
void DeleteAll(struct node **, struct node **);
int DeleteFirst(struct node **, struct node **);
void InsertLast(struct node **, struct node **, int);
void InsertFirst(struct node **, struct node **, int);
int DeleteAtPosition(struct node **, struct node **, int);
int SearchLastOccurance(struct node *, struct node *, int);
int SearchAllOccurances(struct node *, struct node *, int);
int SearchFirstOccurance(struct node *, struct node *, int);
void InsertAtPosition(struct node **, struct node **, int, int);
void PhysicalReverse(struct node **, struct node **);
void ReverseDisplay(struct node *, struct node *);
void ConcatList(struct node **, struct node **, struct node **, struct node **);
void ConcatAtPosition(struct node **, struct node **, struct node **, struct node **, int);

int main(void)
{
    int iCount;
    struct node *pFirst1 = NULL;
    struct node *pLast1 = NULL;

    struct node *pFirst2 = NULL;
    struct node *pLast2 = NULL;

    InsertFirst(&pFirst1, &pLast1, 40);
    InsertFirst(&pFirst1, &pLast1, 30);
    InsertFirst(&pFirst1, &pLast1, 20);
    InsertFirst(&pFirst1, &pLast1, 10);
    printf("\nInsert First is\n");
    Display(pFirst1, pLast1);

    InsertLast(&pFirst1, &pLast1, 50);
    InsertLast(&pFirst1, &pLast1, 60);
    InsertLast(&pFirst1, &pLast1, 20);
    InsertLast(&pFirst1, &pLast1, 70);
    InsertLast(&pFirst1, &pLast1, 80);
    printf("\n\nInsert Last is\n");
    Display(pFirst1, pLast1);

    InsertAtPosition(&pFirst1, &pLast1, 90, 3);
    printf("\n\nInsert node at position %d\n", 3);
    Display(pFirst1, pLast1);

    iCount = CountNodes(pFirst1, pLast1);
    printf("\n\nNo of nodes in list is:%d", iCount);

    iCount = DeleteFirst(&pFirst1, &pLast1);
    if (iCount != -1)
        printf("\n\nDeleted data from first is:%d\n", iCount);
    Display(pFirst1, pLast1);

    iCount = DeleteLast(&pFirst1, &pLast1);
    if (iCount != -1)
        printf("\n\nDeletd data from last is:%d\n", iCount);
    Display(pFirst1, pLast1);

    iCount = DeleteAtPosition(&pFirst1, &pLast1, 4);
    if (iCount != -1)
        printf("\n\nDeletd data at position %d is:%d\n", 4, iCount);
    Display(pFirst1, pLast1);

    iCount = SearchFirstOccurance(pFirst1, pLast1, 20);
    if (iCount != 0)
        printf("\n\nFirst occurance of Key %d is found at position:%d\n", 20, iCount);
    Display(pFirst1, pLast1);

    iCount = SearchLastOccurance(pFirst1, pLast1, 20);
    if (iCount != 0)
        printf("\n\nLast occurance of Key %d is found at position:%d\n", 20, iCount);
    Display(pFirst1, pLast1);

    iCount = SearchAllOccurances(pFirst1, pLast1, 20);
    if (iCount != 0)
        printf("\n\nAll occurances of Key %d in list is:%d\n", 20, iCount);
    Display(pFirst1, pLast1);

    PhysicalReverse(&pFirst1, &pLast1);
    printf("\n\nPhysical Reverse list is\n");
    Display(pFirst1, pLast1);
    PhysicalReverse(&pFirst1, &pLast1);
    printf("\nOriginal list is\n");
    Display(pFirst1, pLast1);

    printf("\n\nReverse display is\n");
    ReverseDisplay(pFirst1, pLast1);
    printf("\nOriginal list is\n");
    Display(pFirst1, pLast1);

    InsertLast(&pFirst2, &pLast2, 100);
    InsertLast(&pFirst2, &pLast2, 200);
    InsertLast(&pFirst2, &pLast2, 300);
    printf("\n\nSecond list is\n");
    Display(pFirst2, pLast2);

    ConcatList(&pFirst1, &pLast1, &pFirst2, &pLast2);
    printf("\n\nConcated list is\n");
    Display(pFirst1, pLast1);
    printf("\nSecond list is");
    Display(pFirst2, pLast2);

    InsertLast(&pFirst2, &pLast2, 400);
    InsertLast(&pFirst2, &pLast2, 500);
    InsertLast(&pFirst2, &pLast2, 600);
    printf("\n\nNew second list is\n");
    Display(pFirst2, pLast2);

    ConcatAtPosition(&pFirst1, &pLast1, &pFirst2, &pLast2, 3);
    printf("\n\nConcated list at position %d is\n", 3);
    Display(pFirst1, pLast1);
    printf("\nSecond list is");
    Display(pFirst2, pLast2);

    if (pFirst1 != NULL)
    {
        DeleteAll(&pFirst1, &pLast1);
        pFirst1 = pLast1 = NULL;
    }

    if (pFirst2 != NULL)
    {
        DeleteAll(&pFirst2, &pLast2);
        pFirst2 = pLast2 = NULL;
    }

    printf("\n\nAfter deletion all nodes\n");
    printf("First list is");
    Display(pFirst1, pLast1);
    printf("Second list is");
    Display(pFirst2, pLast2);

    return 0;
}

void InsertFirst(struct node **ppHead, struct node **ppTail, int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("Memory allocation failed");
        return;
    }

    pNewNode->iData = iNo;

    if (NULL == *ppHead)
    {
        *ppHead = pNewNode;
        *ppTail = pNewNode;
        (*ppTail)->pNext = *ppHead;
        (*ppHead)->pPrev = *ppTail;

        return;
    }

    pNewNode->pNext = *ppHead;
    (*ppHead)->pPrev = pNewNode;
    *ppHead = pNewNode;
    pNewNode->pPrev = *ppTail;
    (*ppTail)->pNext = *ppHead;
}

void InsertLast(struct node **ppHead, struct node **ppTail, int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("Memory allocation failed");
        return;
    }

    pNewNode->iData = iNo;

    if (NULL == *ppHead)
    {
        *ppHead = pNewNode;
        *ppTail = pNewNode;

        (*ppHead)->pPrev = *ppTail;
        (*ppTail)->pNext = *ppHead;

        return;
    }

    (*ppTail)->pNext = pNewNode;
    pNewNode->pPrev = *ppTail;
    *ppTail = pNewNode;

    (*ppTail)->pNext = *ppHead;
    (*ppHead)->pPrev = *ppTail;
}

void InsertAtPosition(struct node **ppHead, struct node **ppTail, int iNo, int iPos)
{
    int iCounter;
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;

    iCounter = CountNodes(*ppHead, *ppTail);

    if (iPos <= 0 || iPos > iCounter + 1)
    {
        printf("\nInvalid position\n");
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(ppHead, ppTail, iNo);
        return;
    }

    if (iPos == iCounter + 1)
    {
        InsertLast(ppHead, ppTail, iNo);
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
    iCounter = 1;

    while (iCounter < iPos - 1)
    {
        iCounter++;
        pTemp = pTemp->pNext;
    }

    pNewNode->pNext = pTemp->pNext;
    pTemp->pNext->pPrev = pNewNode;
    pTemp->pNext = pNewNode;
    pNewNode->pPrev = pTemp;
}

int DeleteFirst(struct node **ppHead, struct node **ppTail)
{
    int iDelData;

    if (NULL == *ppHead)
        return -1;

    iDelData = (*ppHead)->iData;

    if (*ppTail == *ppHead)
    {
        free(*ppHead);
        (*ppHead)->pNext = (*ppHead)->pPrev = NULL;
        *ppHead = *ppTail = NULL;
    }
    else
    {
        *ppHead = (*ppHead)->pNext;
        (*ppHead)->pPrev->pPrev = NULL;
        (*ppHead)->pPrev->pNext = NULL;
        free((*ppHead)->pPrev);

        (*ppHead)->pPrev = *ppTail;
        (*ppTail)->pNext = *ppHead;
    }

    return iDelData;
}

int DeleteLast(struct node **ppHead, struct node **ppTail)
{
    int iDelData;

    if (NULL == *ppHead)
        return -1;

    iDelData = (*ppTail)->iData;

    if (*ppHead == *ppTail)
    {
        free(*ppHead);
        *ppHead = *ppTail = NULL;
    }
    else
    {
        (*ppTail)->pNext = NULL;
        *ppTail = (*ppTail)->pPrev;
        free((*ppTail)->pNext);
        (*ppHead)->pPrev = *ppTail;
        (*ppTail)->pNext = *ppHead;
    }

    return iDelData;
}

int DeleteAtPosition(struct node **ppHead, struct node **ppTail, int iPos)
{
    int iCounter;
    struct node *pTemp = NULL;

    iCounter = CountNodes(*ppHead, *ppTail);

    if (iPos <= 0 || iPos > iCounter)
    {
        printf("Position is invalid");
        return -1;
    }

    if (iPos == 1)
    {
        return DeleteFirst(ppHead, ppTail);
    }

    if (iPos == iCounter)
    {
        return DeleteLast(ppHead, ppTail);
    }

    pTemp = *ppHead;
    iCounter = 1;

    while (iCounter < iPos)
    {
        iCounter++;
        pTemp = pTemp->pNext;
    }

    pTemp->pNext->pPrev = pTemp->pPrev;
    pTemp->pPrev->pNext = pTemp->pNext;
    iCounter = pTemp->iData;
    free(pTemp);

    return iCounter;
}

int SearchFirstOccurance(struct node *pHead, struct node *pTail, int iKey)
{
    int iCounter = 0;

    if (NULL == pHead)
        return 0;

    do
    {
        iCounter++;
        if (pHead->iData == iKey)
            return iCounter;
        pHead = pHead->pNext;
    } while (pHead != pTail->pNext);

    return 0;
}

int SearchLastOccurance(struct node *pHead, struct node *pTail, int iKey)
{
    int iPos = 0, iLastOccurance = 0;
    ;

    if (NULL == pHead)
        return 0;

    do
    {
        iPos++;
        if (pHead->iData == iKey)
            iLastOccurance = iPos;

        pHead = pHead->pNext;
    } while (pHead != pTail->pNext);

    return iLastOccurance;
}

int SearchAllOccurances(struct node *pHead, struct node *pTail, int iKey)
{
    int iCounter = 0;

    if (NULL == pHead)
        return 0;

    do
    {
        if (pHead->iData == iKey)
            iCounter++;

        pHead = pHead->pNext;
    } while (pHead != pTail->pNext);

    return iCounter;
}

void PhysicalReverse(struct node **ppHead, struct node **ppTail)
{
    struct node *pPrev = *ppTail;
    struct node *pCurrent = *ppHead;
    struct node *pNext = NULL;

    if (NULL == *ppHead)
        return;

    do
    {
        pNext = pCurrent->pNext;
        pCurrent->pNext = pPrev;
        pCurrent->pPrev = pNext;
        pPrev = pCurrent;
        pCurrent = pNext;

    } while (pCurrent != *ppHead);

    *ppHead = pPrev;
    *ppTail = pCurrent;
}

void ReverseDisplay(struct node *pHead, struct node *pTail)
{
    if (NULL == pHead)
    {
        printf("List is empty");
        return;
    }

    pHead->pPrev = NULL;

    do
    {
        printf("|%d|<->", pTail->iData);
        pTail = pTail->pPrev;
    } while (pTail != NULL);
}

void ConcatList(struct node **ppHead1, struct node **ppTail1, struct node **ppHead2, struct node **ppTail2)
{
    if (NULL == *ppHead2)
        return;

    if (NULL == *ppHead1)
    {
        *ppHead1 = *ppHead2;
        *ppTail1 = *ppTail2;
        (*ppHead1)->pPrev = *ppTail1;
        (*ppTail1)->pNext = *ppHead1;

        *ppHead2 = *ppTail2 = NULL;
        return;
    }

    (*ppTail1)->pNext = *ppHead2;
    (*ppHead2)->pPrev = *ppTail1;
    *ppTail1 = *ppTail2;
    (*ppTail1)->pNext = *ppHead1;
    (*ppHead1)->pPrev = *ppTail1;

    *ppHead2 = *ppTail2 = NULL;
}

void ConcatAtPosition(struct node **ppHead1, struct node **ppTail1, struct node **ppHead2, struct node **ppTail2, int iPos)
{
    struct node *pTemp = NULL;
    int iCount;

    iCount = CountNodes(*ppHead1, *ppTail1);

    if (iPos <= 0 || iPos > iCount + 1)
    {
        printf("\nInvalid position\n");
        return;
    }

    if (NULL == *ppHead2)
        return;

    if (iPos == 1)
    {
        ConcatList(ppHead2, ppTail2, ppHead1, ppTail1);
        *ppHead1 = *ppHead2;
        *ppTail1 = *ppTail2;

        *ppHead2 = *ppTail2 = NULL;
        return;
    }

    if (iPos == iCount + 1)
    {
        ConcatList(ppHead1, ppTail1, ppHead2, ppTail2);
        return;
    }

    pTemp = *ppHead1;
    iCount = 1;

    while (iCount < iPos - 1)
    {
        iCount++;
        pTemp = pTemp->pNext;
    }

    (*ppTail2)->pNext = pTemp->pNext;
    pTemp->pNext->pPrev = *ppTail2;
    pTemp->pNext = *ppHead2;
    (*ppHead2)->pPrev = pTemp;

    *ppHead2 = *ppTail2 = NULL;
}

int CountNodes(struct node *pHead, struct node *pTail)
{
    int iCount = 0;

    if (NULL == pHead)
        return 0;

    do
    {
        iCount++;
        pHead = pHead->pNext;
    } while (pHead != pTail->pNext);

    return iCount;
}

void Display(struct node *pHead, struct node *pTail)
{
    if (NULL == pHead)
    {
        printf("\nList is empty\n");
        return;
    }

    do
    {
        printf("|%d|<->", pHead->iData);
        pHead = pHead->pNext;
    } while (pHead != (pTail)->pNext);
}

void DeleteAll(struct node **ppHead, struct node **ppTail)
{
    struct node *pTemp = NULL;

    (*ppTail)->pNext = NULL;

    while (*ppHead != NULL)
    {
        pTemp = *ppHead;
        *ppHead = pTemp->pNext;
        free(pTemp);
    }

    *ppTail = NULL;
}

// output

// Insert First is
// |10|<->|20|<->|30|<->|40|<->

// Insert Last is
// |10|<->|20|<->|30|<->|40|<->|50|<->|60|<->|20|<->|70|<->|80|<->

// Insert node at position 3
// |10|<->|20|<->|90|<->|30|<->|40|<->|50|<->|60|<->|20|<->|70|<->|80|<->

// No of nodes in list is:10

// Deleted data from first is:10
// |20|<->|90|<->|30|<->|40|<->|50|<->|60|<->|20|<->|70|<->|80|<->

// Deletd data from last is:80
// |20|<->|90|<->|30|<->|40|<->|50|<->|60|<->|20|<->|70|<->

// Deletd data at position 4 is:40
// |20|<->|90|<->|30|<->|50|<->|60|<->|20|<->|70|<->

// First occurance of Key 20 is found at position:1
// |20|<->|90|<->|30|<->|50|<->|60|<->|20|<->|70|<->

// Last occurance of Key 20 is found at position:6
// |20|<->|90|<->|30|<->|50|<->|60|<->|20|<->|70|<->

// All occurances of Key 20 in list is:2
// |20|<->|90|<->|30|<->|50|<->|60|<->|20|<->|70|<->

// Physical Reverse list is
// |70|<->|20|<->|60|<->|50|<->|30|<->|90|<->|20|<->
// Original list is
// |20|<->|90|<->|30|<->|50|<->|60|<->|20|<->|70|<->

// Reverse display is
// |70|<->|20|<->|60|<->|50|<->|30|<->|90|<->|20|<->
// Original list is
// |20|<->|90|<->|30|<->|50|<->|60|<->|20|<->|70|<->

// Second list is
// |100|<->|200|<->|300|<->

// Concated list is
// |20|<->|90|<->|30|<->|50|<->|60|<->|20|<->|70|<->|100|<->|200|<->|300|<->
// Second list is
// List is empty

// New second list is
// |400|<->|500|<->|600|<->

// Concated list at position 3 is
// |20|<->|90|<->|400|<->|500|<->|600|<->|30|<->|50|<->|60|<->|20|<->|70|<->|100|<->|200|<->|300|<->
// Second list is
// List is empty

// After deletion all nodes
// First list is
// List is empty
// Second list is
// List is empty