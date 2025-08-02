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
    printf("\n");
}

int main(void)
{
    int x;
    do {
        x = get_int("Height: ");
    } while (1 > x || x >= 9);
    int space = x;
    for (int i = 0; i < x; i++)
    {
        dots_brack(space, i + 1);
        space--;
    }
    return 0;
}


