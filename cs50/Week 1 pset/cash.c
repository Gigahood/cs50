#include <cs50.h>
#include <stdio.h>
#include <math.h>

int input(void);
int calculation(int);
void printResult(int);

int main(void)
{
    int cents, total;
    // get user input, validate the input
    cents = input();
    //calculate total amount of coins that will be dispplay
    total = calculation(cents);
    //print out the result
    printResult(total);
}

int input(void)
{
    int cents;
    double userInput;
    
    //keep get input until valid input is key in
    do
    {
        userInput = get_float("Enter amount : RM");
    }
    while (userInput < 0);
    
    cents = round(userInput * 100);
    
    return cents;
}

void printResult(int total)
{
    printf("%i\n", total);
}

int calculation(int cents)
{
    //declare and initialize variables
    int total, c25, c10, c5, c1;
    c25 = 0;
    c10 = 0;
    c5 = 0;
    c1 = 0;
    
    // if cents > 25, divide it by 25, take its remainder to furthur divide by 10 
    // quotient will be the amount of 25 cents 
    if (cents >= 25)
    {
        c25 = cents / 25;
        cents %= 25;
    }
    if (cents >= 10)
    {
        c10 = cents / 10;
        cents %= 10;
    }
    if (cents >= 5)
    {
        c5 = cents / 5;
        cents %= 5;
    }
    c1 = cents;
    
    total = c25 + c10 + c5 + c1;
    return total;
}
