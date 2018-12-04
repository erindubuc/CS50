#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// this is a data type that contains this structure
typedef struct {
    int red;
    int green;
    int blue;
} Pixel;

/*   } __attribute__((__packed__)) is better performance b/c
it packs it all next to each other  */

int main(void)
{
    char* name = "Cliff";

    for (int i = strlen(name) -1; i >= 0; i--)
    {
        char temp = name[i];
        printf("%c", temp);
    }

    printf("\n");
}




// main func that we played with first
//add pointer to get actual address
// void copy(int* a, int* b)
// {
//     //star on pointer says go to that address and get the VALUE
//     //put the value of a in the address of b
//     *b = *a;
// }

// void changeArray(int a[])
// {
//     a[0] = 5;
// }
//int main(void)
// {
//     printf("Hello, World\n");
//     int x = 3, y = 7;
//     int arr[5] = {1, 2, 3, 4, 5};
//     printf("y is: %i\n", y);
//     // copy(x, y);  //this is sending the VALUE
//     copy(&x, &y); //this sends the ADDRESS
//     printf("y is now: %i\n", y);
//     printf("arr[0] is: %i\n", arr[0]);
//     changeArray(arr);
//     printf("arr[0] is %i\n", arr[0]);
// }

/* function for pixel
int main(void)
{
    // this is an instance of a pixel
    Pixel pix;
    pix.red = 255;
    printf("%i\n", pix.red);
}
*/