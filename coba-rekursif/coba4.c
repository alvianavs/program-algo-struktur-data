#include <stdio.h>
#include <math.h>

int prima(int number, int index)
{
    if (index == 1)
        return 1;
    else if (number % index == 0)
        return 0;
    else
        return prima(number, --index);
}

int main()
{
    int num;
    printf("Masukkan bilangan sampai dengan : ");
    scanf("%d", &num);
    printf("Deret bilangan prima : ");
    for (int i = 1; i < num; i++)
    {
        if (prima(i, (int)sqrt(i)))
            printf("%d ", i);
    }

    fflush(stdin);
    printf("\n\nPress enter to exit..");
    getchar();
    
}