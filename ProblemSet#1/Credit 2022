#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long CCNumber;

    //To get the input from the user for Credit Card Number:

    do
    {
        CCNumber = get_long("Input the Credit Card Number: ");
    }
    while (CCNumber <= 0);

    //1st case where we take the sum from last digit:

    long CNumber = CCNumber;
    int sum = 0;
    
    while (CNumber > 0)
    {
        int LastDigit = CNumber % 10;
        sum = sum + LastDigit;

        //To go to the next number after one place:

        CNumber = CNumber / 100;
    }

    //2nd case where we take the numbers from last second digit:

    long CNum;
    CNum = CCNumber / 10;

    while (CNum > 0)
    {
        int lastDigit = CNum % 10;

        //Multiplication by 2 to each number:

        int TwiceTimes = lastDigit * 2;
        sum = sum + (TwiceTimes % 10) + (TwiceTimes / 10);
        CNum = CNum / 100;
    }

    //To find the Length of Number:

    long CNo = CCNumber;
    int count = 0;

    while (CNo > 0)
    {
        CNo = CNo / 10;
        count++;
    }

    //To divide the number:

    long divisor = 10;

    for (int i = 0; i < count - 2; i++)
    {
        divisor = divisor * 10;
    }

    //Final Check for Card Type:

    int FirstDigit = CCNumber / divisor;
    int FirstTwoDigits = CCNumber / (divisor / 10);

    if ((sum % 10) == 0)
    {
        if (FirstDigit == 4 && (count == 13 || count == 16))
        {
            printf("VISA\n");
        }
        else if ((FirstTwoDigits == 34 || FirstTwoDigits == 37) && (count == 15))
        {
            printf("AMEX\n");
        }
        else if ((FirstTwoDigits > 50 && FirstTwoDigits < 56) && (count == 16))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
