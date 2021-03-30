#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, *fibo, i;

    printf("Masukkan nilai n : ");
    scanf("%d", &N);
    fibo = (int *)malloc(N*sizeof(int));
    if (fibo == NULL) {
        printf("\nMalloc gagal");
        exit(0);
    } else {
        *fibo = 1;
        *(fibo + 1) = 1;
        for (i = 2; i < N; i++)
            *(fibo+i) = *(fibo+i-1) + *(fibo+i-2);
        printf("%d bilangan fibonaci : ", N);
        for (i = 0; i < N; i++)
            printf("%d ", *(fibo+i));
    }
    free(fibo);

    fflush(stdin);
    printf("\n\nPress enter to exit...");
    getchar();
}
