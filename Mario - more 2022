#include <cs50.h>
#include <stdio.h>
int main (void)
{
 //To get the input of number of level of pyramid from user
	int n;
	do
	{
			n = get_int("Required level of pyramid? ");
	}
	while ( n < 1 || n > 8);
	//To make the pyramid using for loop
	for (int i = 0; i < n; i++)
	{
			int s;
			int l;
			int g;
			int r;
			
			//1. Loop to add space before left brick:
			for (s = 0; s < (n - i) - 1; s++)
			{
					printf(" ");
			}
			//2. Loop to add the left brick:
			for (l = 0; l < (n - s); l++)
			{
					printf("#");
			}
			//3. Loop to add two space gap between left and right brick:
			for (g = 0; g < 2; g++)
			{
					printf(" ");
			}
			//4. Loop to add the right brick:
			for (r = 0; r < (n - s); r++)
			{
					printf("#");
			}
			printf("\n");
	}

}
