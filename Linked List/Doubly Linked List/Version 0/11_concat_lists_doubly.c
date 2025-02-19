#include <stdio.h>
#include <malloc.h>

struct node
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void InsertLast(struct node **, int);
void Display(struct node *);
void ConcatList(struct node **, struct node **);
void DeleteAll(struct node **);

int main(void)
{
    struct node *pFirst = NULL;
    struct node *pSecond = NULL;

    InsertLast(&pFirst, 10);
    InsertLast(&pFirst, 20);
    InsertLast(&pFirst, 30);
    InsertLast(&pFirst, 40);
    printf("\nFirst list is\n");
    Display(pFirst);                 //|10|<->|20|<->|30|<->|40|<->

    InsertLast(&pSecond, 50);
    InsertLast(&pSecond, 60);
    InsertLast(&pSecond, 70);
    printf("\n\nSecond list is\n");
    Display(pSecond);            //|50|<->|60|<->|70|<->

    ConcatList(&pFirst, &pSecond);
    printf("\n\nConcated list is:\n");
    Display(pFirst);                        //|10|<->|20|<->|30|<->|40|<->|50|<->|60|<->|70|<->

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
    Display(pFirst);                  // List is empty
    Display(pSecond);                   // List is empty


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
    (*ppHead2)->pPrev = pTemp;
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

void Display(struct node *pHead)
{
    if (NULL == pHead)
    {
        printf("\nList is Empty\n");
        return;
    }

    while (pHead != NULL)
    {
        printf("|%d|<->", pHead->iData);
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

// First list is
// |10|<->|20|<->|30|<->|40|<->

// Second list is
// |50|<->|60|<->|70|<->

// Concated list is:
// |10|<->|20|<->|30|<->|40|<->|50|<->|60|<->|70|<->

// List after Deletion

// List is Empty

// List is Empty
