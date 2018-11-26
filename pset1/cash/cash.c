//Program that first asks the user how much change is owed and then spits out the minimum number of coins with which said change can be made
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;   //user input
    int cents;  //change converted to cents after being * by 100
    int quarters;
    int dimes;
    int nickels;
    int pennies;
    int count = 0;  //number of coins to return --> starts at 0 b/c it's a counter

//Get user to input change owed
    do
    {
        change = get_float("How much change are you owed? \n");
    }
    while (change < 0);

//Convert change amount to coins by multiplying by 100 since $1 = 100 cents
    cents = round(change * 100);

//Quarters first
    while (cents >= 25)
    {
        quarters = cents / 25;
        count += quarters;  //increase count of coins
        cents -= (quarters * 25);   //decrease amount by quarters
    }
//Dimes
    while (cents >= 10)
    {
        dimes = cents / 10;
        count += dimes;  //increase count of coins
        cents -= (dimes * 10);   //decrease amount by dimes
    }
//Nickels
    while (cents >= 5)
    {
        nickels = cents / 5;
        count += nickels;  //increase count of coins
        cents -= (nickels * 5);   //decrease amount by nickels
    }
//Pennies
    while (cents >= 1)
    {
        pennies = cents / 1;
        count += pennies;  //increase count of coins
        cents -= (pennies * 1);   //decrease amount by pennies
    }

//print the final number of coins
    printf("%i\n", count);
}