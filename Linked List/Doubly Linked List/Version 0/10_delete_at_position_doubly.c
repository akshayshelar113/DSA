#include <stdio.h>
#include <malloc.h>

struct node
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void InsertLast(struct node **, int);
int DeleteAtPosition(struct node **, int);
int DeleteFirst(struct node **);
int DeleteLast(struct node **);
void Display(struct node *);
void DeleteAll(struct node **);

int main(void)
{
    int iDelData;
    struct node *pFirst = NULL;

    InsertLast(&pFirst, 40);
    InsertLast(&pFirst, 50);
    InsertLast(&pFirst, 60);
    InsertLast(&pFirst, 70);
    printf("\nList is\n");
    Display(pFirst);            //|40|<->|50|<->|60|<->|70|<->

    iDelData = DeleteAtPosition(&pFirst, 2);
    printf("\n\nData which is deleted from 2nd postion: %d\n", iDelData);     //Data which is deleted from 2nd postion: 50
    printf("New list is\n");
    Display(pFirst);                //|40|<->|60|<->|70|<->

    iDelData = DeleteAtPosition(&pFirst, 4);                             //Invalid position: 4
    if(iDelData != -1)
    printf("\n\nData which is deleted from 4th postion: %d\n", iDelData);

    printf("\nNew list is\n");
    Display(pFirst);                                                //|40|<->|60|<->|70|<->

    iDelData = DeleteAtPosition(&pFirst, 1);
    printf("\n\nData which is deleted from 1st postion: %d\n", iDelData);    //Data which is deleted from 1st postion: 40
    printf("New list is\n");
    Display(pFirst);                    //|60|<->|70|<->

    if (pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }

    printf("\n\nList after Deletion\n");
    Display(pFirst); // List is empty

    return 0;
}

int DeleteAtPosition(struct node **ppHead, int iPos)
{
    int iCount;
    struct node *pTemp = NULL;

    iCount = CountNodes(*ppHead);

    if (iPos <= 0 || iPos > iCount)
    {
        printf("\n\nInvalid position: %d", iPos);
        return -1;
    }

    if (iPos == 1)
        return DeleteFirst(ppHead);

    if (iPos == iCount)
        return DeleteLast(ppHead);

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

    free(pTemp);
    return iCount;
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
        *ppHead = NULL;

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

//    output

// List is
// |40|<->|50|<->|60|<->|70|<->

// Data which is deleted from 2nd postion: 50
// New list is
// |40|<->|60|<->|70|<->

// Invalid position: 4
// New list is
// |40|<->|60|<->|70|<->

// Data which is deleted from 1st postion: 40
// New list is
// |60|<->|70|<->

// List after Deletion
// List is empty