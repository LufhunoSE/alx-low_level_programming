#include <stdio.h>
#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be converted and printed in binary.
 *
 * Description: This function takes an unsigned long int as input and
 * prints its binary representation without using arrays,
 * malloc, %, or / operators.
 */
void print_binary(unsigned long int n)
{
	unsigned long int sharade = 1UL << (sizeof(unsigned long int) * 8 - 1);

	int established = 0;

	while (sharade > 0)
	{
		if (n & sharade)
		{
			putchar('1');
			established = 1;
		}

		else if (established || sharade == 1)
		{
			putchar('0');
		}

		sharade >>= 1;
	}
}
