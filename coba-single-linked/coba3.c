#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct simpul
{
    char nama[25];
    int nrp;
    struct simpul *next;
} simpul;
struct simpul *ujung;

struct simpul *alokasi_simpul()
{
    struct simpul *new_val;
    new_val = (struct simpul *)malloc(sizeof(struct simpul));
    if (new_val == NULL)
        return NULL;
    else
        new_val->next = NULL;
    return new_val;
}

struct simpul *add(struct simpul *head)
{
    struct simpul *ujung;
    ujung = alokasi_simpul();
    if (ujung == NULL)
        printf("Alokasi gagal");
    else
    {
        printf("Nama :");
        scanf("%s", &ujung->nama);
        printf("NRP :");
        scanf("%d", &ujung->nrp);
    }
    ujung->next = head;
    return ujung;
}
struct simpul *add_for_lifo(struct simpul *head, struct simpul *ujung)
{
    struct simpul *temp = alokasi_simpul();
    strcpy(temp->nama, ujung->nama);
    temp->nrp = ujung->nrp;
    temp->next = head;
    return temp;
}

struct simpul *add_end(struct simpul *head)
{
    struct simpul *kembali = head;
    struct simpul *ujung = alokasi_simpul();
    if (ujung == NULL)
        printf("Alokasi gagal");
    else
    {
        printf("Nama :");
        scanf("%s", &ujung->nama);
        printf("NRP :");
        scanf("%d", &ujung->nrp);
    }
    if (head == NULL)
    {
        kembali = ujung;
    }
    else
    {
        while (head->next != NULL)
        {
            head = head->next;
        }
        head->next = ujung;
    }
    return kembali;
}

struct simpul *add_after(struct simpul *head)
{
    struct simpul *kembali = head;
    struct simpul *ujung = head;
    struct simpul *data = alokasi_simpul();
    struct simpul *sbl;
    char nama[25];
    printf("cari data berdasarkan nama : ");
    scanf("%s", &nama);

    printf("Nama :");
    scanf("%s", &data->nama);
    printf("NRP :");
    scanf("%d", &data->nrp);

    printf("%s \n", &ujung->nama);

    while (strcmp(ujung->nama, nama) != 0)
    {
        sbl = ujung;
        ujung = ujung->next;
    }
    data->next = ujung->next;
    ujung->next = data;
    return kembali;
}

struct simpul *add_before(struct simpul *head)
{
    struct simpul *kembali = head;
    struct simpul *ujung = head;
    struct simpul *data = alokasi_simpul();
    struct simpul *sbl;
    char nama[25];
    printf("cari data berdasarkan nama : ");
    scanf("%s", &nama);

    printf("Nama :");
    scanf("%s", &data->nama);
    printf("NRP :");
    scanf("%d", &data->nrp);

    printf("%s \n", &ujung->nama);
    int i = 0;
    while (strcmp(ujung->nama, nama) != 0)
    {
        sbl = ujung;
        ujung = ujung->next;
        i++;
    }
    if (i == 0)
    {
        data->next = kembali;
        return data;
    }
    else
    {
        data->next = ujung;
        sbl->next = data;
    }
    return kembali;
}

struct simpul *hapus(struct simpul *head)
{

    char nama[25];
    printf("cari data berdasarkan nama : ");
    scanf("%s", &nama);
    struct simpul *kembali = head;
    struct simpul *hapus = head;
    struct simpul *sbl;
    int i = 0;
    if (head == NULL)
    {
        printf("\n------------\nLinked List kosong\n------------\n\n");
    }
    else
    {
        while (strcmp(hapus->nama, nama) != 0)
        {
            sbl = hapus;
            hapus = hapus->next;
            i++;
        }
        if (i == 0)
        {
            sbl = hapus->next;
            return sbl;
        }
        else
        {
            sbl->next = hapus->next;
        }
        free(hapus);
    }
    return kembali;
}

void tampil(struct simpul *tampil)
{
    int i = 1;
    printf("\n==================\n");
    while (tampil != NULL)
    {
        printf("%d. %s  --- %d\n", i, tampil->nama, tampil->nrp);
        tampil = tampil->next;
        i++;
    }
    printf("\n==================\n");
}

void tampil_lifo(struct simpul *tampil)
{
    int i = 1;
    struct simpul *ujung = alokasi_simpul();

    if (tampil == NULL)
    {
        printf("Data kosong !!!\n");
    }
    else
    {
        while (tampil != NULL)
        {
            ujung = add_for_lifo(ujung, tampil);
            tampil = tampil->next;
        }

        printf("\n==================\n");
        while (ujung->next != NULL)
        {
            printf("%d. %s  --- %d\n", i, ujung->nama, ujung->nrp);
            ujung = ujung->next;
            i++;
        }
        printf("\n==================\n");
    }
}

void cari_berdasarkan_nama(struct simpul *tampil)
{
    char nama[25];
    printf("cari data berdasarkan nama : ");
    scanf("%s", &nama);
    int flag = 0;
    int i = 1;
    while (tampil != NULL)
    {
        if (strcmp(nama, tampil->nama) == 0)
        {
            flag = 1;
            printf("%s Ketemu !!!!\nBerada di data ke-%d\n", tampil->nama, i);
        }
        i++;
        tampil = tampil->next;
    }

    if (flag == 0)
    {
        printf("Data tidak tersedia\n");
    }
}

int main()
{
    while (1)
    {
        int pil;
        printf("1. Cari berdasarkan nama \n"
               "2. Tampil Semua \n"
               "3. Tampil LIFO \n"
               "4. Tambah Diawal \n"
               "5. Tambah Diakhir \n"
               "6. Hapus data \n"
               "7. Add After \n"
               "8. Add Before \n"
               "9. Keluar \nPilihan : ");
        scanf("%d", &pil);

        switch (pil)
        {
        case 1:
            cari_berdasarkan_nama(ujung);
            break;
        case 2:
            tampil(ujung);
            break;
        case 3:
            tampil_lifo(ujung);
            break;
        case 4:
            ujung = add(ujung);
            break;
        case 5:
            ujung = add_end(ujung);
            break;
        case 6:
            ujung = hapus(ujung);
            break;
        case 7:
            ujung = add_after(ujung);
            break;
        case 8:
            ujung = add_before(ujung);
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Perintah Tidak ditemukan.\n");
            break;
        }
    }
    fflush(stdin);
    printf("\n\nPress enter to exit");
    getchar();
    return 0;
}