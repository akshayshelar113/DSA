#include <stdio.h>
#include <malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};

int DeleteAtPosition(struct node **, int);
void InsertLast(struct node **, int);
int CountNodes(struct node *);
int DeleteFirst(struct node **);
// int DeleteLast(struct node **);
void Display(struct node *);
void DeleteAll(struct node **);

int main(void)
{
    int iDelData;
    struct node *pFirst = NULL;

    InsertLast(&pFirst, 10);
    InsertLast(&pFirst, 20);
    InsertLast(&pFirst, 30);
    InsertLast(&pFirst, 40);
    InsertLast(&pFirst, 50);
    printf("\nList is\n");
    Display(pFirst);                      // |10|->|20|->|30|->|40|->|50|->

    iDelData = DeleteAtPosition(&pFirst, 2);
    printf("\n\nData which is deleted from 2nd postion: %d\n", iDelData);   //Data which is deleted from 2nd postion: 20
    printf("New list is\n");
    Display(pFirst);                            // |10|->|30|->|40|->|50|->

    iDelData = DeleteAtPosition(&pFirst, 4);
    printf("\n\nData which is deleted from 4th postion: %d\n", iDelData);  //Data which is deleted from 4st postion: 50
    printf("New list is\n");
    Display(pFirst);                                // |10|->|30|->|40|->

    iDelData = DeleteAtPosition(&pFirst, 1);
    printf("\n\nData which is deleted from 1st postion: %d\n", iDelData);   // Data which is deleted from 1st postion: 10
    printf("New list is\n");
    Display(pFirst);                               // |30|->|40|->

    if (pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }

    printf("\n\nList after Deletion\n");
    Display(pFirst);                   // List is empty

    return 0;
}

int DeleteAtPosition(struct node **ppHead, int iPos)
{
    int iCount;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    iCount = CountNodes(*ppHead);

    if (iPos <= 0 || iPos > iCount)
    {
        printf("Invalid position");
        return -1;
    }

    if (iPos == 1)
    {
        return DeleteFirst(ppHead);
    }

    // if (iPos == iCount)
    // {
    //     return DeleteLast(ppHead);
    // }

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

int DeleteFirst(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp = NULL;

    if (NULL == *ppHead)
    {
        return -1;
    }

    pTemp = *ppHead;

    *ppHead = pTemp->pNext;

    iDelData = pTemp->iData;
    free(pTemp);

    return iDelData;
}

// int DeleteLast(struct node **ppHead)
// {
//     int iDelData;
//     struct node *pTemp = NULL;

//     if (NULL == *ppHead)
//     {
//         return -1;
//     }

//     pTemp = *ppHead;

//     if (NULL == pTemp->pNext)
//     {
//         iDelData = pTemp->iData;
//         free(pTemp);
//         *ppHead = NULL;
//     }
//     else
//     {
//         while (pTemp->pNext->pNext != NULL)
//             pTemp = pTemp->pNext;

//         iDelData = pTemp->pNext->iData;
//         free(pTemp->pNext);
//         pTemp->pNext = NULL;
//     }
//     return iDelData;
// }

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
    if (pHead == NULL)
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

// List is
// |10|->|20|->|30|->|40|->|50|->

// Data which is deleted from 2nd postion: 20
// New list is
// |10|->|30|->|40|->|50|->

// Data which is deleted from 4th postion: 50
// New list is
// |10|->|30|->|40|->

// Data which is deleted from 1st postion: 10
// New list is
// |30|->|40|->

// List after Deletion
// List is empty