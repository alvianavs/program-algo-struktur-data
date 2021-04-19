#include <stdio.h>

int fibo(int x)
{
    if (x <= 0 || x <= 1)
        return x;
    else
        return fibo(x - 2) + fibo(x - 1);
}

int main()
{
    int N;
    printf("Masukkan jumlah deret : ");
    scanf("%d", &N);
    printf("Deret fibonanci dari %d = ", N);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", fibo(i));
    }

    fflush(stdin);
    printf("\n\nPress enter to exit..");
    getchar();
}