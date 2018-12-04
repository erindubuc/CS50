#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define HZ_A4 440.0

int frequency(string note);

int main()
{
    string input = "G#6";
    int result = frequency(input);
    printf("%i\n", result);
}

int frequency(string note)
{
    // Letter variable
    char letter;
    // Accidental variable (in needed)
    char accidental;
    // Octave variable
    int octave;

    // Frequency variable in Hz
    double freq = 0.0;

    // If strlen = 2 ex. A#4
    if (strlen(note) == 2)
    {
        letter = note[0];
        octave = atoi(&note[1]);
    }

    // If strlen(note) = 3, contains accidental
    if (strlen(note) == 3)
    {
        letter = note[0];
        accidental = note[1];
        octave = atoi(&note[2]);
    }

    // Letter changes in OCTAVE 4
    switch (letter)
    {
        // C - G in the 4th octave are LOWER than A4 so divide
        case 'C':
            freq = 440.0 / pow(2.00, (9.0/12.0));
            break;
        case 'D':
            freq = 440.0 / pow(2.0, (7.0/12.0));
            break;
        case 'E':
            freq = 440.0 / pow(2.0, (5.0/12.0));
            break;
        case 'F':
            freq = 440.0 / pow(2.0, (4.0/12.0));
            break;
        case 'G':
            freq = 440.0 / pow(2.0, (2.0/12.0));
            break;
        case 'A':
            freq = 440.0;
            break;
        case 'B':
            freq = 440.0 * pow(2.0, (2.0/12.0));
            break;
    }

    // Support different octaves of A notes
    if (octave > 4)
    {
        for (int i = 0; i < octave - 4; i++)
            freq *= 2.0;

    }
    else if (octave < 4)
    {
        for (int i = 0; i< 4 - octave; i++)
            freq /= 2.0;
    }

    // Support whether a note is sharp # or flat b
    if (note[1] == 'b')
        freq /= (pow(2.0, (1.0/12.0)));

    else if (note[1] == '#')
        freq *= (pow(2.0, (1.0/12.0)));
    //     // If the note is an accidental - sharp or flat
    //     if (accidental == '#')
    //         freq = 440.0 * pow(2.0, (1.0/12.0));

    //     else if (accidental == 'b')
    //         freq = 440.0 / pow(2.0, (1.0/12.0));
    // }

    // Return frequency in Hz (rounded)
    return round(freq);
}


