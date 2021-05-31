#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX 20
void BubbleSortFlagAsc(int arr[])
{
    int i = 0, j, temp;
    bool did_swap = true;

    while (i < MAX - 1 && did_swap)
    {
        for (j = 0; j < MAX - i - 1; j++)
        {
            did_swap = false;
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                did_swap = true;
            }
        }
        i++;
    }
}
void BubbleSortFlagDesc(int arr[])
{
    int i = 0, j, temp;
    bool did_swap = true;

    while (i < MAX - 1 && did_swap)
    {
        for (j = 0; j < MAX - i - 1; j++)
        {
            did_swap = false;
            if (arr[j] < arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                did_swap = true;
            }
        }
        i++;
    }
}

int main()
{
    int data_awal[MAX], data_urut[MAX];
    int i;
    printf("Latihan 2 Bubble Sort dengan Flag\n\nSebelum pengurutan : \n");
    for (i = 0; i < MAX; i++)
    {
        srand(time(NULL) * (i + 1));
        data_awal[i] = rand() % 100 + 1;
        printf("%d ", data_awal[i]);
    }
    printf("\nSetelah pengurutan (Desc) : \n");
    for (i = 0; i < MAX; i++)
        data_urut[i] = data_awal[i];

    int k1 = clock();
    BubbleSortFlagDesc(data_urut);
    int k2 = clock();
    for (i = 0; i < MAX; i++)
        printf("%d ", data_urut[i]);
    printf("\nWaktu = %f\n", (float)(k2 - k1) / CLOCKS_PER_SEC);

    fflush(stdin);
    printf("Press enter to exit...");
    getchar();
}
