#include <stdio.h>

long kombinasi(int i, int j, int k, int n)
{
    if (n == 0)
        return 0;
    else
        return kombinasi(i, j, k, n);
}

int main()
{
    int n, R;
    char K[] = "abcdefghij";
    printf("Jumlah karakter : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                R = kombinasi(i, j, k, n);
                printf("%c ", K[R]);
                // printf("%c%c%c", K[i], K[j], K[k]);
            }
        }
    }
    
    fflush(stdin);
    printf("\n\nPress enter to exit...");
    getchar();
}