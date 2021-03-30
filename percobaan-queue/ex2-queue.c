#include <stdio.h>

#define MAX 100

typedef struct
{
    int Item[MAX];
    int Front;
    int Rear;
    int Max;
    int Count;
} Queue;

int Empty(Queue *Q)
{
    if (Q->Rear == -1)
    {
        return 1;
    }
    return 0;
}

void Push(Queue *Q, int value)
{
    if (Q->Count == Q->Max)
        printf("Maximum");
    else
    {
        if (Empty(Q) == 1)
        {
            Q->Front = 0;
            Q->Rear = 0;
            Q->Item[Q->Rear] = value;
            Q->Count = 1;
        }
        else
        {
            Q->Rear = (Q->Rear + 1) % Q->Max;
            Q->Item[Q->Rear] = value;
            Q->Count++;
        }
    }
}

void PushFront(Queue *Q, int value)
{
    if (Q->Count == Q->Max)
        printf("Maximum");
    else
    {
        if (Empty(Q) == 1)
        {
            Q->Front = 0;
            Q->Rear = 0;
            Q->Item[Q->Rear] = value;
            Q->Count = 1;
        }
        else
        {
            Q->Item[Q->Front] = value;
            Q->Front--;
            Q->Count++;
        }
    }
}

int Delete(Queue *Q)
{
    int deleted_item;
    deleted_item = Q->Item[Q->Front];
    Q->Item[Q->Front] = -69;
    if (Q->Front == Q->Rear)
        printf("Empty");
    else
    {
        Q->Front = (Q->Front + 1) % Q->Max;
        Q->Count--;
    }
    return deleted_item;
}

void Print(Queue *Q)
{
    int i, val;
    for (i = 0; i < Q->Count; i++)
    {
        val = Q->Item[i];
        if (val != -69)
        {
            printf("%d ", val);
        }
    }
    printf("\n");
}

void Initialize(Queue *Q, int value)
{
    Q->Count = 0;
    Q->Rear = -1;
    Q->Front = -1;
    Q->Max = value;
}

int main()
{
    Queue q;
    int del;

    Initialize(&q, 5);
    Push(&q, 5);
    Push(&q, 6);
    Print(&q);

    Push(&q, 7);
    Print(&q);

    del = Delete(&q);
    Print(&q);

    Push(&q, 8);
    Print(&q);

    Push(&q, 9);
    Print(&q);

    del = Delete(&q);
    Print(&q);

    Push(&q, 10);
    Print(&q);

    Push(&q, 11);
    Print(&q);
    printf("\n\nPress enter to exit...");
    getchar();
    return 0;
}