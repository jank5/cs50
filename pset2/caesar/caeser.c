#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../cs50.h"

int only_digits(string s);
int reverse(string s);
char rotate(char c, int n);


char UPPER_ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char LOWER_ALPHABET[] = "abcdefghijklmnopqrstuvwxyz";
int main(int argc, string argv[])
{
    string output;
    char new_output;
    char low[2];
    string arg = argv[1];
    int number;
    if (argc > 2 || argc == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int check = only_digits(arg);
    if (check != 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        number = reverse(arg);
        output = get_string("plaintext: ");
    }
    int length = strlen(output);
    char result_string[length-1];
    for(int i = 0; i < length; i++)
    {
        new_output = rotate(output[i], number);
        result_string[i] = new_output;
    }
    result_string[length] = '\0';
    printf("ciphertext: %s",result_string);


    return 0;
}

int only_digits(string s)
{
    int result;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if(isdigit(s[i]))
        {
            result = 0;
        }
        else
        {
            result = 1;
        }
    }
    return result;
}

int reverse(string s)
{
	int result = atoi(s);
    return result;
}

char rotate(char c, int n)
{
    char result;
    int formulaH = (((int) c + n) - 'A') % 26;
    int formulaL = (((int) c + n) - 'a') % 26;

    if(isalpha(c) && isupper(c))
    {
        result = UPPER_ALPHABET[formulaH];
    }
    else if(isalpha(c) && islower(c))
    {
        result = LOWER_ALPHABET[formulaL];
    }
    return result;
}
