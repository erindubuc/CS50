//Program that will print a person's intials when given his/her name as input
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    //Prompt user for their full name
    string names = get_string("What is your full name? \n");

    //Output user's FIRST initial with first char of string as an uppercase
    int toupper();
    printf("%c", toupper(names[0]));

    //Full name will have spaces between words -- look for and loop through those spaces
    for (int i = 0; i < strlen(names); i++)
    {
        //When you come to a space, you'll find the next word name
        if (names[i] == ' ')
        {
            //Print next char (first char of next word name) as an uppercase
            printf("%c", toupper((names[i + 1])));
        }
    }

    //Enter for a new line
    printf("\n");
}