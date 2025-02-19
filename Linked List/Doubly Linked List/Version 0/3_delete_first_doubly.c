#include <stdio.h>
#include <malloc.h>

struct node
{
    struct node *pPrev;
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

    printf("Doubly Linked list is\n");
    Display(pFirst);                             //|30|->|20|->|10|->

    iDelData = DeleteFirst(&pFirst);
    printf("\n\nDeleted node data is: %d\n", iDelData);        //Deleted node data is: 30
    Display(pFirst);                             //|20|->|10|->

    if (pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }

    printf("\n\nList after Deletion\n");
    Display(pFirst);                // List is empty


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
    pNewNode->pPrev = NULL;

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
        printf("String is empty");
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

