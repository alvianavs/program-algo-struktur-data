#include <stdio.h>
#include <string.h>

#define max 100
typedef struct
{
    int top;
    int item[max];
} stack;

void Initialization(stack *stk)
{
    stk->top = 0;
}
int Empty(stack *stk)
{
    return (stk->top == 0);
}
int Full(stack *stk)
{
    return (stk->top == max);
}
void Push(stack *stk, char x)
{
    if (stk->top == max - 1)
    {
        printf("stack penuh");
    }
    else
    {
        stk->item[++(stk->top)] = x;
    }
}

void Pop(stack *stk)
{
    printf("%c", stk->item[(stk->top)--]);
}

int main()
{
    stack tumpuk;
    Initialization(&tumpuk);
    char str[] = "sri lanka";
    int len = strlen(str);
    int i;

    for (i = 0; i < len; i++)
        Push(&tumpuk, str[i]);

    for (i = 0; i < len; i++)
        Pop(&tumpuk);

    fflush(stdin);
    printf("\nPress enter to exit...");
    getchar();
}