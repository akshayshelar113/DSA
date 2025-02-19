#include <stdio.h>
#include <malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};

void InsertAtPosition(struct node **, int, int);
void InsertFirst(struct node **, int);
// void InsertLast(struct node **, int);

int CountNodes(struct node *);
void Display(struct node *);
void DeleteAll(struct node **);

int main(void)
{
    struct node *pFirst = NULL;

    printf("\nInserting 10 at postion 1\n");
    InsertAtPosition(&pFirst, 10, 1);
    Display(pFirst);                                   // |10|->

    printf("\n\nInserting 20 at postion 1\n");
    InsertAtPosition(&pFirst, 20, 1);
    Display(pFirst);                                    // |20|->|10|->

    printf("\n\nInserting 30 at postion 2\n");
    InsertAtPosition(&pFirst, 30, 2);
    Display(pFirst);                                    // |20|->|30|->|10|->           

    printf("\n\nInserting 40 at postion 5\n");
    InsertAtPosition(&pFirst, 40, 5);                     // Position is invalid
    Display(pFirst);                                     // |20|->|30|->|10|->

    printf("\n\nInserting 50 at postion 4\n");
    InsertAtPosition(&pFirst, 50, 4);
    Display(pFirst);                                      // |20|->|30|->|10|->|50|->

    printf("\n\nInserting 60 at postion 4\n");
    InsertAtPosition(&pFirst, 60, 4);
    Display(pFirst);                                      // |20|->|30|->|10|->|60|->|50|->

    if (pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }

    printf("\n\nList after Deletion\n");
    Display(pFirst);                        // List is empty

    return 0;
}

void InsertAtPosition(struct node **ppHead, int iNo, int iPos)
{
    int iCount;
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;

    iCount = CountNodes(*ppHead);

    if (iPos <= 0 || iPos > iCount + 1)
    {
        printf("Position is invalid\n");
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(ppHead, iNo);
        return;
    }

    // if (iPos == iCount + 1)
    // {
    //     InsertLast(ppHead, iNo);
    //     return;
    // }

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

// void InsertLast(struct node **ppHead, int iNo)
// {
//     struct node *pTemp = NULL;
//     struct node *pNewNode = NULL;

//     pNewNode = (struct node *)malloc(sizeof(struct node));

//     if (NULL == pNewNode)
//     {
//         printf("Memory allocation fail");
//         return;
//     }

//     pNewNode->iData = iNo;
//     pNewNode->pNext = NULL;

//     if (NULL == *ppHead)
//     {
//         *ppHead = pNewNode;
//         return;
//     }

//     pTemp = *ppHead;

//     while (pTemp->pNext != NULL)
//         pTemp = pTemp->pNext;

//     pTemp->pNext = pNewNode;
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

// Output

// Inserting 10 at postion 1
// |10|->

// Inserting 20 at postion 1
// |20|->|10|->

// Inserting 30 at postion 2
// |20|->|30|->|10|->

// Inserting 40 at postion 5
// Position is invalid
// |20|->|30|->|10|->

// Inserting 50 at postion 4
// |20|->|30|->|10|->|50|->

// Inserting 60 at postion 4
// |20|->|30|->|10|->|60|->|50|->

// List after Deletion
// List is empty
