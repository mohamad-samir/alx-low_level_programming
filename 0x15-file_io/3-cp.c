#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 1024

void error_exit(char *message, int exit_code);
void copy_file(int fd_from, int fd_to);
void close_fd(int fd);

/**
 * main - copies the content of a file to another file.
 * @argc: number of arguments.
 * @argv: array of arguments.
 *
 * Return: 0 on success, otherwise exit with code 97, 98, 99, or 100.
 */
int main(int argc, char **argv)
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit("Error: Can't read from file %s\n", 98);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		error_exit("Error: Can't write to %s\n", 99);

	copy_file(fd_from, fd_to);
	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}

/**
 * error_exit - prints an error message to stderr and exits with an exit code.
 * @message: error message.
 * @exit_code: exit code.
 */
void error_exit(char *message, int exit_code)
{
	dprintf(STDERR_FILENO, message, argv[1]);
	exit(exit_code);
}

/**
 * copy_file - copies the content of a file to another file.
 * @fd_from: file descriptor of the file to copy from.
 * @fd_to: file descriptor of the file to copy to.
 */
void copy_file(int fd_from, int fd_to)
{
	int rd, wr;
	char buf[BUFSIZE];

	do {
		rd = read(fd_from, buf, BUFSIZE);
		if (rd == -1)
			error_exit("Error: Can't read from file %s\n", 98);
		wr = write(fd_to, buf, rd);
		if (wr == -1)
			error_exit("Error: Can't write to %s\n", 99);
	} while (rd == BUFSIZE);
}

/**
 * close_fd - closes a file descriptor and exits with an exit code
 * if an error occurs.
 * @fd: file descriptor to close.
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
		error_exit("Error: Can't close fd %d\n", 100);
}
