#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>  

int validate(string key);
string rotate(string keyword, string text);

int main(int argc, string argv[])
{
    //check if the argument count is exactly 2
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n"); //Error text to display
        return 1;
    }

    //assign the argv[1] value to another string for ease of use
    string key = argv[1];

    //function call to check the validity of key
    int check = validate(key);

    if (check == 1)
    {
        return 1; //return 1 signifies error in code
    }

    if (check == 0)
    {
        //receive the plain text as input from user
        string plaintext = get_string("plaintext: ");

        //function call to rotate the plain text as per cheatkey
        string new = rotate(key, plaintext);

        //prints the ciphertext as output
        printf("ciphertext: %s\n", new);
    }

    return 0;

}

//function to check validity of code
int validate(string key)
{
    int n = strlen(key);

    //if the length of string key is not 26
    if (n != 26)
    {
        printf("Key must contain 26 letters.\n");
        return 1;
    }

    //if the string key consists of any non-alphabetical character
    for (int i = 0; i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }

    //if the string key consists of repetitive characters
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (key[i] == key[j])
                //i=0: j=1: key[0] = key[1] ?
                //i=0: j=2: key[0] = key[2] ? and so on..
            {
                printf("Alphabets cannot repeat\n");
                return 1;
            }
        }
    }

    return 0;
}

//function call to change the cipher
string rotate(string keyword, string text)
{
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        //if the plaintext is in lower case
        if (islower(text[i]))
        {
            text[i] = tolower(keyword[text[i] - 97]);
            //suppose text[0] = 'a' then:
            //keyword is first changed to lower
            //'a' = keyword[97-97] = keyword[0]
        }
        else if (isupper(text[i]))
        {
            text[i] = toupper(keyword[text[i] - 65]);
            //suppose text[0] = 'A' then:
            //keyword is first changed to upper
            //'A' = keyword[65-65] = keyword[0]
        }
    }
    return text;
}
