#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
void InsertionSortAsc(int arr[])
{
    int i, j, key;
    for (i = MAX - 2; i >= 0; i--)
    {
        key = arr[i];
        j = i + 1;
        while (j < MAX && arr[j] < key)
        {
            arr[j - 1] = arr[j];
            j++;
        }
        arr[j - 1] = key;
    }
}
void InsertionSortDesc(int arr[])
{
    int i, j, key;
    for (i = MAX - 2; i >= 0; i--)
    {
        key = arr[i];
        j = i + 1;
        while (j < MAX && arr[j] > key)
        {
            arr[j - 1] = arr[j];
            j++;
        }
        arr[j - 1] = key;
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

    InsertionSortAsc(data_urut);
    printf("\n\nInsertion secara Ascending\n");
    for (i = 0; i < MAX; i++)
        printf("%d ", data_urut[i]);
    InsertionSortDesc(data_urut);
    printf("\n\nInsertion secara Descending\n");
    for (i = 0; i < MAX; i++)
        printf("%d ", data_urut[i]);

    fflush(stdin);
    printf("\n\nPress enter to exit...");
    getchar();
}
