#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct simpul
{
    char nama[25];
    int nrp;
    struct simpul *before;
    struct simpul *next;
};

struct simpul *baru = NULL, *head, *tail;
int j = 0;

struct simpul *alokasi_simpul()
{
    struct simpul *baru;
    baru = (struct simpul *)malloc(sizeof(struct simpul));
    if (baru == NULL)
        return NULL;
    else
        baru->next = NULL;
        baru->before = NULL;
    return baru;
}
void lanjutkan()
{
    fflush(stdin);
    printf("\n | Press enter to continue...");
    getchar();
    system("cls");
}
void simpan()
{
    char conf;
    printf(" + ---------------------------------------- +\n");
    do
    {
        baru = alokasi_simpul();
        printf(" | Nama\t: ");
        scanf("%s", &baru->nama);
        printf(" | NRP\t: ");
        scanf("%d", &baru->nrp);    

        if (j == 0 || head == NULL)
        {
            head = baru;
            tail = baru;
            j++;
        }
        else
        {
            tail->next = baru;
            baru->before = tail;
            tail = baru;
            j++;
        }
        printf(" | Ingin input lagi (y/n)? : ");
        scanf("%s", &conf);
    } while (conf == 'y');
}
void tampil_fifo()
{
    struct simpul *show;

    show = head;
    int i = 1;
    printf(" + ---------------------------------------- +\n");
    printf(" | #   NRP\t Nama\n");
    while (show != NULL)
    {
        printf(" | %d. [%d]\t %s\n", i, show->nrp, show->nama);
        show = show->next;
        i++;
    }
    lanjutkan();
}
void tampil_lifo()
{
    struct simpul *show;

    show = tail;
    int i = 1;
    printf(" + ---------------------------------------- +\n");
    printf(" | #   NRP\t Nama\n");
    while (show != NULL)
    {
        printf(" | %d. [%d]\t %s\n", i, show->nrp, show->nama);
        show = show->before;
        i++;
    }
    lanjutkan();
}
void cari_data()
{
    struct simpul *cari = head;
    char keynm[25];
    int key, op, ketemu = 0;
    printf(" + ---------------------------------------- +\n");
    printf(" | [1] Berdasarkan nama\n");
    printf(" | [2] Berdasarkan NRP\n");
    printf(" | Masukkan option : ");
    scanf("%d", &op);
    printf(" + ---------------------------------------- +\n");
    if (op == 1)
    {
        printf(" | Masukkan nama : ");
        scanf("%s", &keynm);
        while (cari != NULL)
        {
            if (strcmp(cari->nama, keynm) == 0)
            {
                ketemu = 1;
                printf("\n | [%d] %s\n", cari->nrp, cari->nama);
            }
            cari = cari->next;
        }
    }
    if (op == 2)
    {
        printf(" | Masukkan NRP : ");
        scanf("%d", &key);
        while (cari != NULL)
        {
            if (cari->nrp == key)
            {
                ketemu = 1;
                printf("\n | [%d] %s\n", cari->nrp, cari->nama);
            }
            cari = cari->next;
        }
    }

    if (ketemu == 0)
        printf("\n | Data tidak ditemukan");
    lanjutkan();
}
void hapus()
{
    int key, op, ketemu = 0;
    struct simpul *del = head;

    if (del != NULL)
    {
        printf(" + ---------------------------------------- +\n");
        printf(" | [1] Menghapus awal data (%d - %s)\n", head->nrp, head->nama);
        printf(" | [2] Menghapus akhir data (%d - %s)\n", tail->nrp, tail->nama);
        printf(" | [3] Menghapus data tertentu\n");
        printf(" | Masukkan option : ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            if (del->nrp == head->nrp)
            {
                printf("\n | Anda telah menghapus NRP %d dengan nama %s", del->nrp, del->nama);
                ketemu = 1;
                if (head == tail) {
                    head = NULL;
                    tail = NULL;
                    free(del);
                } else {
                    head = head->next;
                    head->before = NULL;
                    free(del);
                }
            }
            break;
        case 2:
            del = tail;
            if (del->nrp == tail->nrp)
            {
                printf("\n | Anda telah menghapus NRP %d dengan nama %s", del->nrp, del->nama);
                ketemu = 1;
                if (tail == head) {
                    tail = NULL;
                    head = NULL;
                    free(del);
                } else {
                    tail = tail->before;
                    tail->next = NULL;
                    free(del);
                }
            }

            break;
        case 3:
            printf(" | Masukkan NRP data untuk dihapus : ");
            scanf("%d", &key);

            while (del != NULL)
            {
                if (del->nrp == key)
                {
                    ketemu = 1;
                    if (del == head || del == tail)
                        printf("\n | Data yang anda pilih berada diujung. Pilih opsi lain!");
                    else
                    {
                        printf("\n | Anda telah menghapus NRP %d dengan nama %s", del->nrp, del->nama);
                        del->before->next = del->next;
                        del->next->before = del->before;
                        free(del);
                    }
                    break;
                }
                del = del->next;
            }
            break;
        default:
            break;
        }
    }
    
    if (ketemu != 1)
        printf("\n | Data tidak ditemukan");
    lanjutkan();
}
void simpan_start()
{
    struct simpul *cari = head;
    struct simpul *data = alokasi_simpul();
    printf(" + ---------------------------------------- +\n");
    printf(" | Nama\t: ");
    scanf("%s", &data->nama);
    printf(" | NRP\t: ");
    scanf("%d", &data->nrp);

    head->before = data;
    data->next = head;
    head = data;
    lanjutkan();
}
void simpan_end()
{
    struct simpul *cari = head;
    struct simpul *data = alokasi_simpul();
    printf(" + ---------------------------------------- +\n");
    printf(" | Nama\t: ");
    scanf("%s", &data->nama);
    printf(" | NRP\t: ");
    scanf("%d", &data->nrp);

    while (cari->next != NULL)
    {
        cari = cari->next;
    }
    tail->next = data;
    data->before = tail;
    tail = data;
    lanjutkan();
}
void simpan_stl()
{
    struct simpul *data = alokasi_simpul();
    struct simpul *stl = head;
    char keynm[25];
    int ketemu = 0;

    printf(" | Masukkan nama yang setelahnya akan ditambah data baru\n | Input : ");
    scanf("%s", &keynm);
    while (stl != NULL)
    {
        if (strcmp(stl->nama, keynm) == 0)
        {
            ketemu = 1;
            if (stl == tail)
            {
                printf("\n | Data yang anda pilih berada diujung! pilih opsi lain(7)");
                break;
            }
            printf(" + ---------------------------------------- +\n");
            printf(" | Nama\t: ");
            scanf("%s", &data->nama);
            printf(" | NRP\t: ");
            scanf("%d", &data->nrp);
            data->before = stl;
            data->next = stl->next;
            stl->next->before = data;
            stl->next = data;
        }
        stl = stl->next;
    }
    if (ketemu != 1)
        printf("\n | Data tidak ditemukan");

    lanjutkan();
}
void simpan_sbl()
{
    struct simpul *data = alokasi_simpul();
    struct simpul *sbl = head;
    char keynm[25];
    int ketemu = 0;

    printf(" | Masukkan nama yang sebelumnya akan ditambah data baru\n | Input : ");
    scanf("%s", &keynm);
    while (sbl != NULL)
    {
        if (strcmp(sbl->nama, keynm) == 0)
        {
            ketemu = 1;
            if (sbl == head) {
                printf("\n | Data yang anda pilih berada diujung! pilih opsi lain(6)");
                break;
            }
            printf(" + ---------------------------------------- +\n");
            printf(" | Nama\t: ");
            scanf("%s", &data->nama);
            printf(" | NRP\t: ");
            scanf("%d", &data->nrp);
            data->next = sbl;
            data->before = sbl->before;
            sbl->before->next = data;
            sbl->before = data;
        }
        sbl = sbl->next;
    }
    if (ketemu != 1) 
        printf("\n | Data tidak ditemukan");

    lanjutkan();
}
int main()
{
    int op, keluar = 0;
    while (keluar == 0)
    {
        printf(" + ---------------------------------------- +\n");
        printf(" |            Double Linked List            |\n");
        printf(" + ---------------------------------------- +\n");
        printf(" | [1] Masukkan data\n");
        printf(" | [2] Tampilkan data (FIFO)\n");
        printf(" | [3] Tampilkan data (LIFO)\n");
        printf(" | [4] Hapus data\n");
        printf(" | [5] Mencari data\n");
        printf(" | [6] Masukkan data di awal\n");
        printf(" | [7] Masukkan data di akhir\n");
        printf(" | [8] Masukkan data setelah simpul tertentu\n");
        printf(" | [9] Masukkan data sebelum simpul tertentu\n");
        printf(" | [10] Exit\n");
        printf(" | Masukkan option : ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            simpan();
            system("cls");
            break;
        case 2:
            tampil_fifo();
            break;
        case 3:
            tampil_lifo();
            break;
        case 4:
            hapus();
            break;
        case 5:
            cari_data();
            break;
        case 6:
            simpan_start();
            break;
        case 7:
            simpan_end();
            break;
        case 8:
            simpan_stl();
            break;
        case 9:
            simpan_sbl();
            break;
        case 10:
            printf("\n | Exit Program");
            keluar = 1;
            break;
        default:
            printf("\n | Option yang anda masukkan salah!");
            lanjutkan();
            break;
        }
    }

    fflush(stdin);
    printf("\n | Press enter to exit...");
    getchar();
}