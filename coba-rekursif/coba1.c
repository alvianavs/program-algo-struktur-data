#include <stdio.h>

int faktorial(int x)
{
    if (x == 1)
        return x;
    else
    {
        printf("x = %d", x);
        return x * faktorial(x - 1);
    }
}

int main()
{
    int N;
    printf(" Masukkan N : ");
    scanf("%d", &N);
    printf(" Hasil %d! = %d\n", N, faktorial(N));

    fflush(stdin);
    printf(" Press enter to exit..");
    getchar();
}