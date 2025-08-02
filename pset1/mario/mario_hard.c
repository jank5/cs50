#include <stdio.h>
#include "../../lib/cs50.h"

void dots_brack(int dot, int brack)
{
    for (int i = 1; i < dot;i++)
    {
        printf(" ");
    }
    for (int j = 0; j < brack; j++)
    {
        printf("#");
    }
    printf("  ");
    for (int k = 0; k < brack; k++)
    {
        printf("#");
    }
    printf("\n");
}

int main(void)
{
    int numbers;
    do {
        numbers = get_int("Height: ");
    } while (1 > numbers || numbers >= 9);
    int space = numbers;
    for (int i = 0; i < numbers; i++)
    {
        dots_brack(space, i + 1);
        space--;
    }
    return 0;
}

