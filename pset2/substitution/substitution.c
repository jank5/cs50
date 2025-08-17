#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../cs50.h"

int check_key(string key);

int main(int argc, string argv[])
{
    string arg = argv[1];
    if (argc > 2 || argc == 1)
    {
        printf("Usage: %s KEY", argv[0]);
        return 1;
    }
    int length = strlen(arg);
    int result = check_key(arg);
    printf("%d",result);
}
/* Там надо несмотря на регистр ключа заменить с соответствующим регистром, для этого надо использовать модуль от ctype.h под названием tolower() toupper()*/

int check_key(string key)
{
    int result = 0, len = strlen(key);
    if (len == 26)
    {
        for (int i = 0; i < len; i++)
        {
            if(isalpha(key[i]))
            {
                for (int j = 0; j < len; j++)
                {
                    if (key[i + 1] == key[j])
                    {
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
