#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int top;
    unsigned capacity;
    char *array;
} Stack;

Stack *createStack(unsigned capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char *)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, char item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

char pop(Stack *stack)
{
    if (isEmpty(stack))
        return 0;
    return stack->array[stack->top--];
}

int palindrom(char str[])
{
    int len, i, mid;
    len = strlen(str);
    mid = len / 2;
    Stack *stack = createStack(len);
    printf("\n%d, %d\n", len, mid);

    for (i = 0; i < mid; i++)
    {
        push(stack, str[i]);
    }
    if (len % 2 != 0)
    {
        i++;
    }
    printf("i = %d", i);
    while (str[i] != '\0')
    {
        char ele = pop(stack);

        if (ele != str[i])
            return 0;
        i++;
    }
    return 1;
}

int main()
{
    char str[100];
    puts("=== Cek String apakah palindrom atau bukan ===");
    printf("Masukkan Inputan : ");
    gets(str);
    if (palindrom(str) == 1)
    {
        printf("\nKalimat tersebut adalah palindrom");
    }else
        printf("\nKalimat tersebut bukan palindrom");

    printf("\n\nPress enter to exit...");
    getchar();
}