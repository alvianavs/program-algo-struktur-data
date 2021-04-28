#include <stdio.h>

int faktorial(int x, int a)
{
    if (x == 1)
        return a;
    else
    {
        return faktorial(x - 1, x * a);
        printf("x = %d, a = %d\n", x, a);
    }
}

int main()
{
    int N;
    printf(" Masukkan N : ");
    scanf("%d", &N);
    printf(" Hasil %d! = %d\n", N, faktorial(N, 1));

    fflush(stdin);
    printf(" Press enter to exit..");
    getchar();
}