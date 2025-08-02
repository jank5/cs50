#include <stdio.h>
#include "../../lib/cs50.h"

void print_spaces(int spaces)
{
    for (int i = 0; i < spaces; spaces--)
    {
        printf(" ");
    }
}
void print_bricks(int bricks)
{
    for (int j = 0; j < bricks; j++)
    {
        printf("#");
    }
    printf("\n");
}

int main(void)
{
    int n;
    do {
        n = get_int("Height: ");
    } while (n < 1);
    for (int i = 0; i < n; i++)
    {
        print_spaces(n-1);
    }
    return 0;
}
