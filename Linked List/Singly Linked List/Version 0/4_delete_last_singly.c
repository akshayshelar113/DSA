#include <stdio.h>
#include <malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};

void InsertLast(struct node **, int);
int DeleteLast(struct node **);
void Display(struct node *);
void DeleteAll(struct node **);

int main(void)
{
    int iDelData;
    struct node *pFirst = NULL;

    InsertLast(&pFirst, 10);
    InsertLast(&pFirst, 20);
    InsertLast(&pFirst, 30);
    printf("Singly Linked list is\n");
    Display(pFirst); // |10|->|20|->|30|->

    iDelData = DeleteLast(&pFirst);
    printf("\n\nDeleted node data is: %d\n", iDelData); // 30
    Display(pFirst);                                    // |10|->|20|->

    if (pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }

    printf("\n\nList after Deletion\n");
    Display(pFirst); // List is empty

    return 0;
}

void InsertLast(struct node **ppHead, int iNo)
{
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("memory allocation fail");
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

// Singly Linked list is
// |10|->|20|->|30|->

// Deleted node data is: 30
// |10|->|20|->

// List after Deletion
// List is empty
