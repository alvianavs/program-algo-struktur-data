#include <stdio.h>

int paskal(int n, int i)
{
    if (n == i || i == 0)
        return 1;
    else
        return paskal(n - 1, i) + paskal(n - 1, i - 1);
}

int main()
{
    int R, n;
    printf("Masukkan nilai n : ");
    scanf("%d", &n);

    for (int k = 0; n >= k; k++)
    {
        printf("K%d\t", k+1);
        for (int s = 1; s <= n - k; s++)
            printf("  ");
        for (int m = 0; m <= k; m++)
        {
            R = paskal(k, m);
            printf("%3d ", R);
        }
        printf("\n");
    }

    fflush(stdin);
    printf("\n\nPress enter to exit..");
    getchar();
    return 0;
}