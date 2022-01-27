#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int main(void)
{
    //To get the text from user:
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    //To print the no. of letters, words & sentences
    printf("%d letters\n", letters);
    printf("%d words\n", words);
    printf("%d sentences\n", sentences);

    //Calculation for Coleman-Liau index:
    float L = ((float)letters/(float)words) * 100;
    float S = ((float)sentences/(float)words) * 100;
    float index;
    index = 0.0588 * L - 0.296 * S - 15.8;
    printf("index: %f\n", index);

    //To round off the index to the nearest grade:
    int grade = round(index*1);

		//To print the grade:
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
}

//function to count letters:
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isupper(text[i]) || islower(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

//function to count words:
int count_words(string text)
{
    int words = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words + 1;
}

//function to count sentences:
int count_sentences(string text)
{
    int sentence = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence++;
        }
    }
    return sentence;
}
