#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
void SelectionSortAsc(int arr[])
{
    int i, j, temp, max, max_id;
    i = MAX - 1;
    while (i >= 0)
    {
        max_id = i;
        max = arr[i];
        for (j = i - 1; j >= 0; j--)
            if (arr[j] > max)
            {
                max = arr[j];
                max_id = j;
            }
        temp = arr[max_id];
        arr[max_id] = arr[i];
        arr[i] = temp;
        i--;
    }
}
void SelectionSortDesc(int arr[])
{
    int i, j, temp, min, min_id;
    i = MAX - 1;
    while (i >= 0)
    {
        min_id = i;
        min = arr[i];
        for (j = i - 1; j >= 0; j--)
            if (arr[j] < min)
            {
                min = arr[j];
                min_id = j;
            }
        temp = arr[min_id];
        arr[min_id] = arr[i];
        arr[i] = temp;
        i--;
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

    SelectionSortAsc(data_urut);
    printf("\nSelection secara Ascending\n");
    for (i = 0; i < MAX; i++)
        printf("%d ", data_urut[i]);

    SelectionSortDesc(data_urut);
    printf("\n\nSelection secara Descending\n");
    for (i = 0; i < MAX; i++)
        printf("%d ", data_urut[i]);

    fflush(stdin);
    printf("\n\nPress enter to exit...");
    getchar();
}
