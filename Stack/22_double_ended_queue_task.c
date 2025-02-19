#include <stdio.h>
#define MAX 5

void EnQueue(int *, int *, int *, int);
void EnQueueFromFront(int *, int *, int *, int);
int DeQueue(int *, int *, int *);
int DeQueueFromRear(int *, int *, int *);
void Display(const int *, int, int);
int IsQueueFull(int, int);

int main(void)
{
    int iQuedData;
    int Queue[MAX];
    int iFront = 0;
    int iRear = -1;

    EnQueue(Queue, &iFront, &iRear, 10);
    EnQueue(Queue, &iFront, &iRear, 20);
    EnQueue(Queue, &iFront, &iRear, 30);
    EnQueue(Queue, &iFront, &iRear, 40);
    Display(Queue, iFront, iRear);

    iQuedData = DeQueue(Queue, &iFront, &iRear);
    if (iQuedData != -1)
        printf("\n\nDeQued data is: %d", iQuedData);
    printf("\nQueue after DeQueue\n");
    Display(Queue, iFront, iRear);

    EnQueueFromFront(Queue, &iFront, &iRear, 60);
    printf("\n\nQueue after Front enqueue\n");
    Display(Queue, iFront, iRear);

    iQuedData = DeQueueFromRear(Queue, &iFront, &iRear);
    if (iQuedData != -1)
        printf("\n\nDeQued data from rear is: %d", iQuedData);
    printf("\nQueue after DeQueue from rear is\n");
    Display(Queue, iFront, iRear);

    return 0;
}

void EnQueueFromFront(int *pQueue, int *piFront, int *piRear, int iNo)
{
    if (IsQueueFull(*piFront, *piRear))
    {
        printf("\nQueue is FULL\n");
        return;
    }

    if (*piFront == 0)
    {
        *piFront = MAX - 1;
        *piRear = MAX - 1;
    }

    (*piFront)--;
    pQueue[*piFront] = iNo;
}

void EnQueue(int *pQueue, int *piFront, int *piRear, int iNo)
{
    if (IsQueueFull(*piFront, *piRear))
    {
        printf("\nQueue is FULL\n");
        return;
    }

    if (*piRear == MAX - 1)
        *piRear = 0;
    else
        (*piRear)++;

    pQueue[*piRear] = iNo;
}

int DeQueueFromRear(int *pQueue, int *piFront, int *piRear)
{
    int iQuedData;
    if (IsQueueEmpty(*piRear))
    {
        printf("Queue is empty");
        return -1;
    }

    iQuedData = pQueue[*piRear];
    if (*piRear == *piFront)
    {
        *piFront = 0;
        *piRear = -1;
    }
    else
        (*piRear)--;

    return iQuedData;
}

int DeQueue(int *pQueue, int *piFront, int *piRear)
{
    int iQuedData;
    if (IsQueueEmpty(*piRear))
    {
        printf("Queue is empty");
        return -1;
    }

    iQuedData = pQueue[*piFront];

    if (*piFront == *piRear)
    {
        *piFront = 0;
        *piRear = -1;
    }
    else if (*piFront == MAX - 1)
        *piFront = 0;

    else
        (*piFront)++;

    return iQuedData;
}

int IsQueueEmpty(int iRear)
{
    if (iRear == -1)
        return 1;
    return 0;
}

int IsQueueFull(int iFront, int iRear)
{
    if ((iFront == 0 && iRear == MAX - 1) || (iRear == iFront - 1 && iRear != -1))
        return 1;
    return 0;
}

void Display(const int *pQueue, int iFront, int iRear)
{
    int iCounter;

    if (iRear < iFront)
    {
        for (iCounter = iFront; iCounter <= MAX - 1; iCounter++)
            printf("%d\t", pQueue[iCounter]);

        for (iCounter = 0; iCounter <= iRear; iCounter++)
            printf("%d\t", pQueue[iCounter]);
    }
    else
    {
        for (iCounter = iFront; iCounter <= iRear; iCounter++)
            printf("%d\t", pQueue[iCounter]);
    }
}