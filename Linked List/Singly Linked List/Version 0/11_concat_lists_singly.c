#include <stdio.h>
#include <malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};

void ConcatList(struct node **, struct node **);
void InsertFirst(struct node **, int);
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
    printf("\nFirst List is\n");
    Display(pFirst);                        // |10|->|20|->|30|->|40|->

    InsertFirst(&pSecond, 70);
    InsertFirst(&pSecond, 60);
    InsertFirst(&pSecond, 50);
    printf("\nSecond List is\n");
    Display(pSecond);                         // |50|->|60|->|70|->

    ConcatList(&pFirst, &pSecond);
    printf("\n\nConcated list is\n");
    Display(pFirst);                       // |10|->|20|->|30|->|40|->|50|->|60|->|70|->

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

// First List is
// |10|->|20|->|30|->|40|->
// Second List is
// |50|->|60|->|70|->

// Concated list is
// |10|->|20|->|30|->|40|->|50|->|60|->|70|->

// List after Deletion
// List is empty