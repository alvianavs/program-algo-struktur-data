#include <stdio.h>
#include <conio.h>
int main()
{
    int i,j,c;
    printf("deret bilangan prima 1-100 adalah \n");
    for( i=1;i<=100;i++){
        for( j=1;j<=i;j++){
            if(i % j == 0){
                c++;
            }
        }
    if(c == 2) printf("%d ",i);
    c=0;
    }
    getch();
}
