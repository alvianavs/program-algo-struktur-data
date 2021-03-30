#include <stdio.h>
#include <stdlib.h>

void funPrima(int *prima, int n)
{
    int i, j, cek;
    if (prima == NULL)
    {
        printf("\nMalloc gagal");
        exit(0);
    }
    else {
        for (i = 2; i <= n; i++)
        {
            cek = 0;
            *prima = i;
            for (j = 2; j < i; j++)
            {
                if (*prima % j == 0)
                    cek = 1;
            }
            if (cek == 0)
                printf("%d ", *prima);
        }
        printf("\nAlamat : %u", prima);
    }
}
int main()
{
    int n, m, *prima;

    printf("Bilangan Prima menggunakan Malloc dan Realloc\n");

    printf("\nMasukkan nilai n (Malloc) : ");
    scanf("%d", &n);
    prima = (int *)malloc(n * sizeof(int));
    funPrima(prima, n);

    printf("\nMasukkan nilai m (Realloc) : ");
    scanf("%d", &m);
    prima = (int *) realloc(prima, m * sizeof(int));
    funPrima(prima, m);

    free(prima);

    fflush(stdin);
    printf("\n\nPress enter to exit...");
    getchar();
}
