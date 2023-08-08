#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int lee_fro, lee_to;
	ssize_t lee_input, lee_output;
	char chosen[1024];

	if (argc != 3)
	{
		write(STDERR_FILENO, "Usage: ", 7);
		write(STDERR_FILENO, argv[0], strlen(argv[0]));
		write(STDERR_FILENO, " file_from file_to\n", 20);
		exit(97);
	}

	lee_fro = open(argv[1], O_RDONLY);
	
	if (lee_fro == -1)
	{
		write(STDERR_FILENO, "Error: Can't read from file ", 28);
		write(STDERR_FILENO, argv[1], strlen(argv[1]));
		write(STDERR_FILENO, "\n", 1);
		exit(98);
	}

	lee_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

	if (lee_to == -1)
	{
		write(STDERR_FILENO, "Error: Can't write to ", 22);
		write(STDERR_FILENO, argv[2], strlen(argv[2]));
		write(STDERR_FILENO, "\n", 1);
		exit(99);
	}

	while ((lee_input = read(lee_fro, chosen, sizeof(chosen))) > 0)
	{
		lee_output = write(lee_to, chosen, lee_input);
		if (lee_output != lee_input)
		{
			write(STDERR_FILENO, "Error: Can't write to ", 22);
			write(STDERR_FILENO, argv[2], strlen(argv[2]));
			write(STDERR_FILENO, "\n", 1);
			close(lee_fro);
			close(lee_to);
			exit(99);
		}
	}

	if (lee_input == -1)
	{
		write(STDERR_FILENO, "Error: Can't read from file ", 28);
		write(STDERR_FILENO, argv[1], strlen(argv[1]));
		write(STDERR_FILENO, "\n", 1);
		close(lee_fro);
		close(lee_to);
		exit(98);
	}

	if (close(lee_fro) == -1)
	{
		write(STDERR_FILENO, "Error: Can't close fd ", 22);
		write(STDERR_FILENO, "%d\n", lee_fro);
		exit(100);
	}

	if (close(lee_to) == -1)
	{
		write(STDERR_FILENO, "Error: Can't close fd ", 22);
		write(STDERR_FILENO, "%d\n", lee_to);
		exit(100);
	}

	return (0);
}

