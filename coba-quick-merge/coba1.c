#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define MAX 20

int Partition(int arr[], int p, int r)
{
    int i, j, pivot, tmp;
    pivot = arr[p];
    i = p;
    j = r;
    while (i <= j)
    {
        while (pivot < arr[j])
            j--;
        while (pivot > arr[i])
            i++;
        if (i < j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            j--;
            i++;
        }
        else
            return j;
    }
    return j;
}
void QuickSort(int arr[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = Partition(arr, p, r);
        QuickSort(arr, p, q);
        QuickSort(arr, q + 1, r);
    }
}
int main()
{
    int data_awal[MAX], data_urut[MAX];
    int i;
    struct timeval start, end;

    printf("Quick Sort secara ascending\n\n");
    printf("Sebelum pengurutan : \n");
    for (i = 0; i < MAX; i++)
    {
        srand(time(NULL) * (i + 1));
        data_awal[i] = rand() % 100 + 1;
        printf("%d ", data_awal[i]);
    }
    printf("\nSetelah pengurutan (Asc) : \n");
    for (i = 0; i < MAX; i++)
        data_urut[i] = data_awal[i];

    gettimeofday(&start, 0);
    QuickSort(data_urut, 0, MAX - 1);
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double elapsed = seconds + microseconds * 1e-6;
    for (i = 0; i < MAX; i++)
        printf("%d ", data_urut[i]);
    printf("\nWaktu = %.3f seconds\n", elapsed);

    printf("Press enter to exit...");
    getchar();
}
