#include <stdio.h>

int main()
{
    int count = 10, *temp, sum = 7;
    temp = &count;
    *temp = 32;
    temp = &sum;
    *temp = count;
    printf("\n%d\n", sum);
    sum = *temp * 4;
    printf("\ncount=%d, *temp=%d, sum=%d\n", count, *temp, sum);
}