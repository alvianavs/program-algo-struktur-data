#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, op, *C, *S, i;
    char conf;

    printf("1. Cn = 2Cn-1 + 1\n2. Sn = Sn-1 + n-1\n");
    printf("Pilih fungsi : ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        printf("\n<= Fungsi  Cn = 2Cn-1 + 1 =>\n");
        printf("Masukkan nilai n : ");
        scanf("%d", &n);
        C = (int *)malloc(n * sizeof(int));
        if (C == NULL)
            printf("\nMalloc gagal");
        else
        {
            *C = 1;
            for (i = 1; i < n; i++)
            {
                *(C + i) = 2 * *(C + i - 1) + 1;
            }
            printf("\nDeret rumus C : ");
            for (i = 0; i < n; i++)
            {
                printf("%d ", *(C + i));
            }
        }
        free(C);
        break;
    case 2:
        printf("\n<= Fungsi  Sn = Sn-1 + n-1 =>\n");
        printf("Masukkan nilai n : ");
        scanf("%d", &n);
        S = (int *)malloc(n * sizeof(int));
        if (S == NULL)
            printf("\nMalloc gagal");
        else
        {
            *S = 0;
            *(S + 1) = 0;
            for (i = 1; i < n; i++)
            {
                *(S + i) = *(S + i - 1) + i - 1;
            }
            printf("\nDeret rumus S : ");
            for (i = 0; i < n; i++)
            {
                printf("%d ", *(S + i));
            }
        }
        free(S);
        break;

    default:
        printf("\nOption yang anda masukkan salah");
        break;
    }
    
    fflush(stdin);
    printf("\n\nPress enter to exit...");
    getchar();
}
