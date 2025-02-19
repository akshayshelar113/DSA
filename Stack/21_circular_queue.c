#include <stdio.h>
#define MAX 5

void EnQueue(int *, int *, int *, int);
int DeQueue(int *, int *, int *);
int IsQueueFull(int, int);
int IsQueueEmpty(int);
void Display(const int *, int, int);

int main(void)
{
    int DeQuedData;
    int Queue[MAX];
    int iFront = 0;
    int iRear = -1;

    EnQueue(Queue, &iFront, &iRear, 10);
    EnQueue(Queue, &iFront, &iRear, 20);
    EnQueue(Queue, &iFront, &iRear, 30);
    EnQueue(Queue, &iFront, &iRear, 40);
    EnQueue(Queue, &iFront, &iRear, 50);
    printf("Queue is\n");
    Display(Queue, iFront, iRear);

    DeQuedData = DeQueue(Queue, &iFront, &iRear);
    if (DeQuedData != -1)
        printf("\n\nDequed data is: %d", DeQuedData);
    printf("\nQueue after DeQueue is\n");
    Display(Queue, iFront, iRear);

    printf("\n\nEntering data after dequed one data\n");
    EnQueue(Queue, &iFront, &iRear, 60);
    Display(Queue, iFront, iRear);

    DeQuedData = DeQueue(Queue, &iFront, &iRear);
    if (DeQuedData != -1)
        printf("\n\nDequed data after 2nd deque is: %d", DeQuedData);
    printf("\nQueue after DeQueue is\n");
    Display(Queue, iFront, iRear);

    EnQueue(Queue, &iFront, &iRear, 70);
    printf("\n\nAfter 2nd enque\n");
    Display(Queue, iFront, iRear);

    return 0;
}

void EnQueue(int *pQueue, int *piFront, int *piRear, int iNo)
{
    if (IsQueueFull(*piFront, *piRear))
    {
        printf("\nQueue is full\n");
        return;
    }
    if (*piRear == MAX - 1)
        *piRear = 0;
    else
        (*piRear)++;

    pQueue[*piRear] = iNo;
}

int DeQueue(int *pQueue, int *piFront, int *piRear)
{
    int iDeQuedData;
    if (IsQueueEmpty(*piRear))
    {
        printf("\nQueue is empty\n");
        return -1;
    }

    iDeQuedData = pQueue[*piFront];

    if (*piRear == *piFront)
    {
        *piRear = -1;
        *piFront = 0;
    }
    else if (*piFront == MAX - 1)
        *piFront = 0;
    else
        (*piFront)++;

    return iDeQuedData;
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

    if (iRear == -1)
    {
        printf("\nQueue is empty\n");
        return;
    }

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
