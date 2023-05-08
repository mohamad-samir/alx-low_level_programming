#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 64

int main(int argc, char **argv)
{
	int fd;
	unsigned char buf[BUF_SIZE];

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: cannot open file '%s'\n", argv[1]);
		exit(98);
	}

	if (read(fd, buf, BUF_SIZE) != BUF_SIZE)
	{
		fprintf(stderr, "Error: cannot read file '%s'\n", argv[1]);
		exit(98);
	}

	// Check for magic number
	if (buf[0] != 0x7f || buf[1] != 'E' || buf[2] != 'L' || buf[3] != 'F')
	{
		fprintf(stderr, "Error: file '%s' is not an ELF file\n", argv[1]);
		exit(98);
	}

	// Parse the ELF header fields
	printf("ELF Header:\n");

	// Class
	printf("  Class:                             ");
	if (buf[4] == 1)
		printf("ELF32\n");
	else if (buf[4] == 2)
		printf("ELF64\n");
	else
		printf("<unknown>\n");

	// Data encoding
	printf("  Data:                              ");
	if (buf[5] == 1)
		printf("2's complement, little endian\n");
	else if (buf[5] == 2)
		printf("2's complement, big endian\n");
	else
		printf("<unknown>\n");

	// Version
	printf("  Version:                           %d (current)\n", buf[6]);

	// OS/ABI
	printf("  OS/ABI:                            ");
	switch (buf[7])
	{
		case 0:
			printf("UNIX - System V\n");
			break;
		case 3:
			printf("UNIX - GNU\n");
			break;
		default:
			printf("<unknown>\n");
			break;
	}

	// ABI version
	printf("  ABI Version:                       %d\n", buf[8]);

	// Type
	printf("  Type:                              ");
	switch (*(short *)(buf + 16))
	{
		case 1:
			printf("REL (Relocatable file)\n");
			break;
		case 2:
			printf("EXEC (Executable file)\n");
			break;
		case 3:
			printf("DYN (Shared object file)\n");
			break;
		case 4:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown>\n");
			break;
	}

	// Entry point address
	printf("  Entry point address:               0x%x\n", *(unsigned int *)(buf + 24));

	close(fd);
	return 0;
}
