#include <stdio.h>
#include <Windows.h>
#define MAX 5

typedef struct
{
    int Item[MAX];
    int Front;
    int Rear;
    int Over;
} Queue;

void Inisialisasi(Queue *q)
{
    q->Front = -1;
    q->Rear = -1;
    q->Over = 0;
}

void Enqueue(Queue *q, int item)
{
    if (q->Rear == MAX - 1)
    {
        q->Front = q->Over;
        q->Item[q->Over] = item;
        q->Over++;
        
    }
    else
    {
        if (q->Front == -1)
            q->Front = 0;
        q->Rear++;
        q->Item[q->Rear] = item;
    }
}

void Dequeue(Queue *q)
{
    if (q->Front == -1 || q->Front > q->Rear)
    {
        return;
    }
    else
    {
        q->Item[q->Front] = 0;
        q->Front++;
    }
}
int Kosong(Queue *q)
{
    if (q->Rear == -1 || q->Front > q->Rear)
        return 1;
    else
        return 0;
}
int Penuh(Queue *q)
{
    return (q->Rear == MAX - 1);
}
void Tampil(Queue *q)
{
    if (q->Front != -1)
    {
        for (int i = 0; i < q->Rear + 1; i++)
        {
            if (q->Item[i] == 0)
                printf(" ");
            else
                printf("%d ", q->Item[i]);
        }
    }
    printf("\n");
}
int main()
{
    Queue q;
    int data, ch;
    Inisialisasi(&q);
    Enqueue(&q, 5);
    Tampil(&q);
    Enqueue(&q, 6);
    Tampil(&q);
    Enqueue(&q, 7);
    Tampil(&q);
    Dequeue(&q);
    Tampil(&q);
    Enqueue(&q, 8);
    Tampil(&q);
    Dequeue(&q);
    Tampil(&q);
    Enqueue(&q, 9);
    Tampil(&q);
    Enqueue(&q, 10);
    Tampil(&q);
    Enqueue(&q, 11);
    Tampil(&q);


    printf("\n\nPress enter to exit...");
    getchar();
}