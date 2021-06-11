#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 10

struct Pegawai
{
    int nip;
    char nama[25];
    char alamat[100];
    char gol[10];
};
struct Pegawai Data[MAX] = {
    {7723, "Adit", "Ponorogo", "L"},
    {6232, "Denis", "Malang", "L"},
    {2345, "Siti", "Ngawi", "P"},
    {4352, "Niwa", "Mojokerto", "P"},
    {2883, "Uki", "Jogja", "L"}
    };
void Tukar(struct Pegawai *a, struct Pegawai *b)
{
    struct Pegawai temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void QuickSort(int L, int R)
{
    int i, j, x;
    x = Data[(L + R) / 2].nip;
    i = L;
    j = R;
    while (i <= j)
    {
        while (Data[i].nip < x)
            i++;
        while (Data[j].nip > x)
            j--;
        if (i <= j)
        {
            Tukar(&Data[i], &Data[j]);
            i++;
            j--;
        }
    }
    if (L < j)
        QuickSort(L, j);
    if (i < R)
        QuickSort(i, R);
}
int BinarySearch(int x, char xnama[25], int opkey)
{
    int L = 0, R = MAX - 1, m;
    bool ketemu = false;
    while ((L <= R) && (!ketemu))
    {
        m = (L + R) / 2;
        if (opkey == 1)
        {
            if (strcmp(Data[m].nama, xnama) == 0)
                ketemu = true;
            else
            {
                if (xnama < Data[m].nama)
                    R = m - 1;
                else
                    L = m + 1;
            }
        } else {
            if (Data[m].nip == x)
                ketemu = true;
            else
            {
                if (x < Data[m].nip)
                    R = m - 1;
                else
                    L = m + 1;
            }
        }
        
    }
    if (ketemu)
        return m;
    else
        return -1;
}
int SequentialSearch(char xnama[25], int x, int opkey)
{
    int i = 0;
    bool ketemu = false;
    
    while ((!ketemu) && (i < MAX))
    {
        if (opkey == 1) // mencari nama
        {
            if (strcmp(Data[i].nama, xnama) == 0)
            {
                ketemu = true;
            }
            
        } else {
            if (Data[i].nip == x) // mencari nip
            {
                ketemu = true;
            }
        }
        i++;
    }
    if (ketemu)
        return i = i - 1;
    else
        return -1;
}
void Tampil(int index)
{
    if (index >= 0)
    {
        printf("\nData Pegawai:");
        printf("\nNIP\t\t: %d", Data[index].nip);
        printf("\nNama\t\t: %s", Data[index].nama);
        printf("\nAlamat\t\t: %s", Data[index].alamat);
        printf("\nGol\t\t: %s", Data[index].gol);
    } else
        printf("\nData tidak ditemukan!");
}
int main()
{
    char keynama[25];
    int metod, opkey, ketemu, keynip;
    char conf;
    do
    {
        printf("\nPENCARIAN DATA PEGAWAI");
        printf("\n+--------------------------------------+");
        printf("\n1. Sequential Search\n2. Binary Search");
        printf("\nMasukkan metode yg dipilih: ");
        scanf("%d", &metod);
        printf("\n1. Pencarian berdasarkan nama\n2. Berdasarkan NIP");
        printf("\nMasukkan pilihan: ");
        scanf("%d", &opkey);
        if (opkey == 1)
        {
            printf("\nMasukkan nama: ");
            scanf("%s", &keynama);
        }
        else
        {
            printf("\nMasukkan NIP: ");
            scanf("%d", &keynip);
        }
        switch (metod)
        {
        case 1:
            ketemu = SequentialSearch(keynama, keynip, opkey);
            Tampil(ketemu);
            break;
        case 2:
            QuickSort(0, MAX - 1);
            ketemu = BinarySearch(keynip, keynama, opkey);
            Tampil(ketemu);
            break;

        default:
            printf("\nOption yg anda masukkan salah!");
            break;
        }
        fflush(stdin);
        printf("\nIngin melanjutkan? (y/n): ");
        scanf("%s", &conf);
    } while (conf == 'y');
    
    fflush(stdin);
    printf("\n\nPress enter to exit..");
    getchar();
    return 0;
}
