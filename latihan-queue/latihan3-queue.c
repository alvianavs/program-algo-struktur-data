#include <stdio.h>
#include <Windows.h>
#define MAX 10

typedef struct
{
    int Car[MAX];
    int Front;
    int Rear;
} Queue;

void Inisialisasi(Queue *q)
{
    q->Front = -1;
    q->Rear = -1;
}

void Masuk(Queue *q, int car)
{
    if (q->Rear == MAX - 1)
    {
        return;
    }
    else {
        if (q->Front == -1)
            q->Front = 0;
        q->Rear++;
        q->Car[q->Rear] = car;
    }
}

void Keluar(Queue *q)
{
    if (q->Front == -1 || q->Front > q->Rear)
    {
        return;
    }
    else {
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
    return (q->Rear == MAX-1);
}
void Tampil(Queue *q)
{
    if (q->Front != -1)
    {
        for (int i = q->Front; i < q->Rear + 1; i++)
        {
            printf(" | [%d] Mobil Nomor ke : %d\t    |\n", i + 1, q->Car[i]);
        }
    }
}
int main()
{
    Queue q;
    char conf;
    int data, ch;
    Inisialisasi(&q);
    while (ch != 4)
    {
        system("cls");
        printf(" +==================================+\n");
        printf(" | \t[1] Masukkan Mobil          |\n");
        printf(" | \t[2] Keluarkan Mobil         |\n");
        printf(" | \t[3] Kosongkan parkiran      |\n");
        printf(" | \t[4] Exit                    |\n");
        printf(" +==================================+\n\n");
        if (Penuh(&q)) {
            printf(" +========= Parkiran Penuh! ========+\n");
            printf(" |                                  |\n");
        }
        if (Kosong(&q)) {
            printf(" +========= Parkiran Kosong ========+\n");
            printf(" |                                  |\n");
        }
        printf(" +========== Daftar Mobil ==========+\n");
        Tampil(&q);
        printf(" +==================================+\n");
        printf(" | Masukkan pilihan : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf(" | Masukkan nomor mobil : ");
            scanf("%d", &data);
            Masuk(&q, data);
            break;
        case 2:
            Keluar(&q);
            break;
        case 3:
            fflush(stdin);
            printf(" | Apakah anda yakin ? [y/n] : ");
            scanf("%c", &conf);
            if (conf == 'y')
                Inisialisasi(&q);
            break;
        case 4:
            system("exit");
            break;
        default:
            printf(" | Pilihan yang anda masukkan salah \n");
            fflush(stdin);
            printf(" | Continue ? [y/n] : ");
            scanf("%c", &conf);
            if (conf != 'y')
                ch = 3;
            break;
        }
    
    }
}