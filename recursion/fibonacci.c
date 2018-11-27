#include <stdio.h>

int fib(int);

int main()
{
    printf("\t%i\n", fib(10));
	return 0;
}

int fib (int pos)
{
    if (pos <= 1)  // base case return 1 && 0
    {
        return pos;
    }

    return fib(pos - 1) + fib(pos - 2);

}