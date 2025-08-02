#include "../../lib/cs50.h"
#include <stdio.h>

void print_row(int bricks)
{
    for (int i = 0; i < bricks; i++)
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
    } while (1 > n || n >= 9);
    for (int i = 0; i < n; i++)
    {
        print_row(i + 1);
    }
    return 0;
}
