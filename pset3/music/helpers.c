// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // If num and den are in array, can be ref by index
    // Convert single digit to ASCII value --> '0' is 48
    // Take str value and turn it into int w/ ascii reference
    int numerator = (int)fraction[0] - 48;
    int denominator = (int)fraction[2] - 48;
    int duration = (numerator * 8) / denominator;
    return duration;
}

// Calculates frequency (in Hz) of a note
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

    // If strlen == 2 ex. A#4
    if (strlen(note) == 2)
    {
        letter = note[0];
        octave = atoi(&note[1]);
    }

    // If strlen(note) == 3, contains accidental
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
        // 2^#/12 power where # is how many semitones you are away from A
        case 'C':
            freq = 440.0 / pow(2.00, (9.0 / 12.0));
            break;
        case 'D':
            freq = 440.0 / pow(2.0, (7.0 / 12.0));
            break;
        case 'E':
            freq = 440.0 / pow(2.0, (5.0 / 12.0));
            break;
        case 'F':
            freq = 440.0 / pow(2.0, (4.0 / 12.0));
            break;
        case 'G':
            freq = 440.0 / pow(2.0, (2.0 / 12.0));
            break;
        case 'A':
            freq = 440.0;
            break;
        case 'B':
            freq = 440.0 * pow(2.0, (2.0 / 12.0));
            break;
    }

    // Support different octaves of A notes
    if (octave > 4)
    {
        for (int i = 0; i < octave - 4; i++)
        {
            freq *= 2.0;
        }
    }
    else if (octave < 4)
    {
        for (int i = 0; i < 4 - octave; i++)
        {
            freq /= 2.0;
        }

    }

    // Support whether a note is sharp # or flat b
    if (note[1] == 'b')
    {
        freq /= (pow(2.0, (1.0 / 12.0)));
    }

    else if (note[1] == '#')
    {
        freq *= (pow(2.0, (1.0 / 12.0)));
    }

    // Return frequency in Hz (rounded)
    return round(freq);
}


// Determines whether a string represents a rest
bool is_rest(string s)
{
    // If string is empty, then the line is empty
    if (s[0] == 0)
    {
        return true;
    }

    else
    {
        return false;
    }

}
