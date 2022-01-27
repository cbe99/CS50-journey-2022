#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    //To get the level of pyramid or height from the user:
    do
    {
        n = get_int("Level of pyramid: ");
    }
    while (n < 1 || n > 8);
    //For loop to make the pyramid sequence:
    for (int i = 0; i < n; i++)
    {
        int j;
        int k;
        //For loop for the space before the bricks:
        for (j = 0; j < (n - i) - 1; j++)
        {
            printf(" ");
        }
        //For loop for the bricks:
        for (k = 0; k < (n - j); k++)
        {
            printf("#");
        }
        //To come to the next line:
        printf("\n");
    }
}
