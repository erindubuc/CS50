#include <cs50.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include "struct.h"

int main(int argc, char *argv[])
{
    // ensure proper usage-> accept exactly one command-line argument: name of a forensic image from which to recover JPEGs.
    // If not executed with exactly one command-line argument, remind the user of correct usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image name (to recover)");
        return 1;
    }

    // remember raw_filename to be opened
    char *raw_file = argv[1];


    // open raw_file
    FILE *inptr = fopen(raw_file, "r");

    // Create the outfile - set to NULL b/c we don't have a value yet
    FILE *images = NULL;

    // If raw_file cannot be opened for reading, inform user with fprintf (to stderr)
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", raw_file);
        return 2;
    }

    // create an array to store chunks (each buffer of 512 bytes)
    // unsigned char *buffer = malloc(512 * sizeof(char));
    unsigned char buffer[512];

    // boolean to decide if an image has been found
    //set to false so it will change to true when a new image has been found
    bool isImage = false;

    // Create array to store names of jpeg results --> string for name
    char imageNames[10];

    // for each block of 512 bytes, create 1 jpg
    // Should be 50 jpegs in all so counter set at 0
    int jpgCounter = 0;


    // expecting 1 element of buffer size (512 bytes)
    while (fread(&buffer, sizeof(buffer), 1, inptr) == 1)
    {
        //check whether first four bytes of buffer correspond to a jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // yes, this is an image so change bool to true!
            if (isImage == true)
                // close the file that images are going into, so you can open a new one for
                fclose(images);
                //if we got here, we are currently in a new image
            // but if it's false and you found a new picture, set to true
            else
                isImage = true;


            // for each jpg, create a file to the directory
            // sprintf(jpgArray, "%00i.jpg", jpgCounter);
            sprintf(imageNames, "%03i.jpg", jpgCounter);

            // Open the file
            // every pic has it's own file, so need to open and name one at a time
            images = fopen(imageNames, "w");

            // write the jpeg file
            // writing -> fwrite(ptr to strcut reading bytes from, size, num of bytes, outptr is new image file just created);
            // fwrite(&buffer, 512, 1, images);
            jpgCounter++;

        }

        // else if found
        if (isImage == true)
        {
            fwrite(&buffer, 512, 1, images);
        }

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(images);

    // success!
    return 0;
}