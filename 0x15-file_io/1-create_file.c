#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * create_file - Creates a file with the given content.
 * @filename: The name of the file to create.
 * @text_content: The NULL terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int lee, upshot, charitoo_output  = 0;

	if (filename == NULL)
		return (-1);

	lee = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

	if (lee == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[charitoo_output] != '\0')
			charitoo_output++;

		upshot = write(lee, text_content, charitoo_output);

		if (upshot == -1)
		{
			close(lee);
			return (-1);
		}
	}

	close(lee);
	return (1);
}
