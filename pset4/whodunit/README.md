# Questions

## What's `stdint.h`?

'stdint.h' is a header declaring sets of integer types having specified
widths.  This header defines corresponding sets of macros that specify
limits of integer types corresponding to types defined in other standard headers.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

The point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a
program is to define the required width, or number of bits that will need to be used
to store an integer type's value within the program.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE = 8 bits = 1 byte
DWORD = 32 bits = 4 bytes
LONG = 32 bits = 4 bytes
WORD = 16 bit = 2 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first two bytes of any BMP file must be 0x42 0x4D in hexadecimal, or 'BM' in ASCII.

## What's the difference between `bfSize` and `biSize`?

'bfSize' is the size, in bytes, of the bitmap file, while 'biSize' is the
number of bytes required by the structure of the DIB (device independent bitmap).


## What does it mean if `biHeight` is negative?

If 'bitHeight' is negative, the bitmap is a top-down DIB and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

In 'BITMAPINFOHEADER', the field that specifies the BMP's color depth is
'biBitCount'. It determines the number of bits that define each pixel
and the maximum number of colors in the bitmap.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

In lines 24 and 32 of 'copy.c', 'fopen' may return 'NULL' if the file it is
trying to open can't be found.

## Why is the third argument to `fread` always `1` in our code?

'fread' returns the number of items successfully read.  Therefore, the third argument
to 'fread' is always '1' in our code because we are asking the computer to read 1 structure,
or header, from 1 file for each 'fopen'.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

If 'bi.biWidth' is '3', line 65 of 'copy.c' will assign 'padding' the value of '3'.

## What does `fseek` do?

'fseek' changes the file position indicator for the specified stream.  Essentially, it allows you to rewind
or fast-forward within a file to move the file pointer associated with the stream to a new location that is
offset bytes from origin.
int fseek(FILE *stream, long int offset, int whence)

## What is `SEEK_CUR`?

'SEEK_CUR' is one of three constant whence parameters for 'fseek' that basically says, begin the offset "from
the current position of the file pointer".

## Whodunit?

It was Professor Plum with the candlestick in the library.
