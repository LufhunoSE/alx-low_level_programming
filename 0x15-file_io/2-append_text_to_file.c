#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * append_text_to_file - Appends text at the end of a file.
 *
 * @filename: The name of the file.
 * @text_content: The NULL terminated str to add at the end of the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int docket = open(filename, O_WRONLY | O_APPEND);

	if (filename == NULL)
		return (-1);

	if (docket == -1)
		return (-1);

	if (text_content != NULL)
	{
		int leeinput_chars = write(docket, text_content, strlen(text_content));

		if (leeinput_chars == -1)
		{
			close(docket);
			return (-1);
		}
	}

	close(docket);
	return (1);
}
