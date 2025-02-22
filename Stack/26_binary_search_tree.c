#include <stdio.h>
#include<malloc.h>

struct node
{
    struct node *pLChild;
    int iData;
    struct node *pRChild;
};

void DeleteAll(struct node **);
int Height(struct node *);
void PreOrder(struct node *);
void InOrder(struct node *);
void PostOrder(struct node *);
int CountNodesV1(struct node *);
int CountNodesV2(struct node *);
int SmallestElement(struct node *);
int LargestElement(struct node *);
int CountLeafNodes(struct node *);
int SmallestElement(struct node *);
int CountNonLeafNodes(struct node *);
void DeleteNode(struct node **, int);
void InsertNode(struct node **, int iKey);
struct node *SearchBSTRecursive(struct node *, int);
struct node *SearchBSTNonRecursive(struct node *, int);

int main(void)
{
    int iCount;
    struct node *pParent = NULL;
    struct node *pSearched = NULL;

    InsertNode(&pParent, 100);
    InsertNode(&pParent, 150);
    InsertNode(&pParent, 90);
    InsertNode(&pParent, 120);
    InsertNode(&pParent, 80);
    InsertNode(&pParent, 50);
    InsertNode(&pParent, 140);
    InsertNode(&pParent, 160);
    InsertNode(&pParent, 10);

    printf("Preorder\n");
    PreOrder(pParent);
    printf("\n\nInOrder\n");
    InOrder(pParent);
    printf("\n\nPostOrder\n");
    PostOrder(pParent);

    iCount = CountNodesV1(pParent);
    printf("\n\nTotal node count of tree by Version 1 is: %d", iCount);

    iCount = CountNodesV2(pParent);
    printf("\n\nTotal node count of tree by Version 2 is: %d", iCount);

    iCount = CountLeafNodes(pParent);
    printf("\n\nLeaf node count of tree is: %d", iCount);

    iCount = CountNonLeafNodes(pParent);
    printf("\n\nNon Leaf node count of tree is: %d", iCount);

    iCount = Height(pParent);
    printf("\n\nHeight of tree is: %d", iCount);

    iCount = SmallestElement(pParent);
    if (iCount != -1)
        printf("\n\nSmallest element of tree is: %d", iCount);

    iCount = LargestElement(pParent);
    if (iCount != -1)
        printf("\n\nLargest element of tree is: %d", iCount);

    pSearched = SearchBSTRecursive(pParent, 10);
    if (pSearched != NULL)
        printf("\n\nIn SearchBSTRecursive Key found at address: %d", pSearched);

    pSearched = SearchBSTNonRecursive(pParent, 10);
    if (pSearched != NULL)
        printf("\n\nIn SearchBSTNonRecursive Key found at address: %d", pSearched);

    DeleteNode(&pParent, 10);
    printf("\n\nPreorder after delet node\n");
    PreOrder(pParent);

    printf("\n\nAfter delet all\n");
    DeleteAll(&pParent);
    printf("\n\nPostOrder\n");
    PostOrder(pParent);

    return 0;
}

void InsertNode(struct node **ppRoot, int iNo)
{
    struct node *pParent = NULL;
    struct node *pPtr = NULL;
    struct node *pNewNode = NULL;

    pPtr = *ppRoot;

    while (pPtr != NULL)
    {
        pParent = pPtr;

        if (iNo < pParent->iData)
            pPtr = pPtr->pLChild;

        else if (iNo > pParent->iData)
            pPtr = pPtr->pRChild;
        else
        {
            printf("Duplicate data");
            return;
        }
    }

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("Memory allocation failed");
        return;
    }

    pNewNode->iData = iNo;
    pNewNode->pLChild = pNewNode->pRChild = NULL;

    if (NULL == pParent)
        *ppRoot = pNewNode;

    else if (iNo < pParent->iData)
        pParent->pLChild = pNewNode;

    else
        pParent->pRChild = pNewNode;
}

void PreOrder(struct node *pRoot)
{
    if (NULL == pRoot)
        return;
    printf("(%d)\t", pRoot->iData);
    PreOrder(pRoot->pLChild);
    PreOrder(pRoot->pRChild);
}

void InOrder(struct node *pRoot)
{
    if (NULL == pRoot)
        return;

    InOrder(pRoot->pLChild);
    printf("(%d)\t", pRoot->iData);
    InOrder(pRoot->pRChild);
}

void PostOrder(struct node *pRoot)
{
    if (NULL == pRoot)
        return;

    PostOrder(pRoot->pLChild);
    PostOrder(pRoot->pRChild);
    printf("(%d)\t", pRoot->iData);
}

