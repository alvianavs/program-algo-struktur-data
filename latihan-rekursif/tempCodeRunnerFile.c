#include <stdio.h>

void kombinasi();

int main()
{
    int n;
    char K[] = "abcdefghij";
    printf("Jumlah karakter : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c", K[j]);
        }
        printf(" ");
        
    }
    
    fflush(stdin);
    printf("\n\nPress enter to exit...");
    getchar();
}