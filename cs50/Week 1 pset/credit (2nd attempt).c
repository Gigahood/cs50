#include <cs50.h>
#include <stdio.h>

void printResult(long input);
bool luhnAlgo(long input);

int main(void)
{
    long input = get_long("Please enter credit card number : ");
    // this is implementing the algo, if algo returning as valid number 
    // proceed to check type of card
    if (luhnAlgo(input))
    {
       printResult(input);
    }
    else
    {
        printf("INVALID\n");
    }
    
}

bool luhnAlgo(long input)
{
    int index = 1;
    int step1Total = 0;
    int checkStep1;
    int resultTotal = 0;
    
    // this will continue to get the last number of the input
    // will left out the first digit 
    // so will use the index to check whether the first digit will be doing
    // step 1 or step 2 of luhn algorithm
    while (input / 10 > 0)
    {
        // check which location from the end
        // if is odd, do step 2
        // if is even do step 1
        if (index % 2 != 0)
        {
            resultTotal += (input % 10);
        }
        else
        {
            checkStep1 = (input % 10) * 2;
            if (checkStep1 / 10 > 0)
            {
                step1Total += ((checkStep1 / 10) + (checkStep1 % 10 ));
            }
            else
            {
                step1Total += checkStep1;
            }
        }
        
        index++;
        input /= 10;
        
    }
    
    if (index % 2 != 0)
        {
            resultTotal += (input % 10);
        }
        else
        {
            checkStep1 = (input % 10) * 2;
            if (checkStep1 / 10 > 0)
            {
                step1Total += ((checkStep1 / 10) + (checkStep1 % 10 ));
            }
            else
            {
                step1Total += checkStep1;
            }
        }
    resultTotal += step1Total;
    
    if (resultTotal % 10 == 0)
    {
        return true;
    }
    
    return false;
}



void printResult(long input)
{
    if ((input >= 100000000000000 && input <= 999999999999999) && (input /10000000000000 == 34 || input /10000000000000 == 37))
    {
        printf("AMEX\n");
    }
    else if (input >= 1000000000000000 && input <= 9999999999999999) 
    {
        int firstTwoNumber = input / 100000000000000 ;
        switch (firstTwoNumber) 
        {
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
                printf("MASTERCARD\n");
                break;
            case 56:
            case 57:
            case 58:
            case 59:
                printf("INVALID\n");
                break;
            default :
                if ((input >= 1000000000000 && input <= 9999999999999 && input / 100000000000 == 4) || input / 100000000000000)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
