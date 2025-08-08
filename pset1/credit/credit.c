#include <stdio.h>
#include <string.h>
#include "../../lib/cs50.h"

int main(void)
{
    int sum, result, sum_check;
    string x = get_string("Number: ");
    int length = strlen(x);
    for (int i = 2; i <= length; i+=2)
    {
        int output = x[length - i] - '0';
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
        int output = x[length - j] - '0';
        sum = output;
        result += sum;
    }
    int sum_numb;
    if (result % 10 == 0)
    {
        if (strncmp(x,"4",1) == 0)
        {
            printf("VISA\n");
        }
        else if (strncmp(x,"34",2) == 0 || strncmp(x,"37",2) == 0)
        {
            printf("AMEX\n");
        }
        else if (strncmp(x,"51",2) == 0 || strncmp(x,"52",2) == 0 || strncmp(x,"53",2) == 0 || strncmp(x,"54",2) == 0 || strncmp(x,"55",2) == 0)
        {
            printf("MASTERCARD\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}
