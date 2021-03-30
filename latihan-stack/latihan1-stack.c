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

void validate(char str[])
{
    int len, i;
    len = strlen(str);
    Stack *stack = createStack(len);

    for (i = 0; i < len; i++)
    {
        if(str[i] == '*')
        {
            str[i] = pop(stack);
        }
        else{
            push(stack, str[i]);
        }

    }
}

int main()
{
    char str[100];
    printf("========= Latihan No 1 =========");
    printf("\nMasukkan Inputan : ");
    gets(str);
    validate(str);
    printf("Hasilnya : %s", str);

    printf("\n\nPress enter to exit...");
    getchar();
}