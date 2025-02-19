#include <stdio.h>
#define MAX 5

void EnQueue(int *, int *, int *, int);
int DeQueue(int *, int *, int *);
void Display(int *, int, int);
int IsQueueFull(int);
int IsQueueEmpty(int);

int main(void)
{
    int DeQuedData;
    int Queue[MAX];
    int iRear = -1;
    int iFront = 0;

    EnQueue(Queue, &iRear, &iFront, 10);
    EnQueue(Queue, &iRear, &iFront, 20);
    EnQueue(Queue, &iRear, &iFront, 30);
    EnQueue(Queue, &iRear, &iFront, 40);
    EnQueue(Queue, &iRear, &iFront, 50);
    printf("Queue is\n");
    Display(Queue, iRear, iFront);

    DeQuedData = DeQueue(Queue, &iRear, &iFront);
    if (DeQuedData != -1)
        printf("\n\nDequed data is: %d", DeQuedData);
    printf("\nQueue after DeQueue is\n");
    Display(Queue, iRear, iFront);

    printf("\nEntering new data after deque");
    EnQueue(Queue, &iRear, &iFront, 60);
    Display(Queue, iRear, iFront);

    return 0;
}

void EnQueue(int *Queue, int *piRear, int *piFront, int iNo)
{
    if (IsQueueFull(*piRear))
    {
        printf("\nQueue is FULL\n");
        return;
    }

    Queue[++(*piRear)] = iNo;
}

int DeQueue(int *pQueue, int *piRear, int *piFront)
{
    int iDelData;
    if (IsQueueEmpty(*piRear))
    {
        printf("\nQueue is empty\n");
        return -1;
    }

    iDelData = pQueue[*piFront];

    if (*piFront == *piRear)
    {
        *piFront = 0;
        *piRear = -1;
    }
    else
        (*piFront)++;

    return iDelData;
}

int IsQueueFull(int iRear)
{
    if (iRear == MAX - 1)
        return 1;
    return 0;
}

int IsQueueEmpty(int iRear)
{
    if (iRear == -1)
        return -1;
    return 0;
}

void Display(int *pQueue, int iRear, int iFront)
{
    int iCounter;

    if (iRear == -1)
    {
        printf("\nList is empty\n");
        return;
    }

    for (iCounter = iFront; iCounter <= iRear; iCounter++)
    {
        printf("%d\t", pQueue[iCounter]);
    }
}

// Output

// Queue is
// 10      20      30      40

// Dequed data is: 10
// Queue after DeQueue is
// 20      30      40
