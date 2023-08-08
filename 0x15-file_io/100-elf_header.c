#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * print_error - Print an error message to stderr and exit with status code 98
 * @message: The error message to be displayed
 */
void print_error(const char *message)
{
	fprintf(stderr, "Error: %s\n", message);
	exit(98);
}

/**
 * print_elf_header_info - Print the information contained in the ELF header
 * @elf_header: Pointer to the ELF header structure
 */
void print_elf_header_info(const Elf64_Ehdr *elf_header)
{
	int i;

	printf("Magic: ");
	for (i = 0; i < EI_NIDENT; ++i)
	{
		printf("%02x ", elf_header->e_ident[i]);
	}
	printf("\n");

	printf("Class: %s\n", elf_header->e_ident[EI_CLASS] == ELFCLASS32 ?
		"ELF32" : "ELF64");

	printf("Data: %s\n",
		elf_header->e_ident[EI_DATA] == ELFDATA2LSB ?
		"2's complement, little-endian" : "2's complement, big-endian");

	printf("Version: %d\n", elf_header->e_ident[EI_VERSION]);

	printf("OS/ABI: %s\n",
		elf_header->e_ident[EI_OSABI] == ELFOSABI_SYSV ?
		"UNIX - System V" : "Unknown");

	printf("ABI Version: %d\n", elf_header->e_ident[EI_ABIVERSION]);

	printf("Type: %s\n",
		elf_header->e_type == ET_EXEC ?
		"EXEC (Executable file)" : "Unknown");

	printf("Entry point address: %lx\n", (unsigned long)elf_header->e_entry);
}

/**
 * main - Entry point of the ELF header information display program.
 *	Reads an ELF file and prints the information contained in the ELF header.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the command-line arguments.
 *
 * Return: Upon successful execution, returns 0.
 *	If there is an error or incorrect usage,
 *	or incorrect usage,the program prints a comprehensive error message
 *	to stderr and exits with status code 98.
 */
int main(int argc, char *argv[])
{
	const char *elf_filename = argv[1];
	int fd = open(elf_filename, O_RDONLY);
	
	Elf64_Ehdr elf_header;

	if (argc != 2)
	{
		print_error("Usage: elf_header elf_filename");
	}

	if (fd == -1)
	{
		print_error("Failed to open the ELF file.");
	}

	if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		close(fd);
		print_error("Failed to read ELF header.");
	}

	if (!(elf_header.e_ident[EI_MAG0] == ELFMAG0 &&
		elf_header.e_ident[EI_MAG1] == ELFMAG1 &&
		elf_header.e_ident[EI_MAG2] == ELFMAG2 &&
		elf_header.e_ident[EI_MAG3] == ELFMAG3))
	{
		close(fd);
		print_error("Not an ELF file.");
	}

	print_elf_header_info(&elf_header);

	close(fd);
	return (0);
}
