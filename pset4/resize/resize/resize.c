#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{

    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize (num<=100) infile outfile\n");
        return 1;
    }

    // declare n for number to resize image by
    int *n = malloc(sizeof(int));
    *n = atoi(argv[1]);

    // make sure that num entered at command-line is between 0-100
    if (*n < 0 || *n > 100)
    {
        fprintf(stderr, "Be sure your number is a positive integer that is less than or equal to 100.");
        return 5;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // variables for new outfile headers
    BITMAPINFOHEADER biOut;
    biOut = bi;
    BITMAPFILEHEADER bfOut;
    bfOut = bf;

    // outfile variables for width and height
    biOut.biWidth = bi.biWidth * *n;
    biOut.biHeight = bi.biHeight * *n;
    printf("resized width: %i\nresized height: %i\n", biOut.biWidth, biOut.biHeight);

    // determine padding for scanlines from infile
    int oldPadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    printf("input padding: %i\n", oldPadding);

    // determine padding for scanlines
    int newPadding = (4 - (biOut.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    printf("new padding: %i\n", newPadding);

    // outptr biSizeImage needs to be modified
    biOut.biSizeImage = (biOut.biWidth * sizeof(RGBTRIPLE) + newPadding) * abs(biOut.biHeight);
    printf("Resized Size of Image: %i\n", biOut.biSizeImage);

    // infile bfSize
    // bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // outptr bfSize needs to be modified
    // bfOut.bfSize = biOut.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    // try hard coding the specific number of bytes that the headers take up
    bfOut.bfSize = biOut.biSizeImage + 54;

    // write outfile's BITMAPFILEHEADER and BITMAPINFO => creates new struct for headers
    fwrite(&bfOut, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&biOut, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines // counter is set at 0 and will iterate to OLD max height
    for (int scanline = 0, old_biHeight = abs(bi.biHeight); scanline < old_biHeight; scanline++)
    {
        // for each row => width
        // to interate through rows, need to go through each vertical row of the image
        for (int row = 0; row < *n; row++)
        {
            // now go through width of each row to access triples
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RBG pixels in the row
                for (int pixel = 0; pixel < *n; pixel++)
                {
                    // write RGB triple to outfile n times
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // input file padding, pass over it
            fseek(inptr, oldPadding, SEEK_CUR);

            // now, can write outfile's padding to the NEW image
            for (int k = 0; k < newPadding; k++)
            {
                fputc(0x00, outptr);
            }

            //recopy method
            //for each row
            if(row < *n - 1)
            {
                // send infile cursor back if row is less than the num - 1
                // get the number of bytes for cursor to go back
                long offset = bi.biWidth * sizeof(RGBTRIPLE) + oldPadding;
                fseek(inptr, -offset, SEEK_CUR);
            }
        }
    }

    // free *n
    free(n);

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}