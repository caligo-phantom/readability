#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // prompts user to enter text
    string text = get_string("Text: ");

    int num_of_letters = 0, num_of_words = 1, num_of_sentences = 0;

    // computes number of letters, words & sentences
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            num_of_letters++;
        }
        else if (isspace(text[i]))
        {
            num_of_words++;
        }
        else if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            num_of_sentences++;
        }
    }

    float index;

    // applying Coleman-Liau index
    index = (0.0588 * (((float)num_of_letters / (float)num_of_words) * 100.00)) - (0.2960 * (((float)num_of_sentences /
            (float)num_of_words) * 100.00)) - 15.8000;

    // prints Grade on the basis of Coleman-Liau index
    if (round(index) < 1)
    {
        printf("Before Grade 1\n"); // prints 'Before Grade 1' if grade is below 1
    }
    else if (round(index) > 16)
    {
        printf("Grade 16+\n"); // prints 'Grade 16+' if grade is more than 16
    }
    else
    {
        printf("Grade %i\n", (int)(round(index)));
    }
}