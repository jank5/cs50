#include <stdio.h>
#include "../../lib/cs50.h"

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    int result;
    int cents;
    do {
        cents = get_int("Change owed: ");
    } while (cents < 0);
    int quarters = calculate_quarters(cents);
    cents = cents - (quarters * 25);
    int dimes = calculate_dimes(cents);
    cents = cents - (dimes * 10);
    int nickels = calculate_nickels(cents);
    cents = cents - (nickels * 5);
    int pennies = calculate_pennies(cents);
    cents = cents - (pennies * 1);

    if (cents == 0) {
        result = quarters + dimes + nickels + pennies;
    }
    printf("%d\n", result);

    return 0;
}

int calculate_quarters(int cents) // 25
{
    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents -= 25;
    }
    return quarters;
}

int calculate_dimes(int cents) // 10
{
    int dimes = 0;
    while (cents >= 10)
    {
        dimes++;
        cents -= 10;
    }
    return dimes;
}

int calculate_nickels(int cents) // 5
{
    int nickles = 0;
    while (cents >= 5)
    { 
        nickles++;
        cents -= 5;
    }
    return nickles;
}

int calculate_pennies(int cents) // 1
{
    int pennies = 0;
    while (cents >= 1)
    {
        pennies++;
        cents -= 1;
    }
    return pennies;
}
