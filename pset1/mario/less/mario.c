// program that prints out a half-pyramid of a specified height
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    int spaces;
    int hashes;
    int line;
// prompt the user for the half-pyramid’s height, a positive integer no greater than 23
    do
    {
        height = get_int("Height: ");
    }

    while (height < 0 || height > 23);

    for (line = 0; line < height; line++)
    {
// spaces on first line are = to total height - 1
// then keep subtracting 1 space for each next line
        for (spaces = 1; spaces <= height - 1 - line; spaces++)
        {
            printf(" ");
        }

// hashes on first line
        for (hashes = 0; hashes < line + 2; hashes++)
        {
            printf("#");
        }

// start a new line
        printf("\n");
    }
}
