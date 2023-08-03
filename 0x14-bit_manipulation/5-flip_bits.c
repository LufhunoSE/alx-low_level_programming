#include <stdio.h>
#include "main.h"

/**
 * flip_bits - Calculate the number of bits needed to flip.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits needed to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int upshot = n ^ m;
	unsigned int tally = 0;

	while (upshot != 0)
	{
		tally += upshot & 1;
		upshot >>= 1;
	}

	return (tally);
}
