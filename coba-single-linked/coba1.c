#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct simpul
{
    char nama[25];
    int nrp;
    struct simpul *next;
};
struct simpul *ujung;
struct simpul *tampung;
struct simpul *show;
struct simpul *cari;
int j = 0;

struct simpul *alokasi_simpul()
{
    struct simpul *baru;
    baru = (struct simpul *)malloc(sizeof(struct simpul));
    if (baru == NULL)
        return NULL;
    else
        baru->next = NULL;
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
    printf(" + ------------------- \n");
    do
    {
        ujung = alokasi_simpul();
        printf(" | Nama\t: ");
        scanf("%s", &ujung->nama);
        printf(" | NRP\t: ");
        scanf("%d", &ujung->nrp);

        if (j == 0)
        {
            ujung->next = NULL;
            tampung = ujung;
            j++;
        }
        else
        {
            ujung->next = tampung;
            tampung = ujung;
            j++;
        }
        printf(" | Ingin input lagi (y/n)? : ");
        scanf("%s", &conf);
    } while (conf == 'y');
}
void tampil()
{
    show = ujung;
    int i = 1;
    printf("\n #  NRP\t Nama\n");
    while (show != NULL) {
        printf(" %d. [%d] %s\n", i, show->nrp, show->nama);
        show = show->next;
        i++;
    }
    lanjutkan();
}
void funcCari()
{
    char keynm[25];
    int key, op, ketemu = 0;
    cari = ujung;

    printf(" | [1] Berdasarkan nama\n");
    printf(" | [2] Berdasarkan NRP\n");
    printf(" | Masukkan option : ");
    scanf("%d", &op);
    if (op == 1) {
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
    if (op == 2) {
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
        printf("\n | data tidak ditemukan");
    lanjutkan();
}
void hapus()
{
    int key, ketemu = 0;
    struct simpul *sbl, *del;

    printf(" | Masukkan NRP data untuk dihapus : ");
    scanf("%d", &key);

    del = ujung;
    while (del != NULL)
    {
        if (del->nrp == key) {
            ketemu = 1;
            printf("\n | Anda menghapus NRP %d dengan nama %s", del->nrp, del->nama);
            if (del == ujung)
                ujung = ujung->next;
            else
                sbl->next = del->next;
        }
        sbl = del;
        del = del->next;
    }
    if (ketemu != 1)
        printf("\n | Data tidak ditemukan");
    free(del);
    lanjutkan();
}
void simpanAfter()
{
    cari = ujung;
    struct simpul *data;
    data = alokasi_simpul();
    char keynm[25];
    int ketemu = 0;

    printf(" | Masukkan nama yang setelahnya akan ditambah baru data\n | Input : ");
    scanf("%s", &keynm);

    printf(" + ------------------- \n");
    printf(" | Nama\t: ");
    scanf("%s", &data->nama);
    printf(" | NRP\t: ");
    scanf("%d", &data->nrp);

    while (cari != NULL)
    {
        if (strcmp(cari->nama, keynm) == 0) {
            ketemu = 1;
            data->next = cari->next;
            cari->next = data;
        }
        cari = cari->next;
    }
    if (ketemu != 1)
        printf("\n | Data tidak ditemukan");
    free(data);
    lanjutkan();
}
int main()
{
    int op, keluar = 0;
    while (keluar == 0)
    {
        printf(" | [1] Masukkan data\n");
        printf(" | [2] Tampilkan data\n");
        printf(" | [3] Hapus data tertentu\n");
        printf(" | [4] Mencari data\n");
        printf(" | [5] Masukkan data setelah simpul tertentu\n");
        printf(" | [6] Exit\n");
        printf(" | Masukkan option : ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            simpan();
            system("cls");
            break;
        case 2:
            tampil();
            break;
        case 3:
            hapus();
            break;
        case 4:
            funcCari();
            break;
        case 5:
            simpanAfter();
            break;
        case 6:
            printf("\n | Exit Program");
            keluar = 1;
            break;
        default:
            printf("\n | Option yang anda masukkan salah!\n");
            break;
        }
    }
    
    fflush(stdin);
    printf("\n\nPress enter to exit");
    getchar();
}