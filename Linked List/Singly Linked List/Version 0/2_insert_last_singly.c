#include <stdio.h>
#include <malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};

void InsertLast(struct node **, int);
void Display(struct node *);
void DeleteAll(struct node **);

int main(void)
{
    struct node *pFirst = NULL;

    InsertLast(&pFirst, 10);
    InsertLast(&pFirst, 20);
    InsertLast(&pFirst, 30);
    printf("List is\n");
    Display(pFirst);                            // |10|->|20|->|30|->

    printf("\n\nInserting new node \n");
    InsertLast(&pFirst, 40);
    Display(pFirst);                            // |10|->|20|->|30|->|40|->

    if (pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }
    printf("\n\nList after Deletion\n");
    Display(pFirst);                            // Linked list is empty

    return 0;
}

void InsertLast(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

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
    if (NULL == pHead)
    {
        printf("Linked list is empty");
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

//Output

// List is
// |10|->|20|->|30|->

// Inserting new node
// |10|->|20|->|30|->|40|->

// List after Deletion
// Linked list is empty
