#include <stdio.h>
#include <string.h>

int main()
{
    char finalText[6];
    char text[] = {'p', 'e', 'n', 's', 'i', 't', '\0'};
    int posisi;
    int size = strlen(text);

    printf("%d", size);
    posisi = size - 1;
    for (int i = 0; i < size; i++)
    {
        finalText[i] = text[posisi];
        posisi--;
    }
    finalText[size] = '\0';
    printf("\n%s\n", finalText);
    return 0;
}