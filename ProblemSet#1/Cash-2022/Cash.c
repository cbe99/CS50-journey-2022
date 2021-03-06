#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
		//ask how much change the customer is owed:
		int cents = get_cents();

		//Calculate the no. of quarters to be given to the customer:
		int quarters = calculate_quarters(cents);
		cents = cents - quarters * 25;

		//Calculate the no. of dimes to be given to the customer:
		int dimes = calculate_dimes(cents);
		cents = cents - dimes * 10;

		//Calculate the no. of nickels to be given to the customer:
		int nickels = calculate_nickels(cents);
		cents = cents - nickels * 5;

		//Calculate the no. of pennies to be given to the customer:
		int pennies = calculate_pennies(cents);
		cents = cents - pennies * 1;

		//To find the sum total no. of coins:
		int coins = quarters + dimes + nickels + pennies;

		//To print the total no. of coins:
		printf("Total number of coins: %i\n", coins);
		
		//To print the total no. of each of types of coins:
		printf(" Quarters : %i\n  Dimes : %i\n  Nickels : %i\n  Pennies : %i\n", quarters, dimes, nickels, pennies);
}

int get_cents(void)
{
	//Get the amount of change owed to the customer:
	int change
	do
	{
			change = get_int("Change owed for? ");
	}
	while (change < 0);
	return change; //Returns the value in cents
}

int calculate_quarters(int cents)
{
	//Divide cents by highest possible value of quarters
	int q;
	for (q=0; cents >= 25; q++)
	{
		cents = cents - 25;
	}
	return q; //q value returns the number of highest quarters
}

int calculate_dimes(int cents)
{
	//Divide cents by highest possible value of dimes
	int d;
	for (d=0; cents >= 10; d++)
	{
		cents = cents - 10;
	}
	return d; //d value returns the no. of dimes
}

int calculate_nickels(int cents)
{
	//Divide cents by highest possible value of nickels
	int n;
	for (n=0; cents >= 5; n++)
	{
		cents = cents - 5;
	}
	return n; //n value return the no. of nickels
}

int calculate_pennies(int cents)
{
	//Divide cents by highest possible number of pennies
	int p;
	for (p=0; cents >= 1; p++)
	{
		cents = cents - 1;
	}
	return p; //p value gives the highest value of no. of pennies
}
