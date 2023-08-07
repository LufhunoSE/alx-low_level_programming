#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed on success;
 * 0 if the file cannot be opened, read fails, or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *cushion = malloc(letters);
	FILE *docket = fopen(filename, "r");
	ssize_t leeinput, leeoutput;

	if (filename == NULL)
		return (0);
	
	docket = fopen(filename, "r");
	if (docket == NULL)
		return (0);

	cushion = malloc(letters);
	if (cushion == NULL)
	{
		fclose(docket);
		return (0);
	}

	leeinput = fread(cushion, sizeof(char), letters, docket);fclose(docket);

	if (leeinput == 0)
	{
		free(cushion);
		return (0);
	}

	free(cushion);

	leeoutput = write(STDOUT_FILENO, cushion, leeinput);
	free(cushion);

	if (leeoutput != leeinput)
		return (0);

	return (leeoutput);
}

