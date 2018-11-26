#include<cs50.h>
#include<stdio.h>

void add_number()
{
    printf("My total: %i", 10 + 100);
}
void add_numbers(int, int);

int main(void)
{
    int x = get_int("enter x: ");
    int y = get_int("enter y: ");
    add_numbers(x, y);
    printf("x is: %i\ty is: %i\n", x, y);
    add_number();
    // if (x == 4)
    // {
    //     int z = get_int("enter z: ");
    //     add_numbers(x, z);
    // }
}

void add_numbers(int x, int y)
{
    x = 8;
    printf("total is: %i\n", x + y);
}

