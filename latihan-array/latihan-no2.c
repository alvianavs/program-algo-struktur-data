#include <stdio.h>
#define N 2

int main()
{
    int result[N][N], i, j;
    int matrix1[N][N] = {{12,7},{54,24}};
    int matrix2[N][N] = {{35,31},{40,19}};

    printf("\nPenjumlahan");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("\n%d + %d = %d", matrix1[i][j], matrix2[i][j], result[i][j]);
        }
    }

    printf("\n\nPengurangan");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
            printf("\n%d - %d = %d",
            matrix1[i][j], matrix2[i][j], result[i][j]);
        }
    }

    printf("\n\nPerkalian");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            result[i][j] = matrix1[i][j] * matrix2[i][j];
            printf("\n%d x %d = %d",
            matrix1[i][j], matrix2[i][j], result[i][j]);
        }
    }
}
