#include <stdio.h>
#include "main.h"

/**
 * get_endianness - Check the endianness of the system.
 *
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
	unsigned int digits = 1;
	char *indicator = (char *)&digits;

	return (*indicator);
}
