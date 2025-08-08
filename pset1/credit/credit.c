#include <stdio.h>
#include <string.h>
#include "../../lib/cs50.h"

int multiply_and_addition(int length, string number_card);
void what_is_card(int result, string number_card);

int main(void)
{
    int result, length;
    string number_card = get_string("Number: ");
    length = strlen(number_card);
    result = multiply_and_addition(length, number_card);
    what_is_card(result, number_card);

    return 0;
}

int multiply_and_addition(int length, string number_card)
{
    int sum = 0;
    int result = 0;
    for (int i = 2; i <= length; i+=2)
    {
        int output = number_card[length - i] - '0';
        sum = output * 2;
        if (sum >= 10){
            int a,b;
            a = sum % 10; // get last digit (1[2])
            b = sum / 10; // get first digit ([1]2)
            result += a;
            result += b;
        } else {
            result += sum;
        }
    }
    for (int j = 1; j <= length; j+=2)
    {
        int output = number_card[length - j] - '0';
        sum = output;
        result += sum;
    }
    return result;
}

void what_is_card(int result, string number_card)
{
    int length = strlen(number_card);
    if (result % 10 == 0)
    {
        if (length == 13 || length == 16 && strncmp(number_card,"4",1) == 0)
        {
            printf("VISA\n");
        }
        else if (length == 15 && strncmp(number_card,"34",2) == 0 || strncmp(number_card,"37",2) == 0)
        {
            printf("AMEX\n");
        }
        else if (length == 16 && strncmp(number_card,"51",2) == 0 || strncmp(number_card,"52",2) == 0 || strncmp(number_card,"53",2) == 0 || strncmp(number_card,"54",2) == 0 || strncmp(number_card,"55",2) == 0)
        {
            printf("MASTERCARD\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
