#include <stdio.h>
#include <malloc.h>
typedef struct node
{
    int Item;
    struct node *link;
} Node;
typedef struct
{
    Node *Front;
    Node *Rear;
} Queue;
// Prosedur untuk menyisipkan data pada antrian
void Tambah(Queue *Q, int y)
{
    Node *ptr;
    ptr = (Node *)malloc(sizeof(Node));
    ptr->Item = y;
    ptr->link = NULL;
    if (Q->Front == NULL)
    {
        Q->Front = Q->Rear = ptr;
    }
    else
    {
        Q->Rear->link = ptr;
        Q->Rear = ptr;
    }
}
// Prosedur untuk menghapus data dari antrian
int Hapus(Queue *Q)
{
    int num;
    if (Q->Front == NULL)
    {
        printf("\n\n\t\tAntrian Kosong\n\n");
        return (0);
    }
    else
    {
        num = Q->Front->Item;
        Q->Front = Q->Front->link;
        if (Q->Front == NULL)
            Q->Rear = NULL;
        //printf("\nNilai yang dihapus : %d \n",num);
        return (num);
    }
}
void Tampil(Node *N)
{
    printf("\nFront -> ");
    while (N != NULL)
    {
        if (N->link == NULL)
        {
            printf("%5d", N->Item);
            printf(" <- Rear");
        }
        else
            printf("%5d", N->Item);
        N = N->link;
    }
}
int Count(Node *N)
{
    int c = 0;
    while (N != NULL)
    {
        N = N->link;
        c++;
    }
    return c;
}
int main()
{
    int item;
    Queue Q;
    Q.Front = Q.Rear = NULL;
    Tambah(&Q, 11);
    Tambah(&Q, 12);
    Tambah(&Q, 13);
    Tambah(&Q, 14);
    Tambah(&Q, 15);
    Tambah(&Q, 16);
    Tambah(&Q, 17);
    Tampil(Q.Front);
    printf("\nJumlah data pada antrian : %d", Count(Q.Front));
    item = Hapus(&Q);
    printf("\nNilai yang dihapus : %d", item);
    item = Hapus(&Q);
    printf("\nNilai yang dihapus : %d", item);
    item = Hapus(&Q);
    printf("\nNilai yang dihapus : %d", item);
    Tampil(Q.Front);
    printf("\nJumlah data pada antrian : %d", Count(Q.Front));

    printf("\n\nPress enter to exit...");
    getchar();
}