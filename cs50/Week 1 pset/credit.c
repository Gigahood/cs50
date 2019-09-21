#include <cs50.h>
#include <stdio.h>
#include <math.h>

int calculation(unsigned long int);
int length(unsigned long int);
int firstTwoDigits(int, unsigned long int);
void print(int, int);

int main(void)
{
// declare variable
    unsigned long int input;
    int result, firstTwoDigit, lengthOfInput;
    
//get user input
    input =  get_long("Enter Your Credit Card Number : ");
    
// validate input less than 13 digit or more than 16 digit print invalid
// if input is 14 digit print invalid den exit program
    if (input < 0 || input < 999999999999 || input > 10000000000000000)
    {
        printf("INVALID\n");
        return 0;
    }
    if (input > 9999999999999 && input < 100000000000000)
    {
        printf("INvalid 14 numbers");
        return 0;
    }
    
//get the result of luhn algorithm
    result = calculation(input);
    
    // calculate the number of digit
    lengthOfInput = length(input);
    
    //get the first two digit
    firstTwoDigit = firstTwoDigits(lengthOfInput, input);
    print(result, firstTwoDigit);
}

int calculation(unsigned long int input)
{
    unsigned long int divisor;
    int result, secondToLast = 0, last = 0, counter  = 0;
    
    do
    {
// counter is for indicate the position of current last digit
// if is odd number mean it is last digit
// if is even it is last to second number
// below is the luhn algorithms
// result will direct add the last digit
// last to second digit will multiply by 2 and check if it is double digit, den add it to the result
        // 
        counter += 1;
        if (counter % 2 == 1)
        {
            result += (input % 10);
        }
        else
        {
            secondToLast = (input % 10) * 2;
            if (secondToLast / 10 != 0)
            {
                result = result + (secondToLast / 10) + (secondToLast % 10);
            }
            else
            {
                result += secondToLast;
            }
        }
        input /= 10;
    }
    while (input > 0);
    
    return result;
}

// calculate number of digits
int length(unsigned long int input)
{
    int counter = 0;
    
    do
    {
        counter += 1;
        input = input / 10;
    }
    while (input > 0);
    
    return counter;
}

int firstTwoDigits(int counter, unsigned long int input)
{
    
//using the number of digit as reference divide accordingly to get the first two digits
    int digit;
    switch (counter)
    {
        case 15 :
            digit = input / (10000000000000);
            break;
            
        case 13 :
            digit = input / (100000000000);
            break;
            
        case 16 :
            digit = input / (100000000000000);
            break;
    }
    return digit;
}

// use switch case to select the credit card type
void print(int result, int firstTwoDigit)
{
    if (result % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        if (firstTwoDigit / 10 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            switch (firstTwoDigit)
            {
                case 34:
                case 37:
                    printf("AMEX\n");
                    break;
                    
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                    printf("MASTERCARD\n");
                    break;
                    
                default:
                    printf("INVALID\n");
            }
        }
    }
}
