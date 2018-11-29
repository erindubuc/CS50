#include <stdio.h>

//function should return the result not print.


int expo(int, int);

int exponr(int, int);


int main()
{
    printf("Recursive Answer: %i\n", expo(9, 9));
    printf("Non-recursive Answer: %i\n", exponr(9, 9));
	return 0;
}

// Recursive function
int expo (int base, int expon)
{
    // Base case num = 0
    if (base == 0)
        return 0;

    // Base case if base = 1, result will always be 1
    // Base case if expon = 0, result will always be 1
    if (base == 1 || expon == 0)
        return 1;


    // Base case => num to the power 0 = 1
    // if (power == 0)
    // {
    //     return 1;
    // }

    // Return result--> recursion invoking itself
    return (base * expo(base, expon - 1));
}


//  Non-recursive
int exponr(int base, int expon)
{
    // variable to store result
    int result = 1;

    // If base is <= 1, result will always be the base
    if (base <= 1)
        return base;

    for (int i = 0; i < expon; i++)
        // power = power * base;
        result *= base;

    return result;
}