#include <stdio.h>
#include <malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **, int);
void Display(struct node *);
int DeleteFirst(struct node **);
void DeleteAll(struct node **);

int main(void)
{
    int iDelData;
    struct node *pFirst = NULL;

    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 30);

    printf("Singly linked list is\n");
    Display(pFirst);                                        // |30|->|20|->|10|->

    iDelData = DeleteFirst(&pFirst);
    printf("\n\nDeleted first Node data is: %d\n", iDelData);  //30
    Display(pFirst);                                          // |20|->|10|->

    if (pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }

    printf("\n\nList after Deletion\n");
    Display(pFirst);                                         // List is empty

    return 0;
}

void InsertFirst(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("Mempry allocation FAILED");
        return;
    }

    pNewNode->iData = iNo;

    if (*ppHead == NULL)
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

    pTemp->pNext = NULL;

    free(pTemp);
    return iDelData;
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

// Singly linked list is
// |30|->|20|->|10|->

// Deleted first Node data is: 30
// |20|->|10|->

// List after Deletion
// List is empty