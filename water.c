//Reporting a user's water usage, coverting minutes spent in the shower to bottles of drinking water
#include <cs50.h>
#include <stdio.h>

//prompt the user for the length of his or her shower in minutes (as a positive integer)

int main(void)
{
    int minutes = get_int("Minutes: ");
    int bottles = minutes * 12;
    printf("Bottles: %iminutes\n", bottles);
}

//then print the equivalent number of bottles of water (as an integer)