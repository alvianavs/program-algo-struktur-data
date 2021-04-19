#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *bil, i, j, n, hsl;
    printf("Masukkan batas bilangan : ");
    scanf("%d", &n);
    bil = (int *)malloc(n * sizeof(int));
    i = 0;
    hsl = 1;
    while (i < n)
    {
        if (hsl % 3 == 0)
        {
            hsl += 2;
            continue;
        }
        else
        {
            *(bil + i) = hsl;
            hsl += 2;
            i++;
        }
    }
    for (j = 0; j < n; j++)
        printf("%d ", *(bil + j));

    fflush(stdin);
    printf("\nPress enter to exit...");
    getchar();
}