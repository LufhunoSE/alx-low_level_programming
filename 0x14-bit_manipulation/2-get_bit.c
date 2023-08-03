#include "main.h"

/**
 * get_bit - Get the value of a bit at a given index.
 * @n: The number whose bit value we want to check.
 * @index: The index of the bit to get, starting from 0 (rightmost bit
 *
 * Return: The value of the bit at the given index or -1 if an error occurred.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int sharade = 1UL << index;
	int gain = (n & sharade) ? 1 : 0;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	return (gain);
}
