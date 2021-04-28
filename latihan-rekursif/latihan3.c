#include <stdio.h>
#include <stdlib.h>

int bin_search(int arr[], int x, int low, int high)
{
    int mid;
    if (low > high)
        return -1;
    mid = (low + high) / 2;
    if (x == arr[mid])
    {
        return mid;
    }
    else if (x < arr[mid])
    {
        return bin_search(arr, x, low, mid - 1);
    }
    else
    {
        return bin_search(arr, x, mid + 1, high);
    }
}

int main()
{
    int key, posisi;
    int low, high;
    int data[] = {8, 14, 19, 24, 31, 37, 43, 49, 55, 62, 70};
    int size = sizeof(data) / sizeof(*data);

    printf("Data : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    low = 0;
    high = size - 1;
    printf("\nData yang ingin dicari : ");
    scanf("%d", &key);
    posisi = bin_search(data, key, low, high);
    if (posisi != -1)
    {
        printf("\nData %d berada pada index ke-%d", key, posisi);
    }
    else
        printf("\nData yang anda masukkan tidak ada");

    fflush(stdin);
    printf("\n\nPress enter to exit...");
    getchar();
    return 0;
}
