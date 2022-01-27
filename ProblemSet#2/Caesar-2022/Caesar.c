#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//function to check digits
bool only_digits(string s);

//function to rotate characters using a key
char rotate(char letter, int key);

int main(int argc, string argv[])
{
    //check if argument count is exactly 2
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //Assign the value of argv[1] to another string for ease of use
    string d = argv[1];

    //call function to check if argv[1] consists of only digits
    bool check = only_digits(d);
    if (check == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        //first convert the argv[1] a string into an integer
        int k = atoi(d);

        //get the string of text as input to be ciphered
        string plaintext = get_string("plaintext: ");

        //to printf the headerline (if under loop, would print n times)
        printf("ciphertext: ");

        //loop to change each of text
        for(int i = 0, n = strlen(plaintext); i < n; i++)
        {
            //function call to cipher the text
            char new = rotate(plaintext[i], k);
            printf("%c", new);
        }

        //to get to next line
        printf("\n");
    }
    return 0;
}

//Function call for only_digits
bool only_digits(string s)
{
    for(int i = 0, n  = strlen(s); i < n; i++)
    {
        //Loop to check if all characters of string s are digits
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
        //if all characters of the string s are digits, returns true
    return true;
}

//Function call for ciphering each of text
char rotate(char letter, int key)
{
    //Assign the text into a new variable
    char c = letter;

    //For each of the character, subtract to get the values from start
    if (isupper(letter))
    {
        letter -= 65; // A = 65 - 65 = 0
    }
    else if (islower(letter))
    {
        letter -= 97; //a = 97 - 97 = 0
    }

    //For any non-alphabetical character, return as it is
    if (!isalpha(c))
    {
        return c;
    }

    char cipher = (letter + key) % 26; //0 (a) +key(suppose 2) = 2%26 = 2 = c

    if (isalpha(c))
    {
        if (isupper(c))
        {
            cipher += 65;
            //2 + 65 = 67 'C'
        }
        else if (islower(c))
        {
            cipher += 97;
            //2 + 97 = 99 'c'
        }
    }
    //To return the cipher letters
    return cipher;
}	
