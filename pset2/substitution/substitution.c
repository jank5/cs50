#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../cs50.h"

int check_key(string key);
void convert(string input, string key);

char ALPHABET[26] = "abcdefghijklmnopqrstuvwxyz";

int main(int argc, string argv[])
{
    string key = argv[1];
    if (argc > 2 || argc == 1)
    {
        printf("Usage: %s KEY", argv[0]);
        return 1;
    }
    int length = strlen(key);
    int result = check_key(key);
    if (result == 1)
    {
        return result;
    }
    string input = get_string("plaintext:  ");
    convert(input, key);
    return 0;
}

int check_key(string key)
{
    int result = 0, len = strlen(key);
    if (len == 26)
    {
        for (int i = 0; i < len; i++)
        {
            if(isalpha(key[i]))
            {
                for (int j = i + 1; j < len; j++)
                {
                    if (key[i] == key[j])
                    {
                        printf("Key must not contain repeated characters.\n");
                        result = 1;
                    }
                }
            }
            else
            {
                printf("Key must only contain alphabetic characters.\n");
                result = 1;
            }
        }
    }
    else
    {
        printf("Key must contain 26 characters.\n");
        result = 1;
    }
    return result;
}

void convert(string input, string key)
{
    int len = strlen(input);
    int array_char[len];
    char result[len];
    for (int i = 0; i < len; i++)
    {
        for (int j = 0, alph_len = strlen(ALPHABET); j < alph_len; j++)
        {
            char check_char = input[i];
            if(islower(check_char))
            {
                if (input[i] == ALPHABET[j])
                {
                    array_char[i] = j;
                    break;
                }
            }
            else if(isupper(check_char))
            {
                if (input[i] == toupper(ALPHABET[j]))
                {
                    array_char[i] = j;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < len; i++)
    {
        if(isupper(input[i]))
        {
            int get_int = array_char[i];
            result[i] = toupper(key[get_int]);
        }
        if(islower(input[i]))
        {
            int get_int = array_char[i];
            result[i] = tolower(key[get_int]);
        }
    }
    result[len] = '\0';
    printf("ciphertext: %s\n", result);
}
