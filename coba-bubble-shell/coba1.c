#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20
void BubbleSort(int arr[])
{
    int i, j, temp;
    for (i = 0; i < MAX - 1; i++)
    {
        for (j = 0; j < MAX - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main()
{
    int data_awal[MAX], data_urut[MAX];
    int i;
    printf("Bubble Sort\n\nSebelum pengurutan : \n");
    for (i = 0; i < MAX; i++)
    {
        srand(time(NULL) * (i + 1));
        data_awal[i] = rand() % 100 + 1;
        printf("%d ", data_awal[i]);
    }
    printf("\nSetelah pengurutan (Asc) : \n");
    for (i = 0; i < MAX; i++)
        data_urut[i] = data_awal[i];

    int k1 = clock();
    BubbleSort(data_urut);
    int k2 = clock();
    for (i = 0; i < MAX; i++)
        printf("%d ", data_urut[i]);
    printf("\nWaktu = %f\n", (float)(k2 - k1) / CLOCKS_PER_SEC);

    fflush(stdin);
    printf("Press enter to exit...");
    getchar();
}
