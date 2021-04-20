#include <stdio.h>

long paskal(int, int);

int main()
{
    int n = 0;
    int m = 0;
    int k = 0;
    int s = 0;
    printf("Enter number of rows:\n");
    scanf("%d", &n);

    for (k = 0; n >= k; k++)
    {
        for (s = 0; s < n - k; s++) //Add spaces before each row
            printf(" ");
        for (m = 0; k >= m; m++)
        {
            long f = paskal(k, m);
            printf("%ld ", f);
        }
        printf("\n");
    }

    fflush(stdin);
    printf("\n\nPress enter to exit..");
    getchar();
    return 0;
}

long paskal(int n, int i)
{
    if (n == i || i == 0)
        return 1;
    else
        return paskal(n - 1, i) + paskal(n - 1, i - 1);
}