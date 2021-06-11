#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

int Data[MAX], comp = 0;
int SequentialSearch(int x)
{
    int i = 0;
    bool ketemu = false;

    while ((!ketemu) && (i < MAX))
    {
        comp++;
        if (Data[i] == x)
        {
            ketemu = true;
        }
        i++;
    }
    if (ketemu)
        return i;
    else
        return -1;
}
int main()
{
    int i;
    //pembangkit bilangan random
    srand(0);
    //membangkitkan bilangan integer random
    printf("\nDATA : ");
    for (i = 0; i < MAX; i++)
    {
        Data[i] = rand() / 1000 + 1;
        printf("%d ", Data[i]);
    }
    int Kunci;
    printf("\nKunci : ");
    scanf("%d", &Kunci);
    int ketemu = SequentialSearch(Kunci);
    if (ketemu > 0)
        printf("Data ditemukan pada posisi %d", ketemu);
    else
        printf("Data tidak ditemukan");

    printf("\nJumlah perbadingan : %d", comp);
    fflush(stdin);
    printf("\n\nPress enter to exit..");
    getchar();
    return 0;
}
