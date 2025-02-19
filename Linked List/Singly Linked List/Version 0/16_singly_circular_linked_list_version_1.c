#include <stdio.h>
#include <malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};

void Display(struct node *, struct node *);
int CountNodes(struct node *, struct node *);
int DeleteLast(struct node **, struct node **);
void DeleteAll(struct node **, struct node **);
int DeleteFirst(struct node **, struct node **);
void ReverseDisplay(struct node *, struct node *);
void InsertLast(struct node **, struct node **, int);
void PhysicalReverse(struct node **, struct node **);
void InsertFirst(struct node **, struct node **, int);
int SearchAllOccurance(struct node *, struct node *, int);
int DeleteAtPosition(struct node **, struct node **, int);
int SearchLastOccurance(struct node *, struct node *, int);
int SearchFirstOccurance(struct node *, struct node *, int);
void InsertAtPosition(struct node **, struct node **, int, int);
void ConcatList(struct node **, struct node **, struct node **, struct node **);
void ConcatAtPosition(struct node **, struct node **, struct node **, struct node **, int);

int main(void)
{
    int iData;
    struct node *pFirst1 = NULL;
    struct node *pLast1 = NULL;
    struct node *pFirst2 = NULL;
    struct node *pLast2 = NULL;

    InsertFirst(&pFirst1, &pLast1, 30);
    InsertFirst(&pFirst1, &pLast1, 20);
    InsertFirst(&pFirst1, &pLast1, 10);
    InsertFirst(&pFirst1, &pLast1, 5);
    printf("List after insert First\n");
    Display(pFirst1, pLast1);

    InsertLast(&pFirst1, &pLast1, 40);
    InsertLast(&pFirst1, &pLast1, 50);
    InsertLast(&pFirst1, &pLast1, 40);
    InsertLast(&pFirst1, &pLast1, 60);
    printf("\n\nList after insert last\n");
    Display(pFirst1, pLast1);

    InsertAtPosition(&pFirst1, &pLast1, 30, 5);
    printf("\n\nList after insert %d at position %d\n", 10, 5);
    Display(pFirst1, pLast1);

    iData = DeleteFirst(&pFirst1, &pLast1);
    if (iData != -1)
        printf("\n\nDeleted first node data is: %d\n", iData);
    Display(pFirst1, pLast1);

    iData = DeleteLast(&pFirst1, &pLast1);
    if (iData != -1)
        printf("\n\nDeleted Last node data is: %d\n", iData);
    Display(pFirst1, pLast1);

    iData = DeleteAtPosition(&pFirst1, &pLast1, 3);
    if (iData != -1)
        printf("\n\nDeleted data at position %d is %d\n", 3, iData);
    Display(pFirst1, pLast1);

    iData = SearchFirstOccurance(pFirst1, pLast1, 40);
    if (iData != 0)
        printf("\n\nFirst occurance of key %d is:%d\n", 40, iData);
    Display(pFirst1, pLast1);

    iData = SearchLastOccurance(pFirst1, pLast1, 40);
    if (iData != 0)
        printf("\n\nLast occurance of key %d is:%d\n", 40, iData);
    Display(pFirst1, pLast1);

    iData = SearchAllOccurance(pFirst1, pLast1, 40);
    if (iData != 0)
        printf("\n\nAll occurance of key %d is:%d\n", 40, iData);
    Display(pFirst1, pLast1);

    printf("\n\nReverse list is\n");
    ReverseDisplay(pFirst1, pLast1);
    printf("\nOriginal list is\n");
    Display(pFirst1, pLast1);

    InsertLast(&pFirst2, &pLast2, 100);
    InsertLast(&pFirst2, &pLast2, 200);
    InsertLast(&pFirst2, &pLast2, 300);
    printf("\n\nSecond List after insert last\n");
    Display(pFirst2, pLast2);

    ConcatList(&pFirst1, &pLast1, &pFirst2, &pLast2);
    printf("\n\nConcated list is\n");
    Display(pFirst1, pLast1);
    printf("\nSecond list is");
    Display(pFirst2, pLast2);

    InsertLast(&pFirst2, &pLast2, 400);
    InsertLast(&pFirst2, &pLast2, 500);
    InsertLast(&pFirst2, &pLast2, 600);
    printf("\n\nSecond List after insert last\n");
    Display(pFirst2, pLast2);

    ConcatAtPosition(&pFirst1, &pLast1, &pFirst2, &pLast2, 3);
    printf("\n\nConcated list is\n");
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
        return;
    }

    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
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
        (*ppTail)->pNext = *ppHead;
        return;
    }
    (*ppTail)->pNext = pNewNode;
    *ppTail = pNewNode;
    (*ppTail)->pNext = *ppHead;
}

void InsertAtPosition(struct node **ppHead, struct node **ppTail, int iNo, int iPos)
{
    int iCount;
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    iCount = CountNodes(*ppHead, *ppTail);

    if (iPos <= 0 || iPos > iCount + 1)
    {
        printf("Invalid position");
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(ppHead, ppTail, iNo);
        return;
    }

    if (iPos == iCount + 1)
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
    iCount = 1;

    while (iCount < iPos - 1)
    {
        iCount++;
        pTemp = pTemp->pNext;
    }

    pNewNode->pNext = pTemp->pNext;
    pTemp->pNext = pNewNode;
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
        *ppHead = NULL;
        *ppTail = NULL;
    }
    else
    {
        *ppHead = (*ppHead)->pNext;
        free((*ppTail)->pNext);
        (*ppTail)->pNext = *ppHead;
    }

    return iDelData;
}

