#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#define MAX 100

int data_awal[MAX], data_urut[MAX];
struct timeval start, end;

void randData(int opsort)
{
    int i;
    printf("Sebelum pengurutan :\n");
    for (i = 0; i < MAX; i++)
    {
        srand(time(NULL) * (i + 1));
        data_awal[i] = rand() % 100 + 1;
        printf("%d ", data_awal[i]);
    }
    if (opsort == 1)
        printf("\nSetelah pengurutan (Asc) : \n");
    else
        printf("\nSetelah pengurutan (Desc) : \n");
    for (i = 0; i < MAX; i++)
        data_urut[i] = data_awal[i];
}
void tampilData()
{
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double elapsed = seconds + microseconds * 1e-6;
    for (int i = 0; i < MAX; i++)
        printf("%d ", data_urut[i]);
    printf("\n\nwaktu %.3f seconds\n", elapsed);
}
void InsertionSortAsc(int arr[])
{
    int i, j, key;
    for (i = 1; i < MAX; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void InsertionSortDesc(int arr[])
{
    int i, j, key;
    for (i = 1; i < MAX; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void SelectionSortAsc(int arr[])
{
    int i, j, temp, max, max_id;
    i = 0;
    while (i < MAX - 1)
    {
        max_id = i;
        max = arr[i];
        for (j = i + 1; j < MAX; j++)
            if (arr[j] < max)
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
void BubbleSortAsc(int arr[])
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
void BubbleSortDesc(int arr[])
{
    int i, j, temp;
    for (i = 0; i < MAX - 1; i++)
    {
        for (j = 0; j < MAX - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
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
void ShellSortAsc(int arr[])
{
    int i, jarak, temp;
    bool did_swap = true;
    jarak = MAX;
    while (jarak > 1)
    {
        jarak = jarak / 2;
        did_swap = true;
        while (did_swap)
        {
            did_swap = false;
            i = 0;
            while (i < (MAX - jarak))
            {
                if (arr[i] > arr[i + jarak])
                {
                    temp = arr[i];
                    arr[i] = arr[i + jarak];
                    arr[i + jarak] = temp;
                    did_swap = true;
                }
                i++;
            }
        }
    }
}
void ShellSortDesc(int arr[])
{
    int i, jarak, temp;
    bool did_swap = true;
    jarak = MAX;
    while (jarak > 1)
    {
        jarak = jarak / 2;
        did_swap = true;
        while (did_swap)
        {
            did_swap = false;
            i = 0;
            while (i < (MAX - jarak))
            {
                if (arr[i] < arr[i + jarak])
                {
                    temp = arr[i];
                    arr[i] = arr[i + jarak];
                    arr[i + jarak] = temp;
                    did_swap = true;
                }
                i++;
            }
        }
    }
}

int PartitionAsc(int arr[], int p, int r)
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
int PartitionDesc(int arr[], int p, int r)
{
    int i, j, pivot, tmp;
    pivot = arr[p];
    i = p;
    j = r;
    while (i <= j)
    {
        while (pivot > arr[j])
            j--;
        while (pivot < arr[i])
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
void QuickSort(int arr[], int p, int r, int opsort)
{
    int q;
    if (p < r)
    {
        if (opsort == 1)
            q = PartitionAsc(arr, p, r);
        else
            q = PartitionDesc(arr, p, r);       
        QuickSort(arr, p, q, opsort);
        QuickSort(arr, q + 1, r, opsort);
    }
}

void MergeAsc(int arr[], int left, int median, int right)
{
    int temp[MAX];
    int kiri1, kanan1, kiri2, kanan2, i, j;
    kiri1 = left;
    kanan1 = median;
    kiri2 = median + 1;
    kanan2 = right;
    i = left;
    while ((kiri1 <= kanan1) && (kiri2 <= kanan2))
    {
        if (arr[kiri1] <= arr[kiri2])
        {
            temp[i] = arr[kiri1];
            kiri1++;
        }
        else
        {
            temp[i] = arr[kiri2];
            kiri2++;
        }
        i++;
    }
    while (kiri1 <= kanan1)
    {
        temp[i] = arr[kiri1];
        kiri1++;
        i++;
    }
    while (kiri2 <= kanan2)
    {
        temp[i] = arr[kiri2];
        kiri2++;
        i++;
    }
    j = left;
    while (j <= right)
    {
        arr[j] = temp[j];
        j++;
    }
}
void MergeDesc(int arr[], int left, int median, int right)
{
    int temp[MAX];
    int kiri1, kanan1, kiri2, kanan2, i, j;
    kiri1 = left;
    kanan1 = median;
    kiri2 = median + 1;
    kanan2 = right;
    i = left;
    while ((kiri1 <= kanan1) && (kiri2 <= kanan2))
    {
        if (arr[kiri1] >= arr[kiri2])
        {
            temp[i] = arr[kiri1];
            kiri1++;
        }
        else
        {
            temp[i] = arr[kiri2];
            kiri2++;
        }
        i++;
    }
    while (kiri1 <= kanan1)
    {
        temp[i] = arr[kiri1];
        kiri1++;
        i++;
    }
    while (kiri2 <= kanan2)
    {
        temp[i] = arr[kiri2];
        kiri2++;
        i++;
    }
    j = left;
    while (j <= right)
    {
        arr[j] = temp[j];
        j++;
    }
}
void MergeSort(int arr[], int l, int r, int opsort)
{
    int med;
    if (l < r)
    {
        med = (l + r) / 2;
        MergeSort(arr, l, med, opsort);
        MergeSort(arr, med + 1, r, opsort);
        if (opsort == 1)
            MergeAsc(arr, l, med, r);
        else
            MergeDesc(arr, l, med, r);
    }
}
int main()
{
    int op, opsort;
    char conf;

    printf("ALGORITMA SORTING\n");
    printf("1. Insertion\n2. Selection\n3. Bubble\n4. Bubble dengan Flag\n5. Shell\n6. Quick\n7. Merge\n");
    
    printf("Masukkan pilihan : ");
    scanf("%d", &op);
    printf("1. Ascending\n2. Descending\n");
    printf("Pilihan sorting : ");
    scanf("%d", &opsort);
    switch (op)
    {
    case 1:
        printf("\nInsertion Sort\n");
        randData(opsort);
        gettimeofday(&start, 0);
        if (opsort == 1)
            InsertionSortAsc(data_urut);
        else
            InsertionSortDesc(data_urut);
        gettimeofday(&end, 0);
        tampilData();
        break;
    case 2:
        printf("\nSelection Sort\n");
        randData(opsort);
        gettimeofday(&start, 0);
        if (opsort == 1)
            SelectionSortAsc(data_urut);
        else
            SelectionSortDesc(data_urut);
        gettimeofday(&end, 0);
        tampilData();
        break;
    case 3:
        printf("\nBubble Sort\n");
        randData(opsort);
        gettimeofday(&start, 0);
        if (opsort == 1)
            BubbleSortAsc(data_urut);
        else
            BubbleSortDesc(data_urut);
        gettimeofday(&end, 0);
        tampilData();
        break;
    case 4:
        printf("\nBubble Sort dengan Flag\n");
        randData(opsort);
        gettimeofday(&start, 0);
        if (opsort == 1)
            BubbleSortFlagAsc(data_urut);
        else
            BubbleSortFlagDesc(data_urut);
        gettimeofday(&end, 0);
        tampilData();
        break;
    case 5:
        printf("\nShell Sort\n");
        randData(opsort);
        gettimeofday(&start, 0);
        if (opsort == 1)
            ShellSortAsc(data_urut);
        else
            ShellSortDesc(data_urut);
        gettimeofday(&end, 0);
        tampilData();
        break;
    case 6:
        printf("\nQuick Sort\n");
        randData(opsort);
        gettimeofday(&start, 0);
        QuickSort(data_urut, 0, MAX - 1, opsort);
        gettimeofday(&end, 0);
        tampilData();
        break;
    case 7:
        printf("\nMerge Sort\n");
        randData(opsort);
        gettimeofday(&start, 0);
        QuickSort(data_urut, 0, MAX - 1, opsort);
        gettimeofday(&end, 0);
        tampilData();
        break;
    default:
        printf("\nOption yang anda masukkan salah!");
        break;
    }
    
    fflush(stdin);
    printf("\n\nPress enter to exit...");
    getchar();
}