int CountNodesV1(struct node *pRoot)
{
    static int iCount = 0;

    if (NULL == pRoot)
        return 0;

    iCount++;
    CountNodesV1(pRoot->pLChild);
    CountNodesV1(pRoot->pRChild);

    return iCount;
}

int CountNodesV2(struct node *pRoot)
{
    if (NULL == pRoot)
        return 0;

    return CountNodesV2(pRoot->pLChild) + CountNodesV2(pRoot->pRChild) + 1;
}

int CountLeafNodes(struct node *pRoot)
{
    static int iCount = 0;

    if (NULL == pRoot)
        return 0;

    if (pRoot->pLChild == NULL && pRoot->pRChild == NULL)
        iCount++;

    CountLeafNodes(pRoot->pLChild);
    CountLeafNodes(pRoot->pRChild);

    return iCount;
}

int CountNonLeafNodes(struct node *pRoot)
{
    static int iCount = 0;

    if (NULL == pRoot)
        return 0;

    if (pRoot->pLChild != NULL || pRoot->pRChild != NULL)
        iCount++;

    CountNonLeafNodes(pRoot->pLChild);
    CountNonLeafNodes(pRoot->pRChild);

    return iCount;
}

int Height(struct node *pRoot)
{
    int iLeftHeight;
    int iRightHeight;

    if (NULL == pRoot)
        return 0;

    iLeftHeight = Height(pRoot->pLChild);
    iRightHeight = Height(pRoot->pRChild);

    if (iLeftHeight > iRightHeight)
        return iLeftHeight + 1;
    else
        return iRightHeight + 1;
}

int SmallestElement(struct node *pRoot)
{
    int iSmallest;
    struct node *pParent = NULL;

    if (NULL == pRoot)
        return -1;

    while (pRoot != NULL)
    {
        pParent = pRoot;
        pRoot = pRoot->pLChild;
    }

    iSmallest = pParent->iData;

    return iSmallest;
}

int LargestElement(struct node *pRoot)
{
    int iLargest;
    struct node *pParent = NULL;

    if (NULL == pRoot)
        return -1;

    while (pRoot != NULL)
    {
        pParent = pRoot;
        pRoot = pRoot->pRChild;
    }

    iLargest = pParent->iData;

    return iLargest;
}

struct node *SearchBSTRecursive(struct node *pRoot, int iKey)
{
    if (NULL == pRoot)
        return NULL;

    if (iKey < pRoot->iData)
        return SearchBSTRecursive(pRoot->pLChild, iKey);

    else if (iKey > pRoot->iData)
        return SearchBSTRecursive(pRoot->pRChild, iKey);

    else
        return pRoot;
}

struct node *SearchBSTNonRecursive(struct node *pRoot, int iKey)
{
    while (pRoot != NULL)
    {
        if (iKey < pRoot->iData)
            pRoot = pRoot->pLChild;

        else if (iKey > pRoot->iData)
            pRoot = pRoot->pRChild;

        else
            return pRoot;
    }
    return NULL;
}

void DeleteNode(struct node **ppRoot, int iKey)
{
    struct node *pPtr = NULL;
    struct node *pChild = NULL;
    struct node *pParent = NULL;
    struct node *pSuccesor = NULL;

    pPtr = *ppRoot;

    while (pPtr != NULL)
    {
        if (iKey == pPtr->iData)
            break;

        pParent = pPtr;

        if (iKey < pPtr->iData)
            pPtr = pPtr->pLChild;
        else
            pPtr = pPtr->pRChild;
    }

    if (NULL == pPtr)
    {
        printf("Data not found");
        return;
    }

    if (pPtr->pLChild != NULL && pPtr->pRChild != NULL)
    {
        pSuccesor = pPtr->pRChild;
        pParent = pPtr;

        if (pSuccesor->pLChild != NULL)
        {
            pParent = pSuccesor;
            pSuccesor = pSuccesor->pLChild;
        }

        pPtr->iData = pSuccesor->iData; //------------
        pPtr = pSuccesor;
    }

    if (pPtr->pLChild != NULL)
        pChild = pPtr->pLChild;
    else
        pChild = pPtr->pRChild;

    if (NULL == pParent)
        *ppRoot = pChild;
    else if (iKey < pParent->iData)
        pParent->pLChild = pChild;
    else
        pParent->pRChild = pChild;

    free(pPtr);
}

void DeleteAll(struct node **ppRoot)
{
    if (NULL == *ppRoot)
        return;

    PostOrder((*ppRoot)->pLChild);
    PostOrder((*ppRoot)->pRChild);

    free(*ppRoot);
    *ppRoot = NULL;
}