int DeleteLast(struct node **ppHead, struct node **ppTail)
{
    int iDelData;
    struct node *pTemp = NULL;

    if (NULL == *ppHead)
        return -1;

    iDelData = (*ppTail)->iData;

    if (*ppHead == *ppTail)
    {
        free(*ppTail);
        *ppHead = NULL;
        *ppTail = NULL;
    }
    else
    {
        pTemp = *ppHead;

        while (pTemp->pNext != *ppTail)
            pTemp = pTemp->pNext;

        free(*ppTail);

        *ppTail = pTemp;
        (*ppTail)->pNext = *ppHead;
    }
    return iDelData;
}

int DeleteAtPosition(struct node **ppHead, struct node **ppTail, int iPos)
{
    int iCount;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    iCount = CountNodes(*ppHead, *ppTail);

    if (iPos <= 0 || iPos > iCount)
    {
        printf("\nInvalid position\n");
        return -1;
    }

    if (iPos == 1)
    {
        return DeleteFirst(ppHead, ppTail);
    }

    if (iPos == iCount)
    {
        return DeleteLast(ppHead, ppTail);
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
    free(pTemp2);

    return iCount;
}

int SearchFirstOccurance(struct node *pHead, struct node *pTail, int iKey)
{
    int iCount = 0;

    if (NULL == pHead)
        return 0;

    do
    {
        iCount++;
        if (iKey == pHead->iData)
            return iCount;

        pHead = pHead->pNext;

    } while (pHead != pTail->pNext);

    return 0;
}

int SearchLastOccurance(struct node *pHead, struct node *pTail, int iKey)
{
    int iCounter = 0, iLastOccurance = 0;

    if (NULL == pHead)
        return 0;

    do
    {
        iCounter++;
        if (iKey == pHead->iData)
            iLastOccurance = iCounter;

        pHead = pHead->pNext;
    } while (pHead != pTail->pNext);

    return iLastOccurance;
}

int SearchAllOccurance(struct node *pHead, struct node *pTail, int iKey)
{
    int iCounter = 0;

    if (NULL == pHead)
        return 0;

    do
    {
        if (iKey == pHead->iData)
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

    do
    {
        pNext = pCurrent->pNext;
        pCurrent->pNext = pPrev;
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
        printf("List is Empty");
        return;
    }

    PhysicalReverse(&pHead, &pTail);
    Display(pHead, pTail);
    PhysicalReverse(&pHead, &pTail);
}

void ConcatList(struct node **ppHead1, struct node **ppTail1, struct node **ppHead2, struct node **ppTail2)
{
    if (NULL == *ppHead2)
        return;

    if (NULL == *ppHead1)
    {
        *ppHead1 = *ppHead2;
        *ppTail1 = *ppTail2;
        *ppHead2 = *ppTail2 = NULL;

        return;
    }

    (*ppTail1)->pNext = *ppHead2;
    *ppTail1 = *ppTail2;

    (*ppTail1)->pNext = *ppHead1;

    *ppHead2 = *ppTail2 = NULL;
}

void ConcatAtPosition(struct node **ppHead1, struct node **ppTail1, struct node **ppHead2, struct node **ppTail2, int iPos)
{
    int iCount;
    struct node *pTemp = NULL;

    iCount = CountNodes(*ppHead1, *ppTail1);

    if (iPos <= 0 || iPos > iCount + 1)
    {
        printf("Invalid position");
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
    pTemp->pNext = *ppHead2;

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
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    } while (pHead != pTail->pNext);
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

//Output

// List after insert First
// |5|->|10|->|20|->|30|->

// List after insert last
// |5|->|10|->|20|->|30|->|40|->|50|->|40|->|60|->

// List after insert 10 at position 5
// |5|->|10|->|20|->|30|->|30|->|40|->|50|->|40|->|60|->

// Deleted first node data is: 5
// |10|->|20|->|30|->|30|->|40|->|50|->|40|->|60|->

// Deleted Last node data is: 60
// |10|->|20|->|30|->|30|->|40|->|50|->|40|->

// Deleted data at position 3 is 30
// |10|->|20|->|30|->|40|->|50|->|40|->

// First occurance of key 40 is:4
// |10|->|20|->|30|->|40|->|50|->|40|->

// Last occurance of key 40 is:6
// |10|->|20|->|30|->|40|->|50|->|40|->

// All occurance of key 40 is:2
// |10|->|20|->|30|->|40|->|50|->|40|->

// Reverse list is
// |40|->|50|->|40|->|30|->|20|->|10|->
// Original list is
// |10|->|20|->|30|->|40|->|50|->|40|->

// Second List after insert last
// |100|->|200|->|300|->

// Concated list is
// |10|->|20|->|30|->|40|->|50|->|40|->|100|->|200|->|300|->
// Second list is
// List is empty


// Second List after insert last
// |400|->|500|->|600|->

// Concated list is
// |10|->|20|->|400|->|500|->|600|->|30|->|40|->|50|->|40|->|100|->|200|->|300|->
// Second list is
// List is empty


// After deletion all nodes
// First list is
// List is empty
// Second list is
// List is empty