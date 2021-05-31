#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 7000
void SelectionSortDesc(int arr[])
{
    int i, j, temp, max, max_id;
    i = 0;
    while (i < MAX - 1)
    {
        max_id = i;
        max = arr[i];
        for (j = i + 1; j < MAX; j++)
            if (arr[j] > max)
            {
                max = arr[j];
                max_id = j;
            }
        temp = arr[max_id];
        arr[max_id] = arr[i];
        arr[i] = temp;
        i++;
    }
}
int main()
{
    int data_awal[MAX], data_urut[MAX];
    int i;
    printf("Sebelum pengurutan : \n");
    for (i = 0; i < MAX; i++)
    {
        srand(time(NULL) * (i + 1));
        data_awal[i] = rand() % 100 + 1;
        printf("%d ", data_awal[i]);
    }
    printf("\nSetelah pengurutan : \n");
    for (i = 0; i < MAX; i++)
        data_urut[i] = data_awal[i];

    int k1 = clock();
    SelectionSortDesc(data_urut);
    int k2 = clock();
    for (i = 0; i < MAX; i++)
        printf("%d ", data_urut[i]);
    printf("\nWaktu = %f\n", (float)(k2 - k1) / CLOCKS_PER_SEC);

    fflush(stdin);
    printf("Press enter to exit...");
    getchar();
}
