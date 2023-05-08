#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters it could read and print.
 *         If the file can not be opened or read, return 0.
 *         If filename is NULL return 0.
 *         If write fails or does't write the expected num of bytes, return 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, ret;
	char *buf;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters + 1));
	if (buf == NULL)
		return (0);

	ret = read(fd, buf, letters);
	if (ret == -1)
	{
		free(buf);
		return (0);
	}

	buf[ret] = '\0';

	ret = write(STDOUT_FILENO, buf, ret);
	if (ret == -1)
	{
		free(buf);
		return (0);
	}

	free(buf);
	close(fd);

	return (ret);
}
