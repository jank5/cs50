#include <stdio.h>
#include <math.h>
#include <string.h>
#include "../cs50.h"

float letters(string read);
float words(string read);
float sentence(string read);
string check_grade(int avg_num);

int main(void)
{
    string read = get_string("Text: ");
    float result_letters = letters(read);
    float result_words = words(read);
    float result_sentence = sentence(read);

    float l = result_letters * 100 / result_words;
    float s = result_sentence * 100 / result_words;

    float index = 0.0588 *  l - 0.296 *  s - 15.8;
    printf("%f\n", index);
    return 0;
}

float letters(string read)
{
    float score = 0;
    int len = strlen(read);
    for (int i = 0; i < len; i++)
    {
        if (isalpha(read[i]))
        {
            score += 1;
        }
    }
    return score;
}
float words(string read)
{
    float score = 0;
    int len = strlen(read);
    for (int i = 0; i < len; i++)
    {
        if (read[i] == ' ')
        {
            score += 1;
        }
    }
    score += 1;
    return score;
}

float sentence(string read)
{
    float score = 0;
    int len = strlen(read);
    for (int i = 0; i < len; i++)
    {
        if (read[i] == '!' || read[i] == '?' || read[i] == '.')
        {
            score += 1;
        }
    }
    return score;
}

string check_grade(int avg_num)
{
    float result = round(avg_num);
    if (avg_num < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (avg_num >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %f\n", result);
    }
}
