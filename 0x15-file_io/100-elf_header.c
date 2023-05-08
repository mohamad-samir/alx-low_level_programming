#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void print_usage(char *program_name) {
	dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", program_name);
}

void print_error(char *error_message, char *filename) {
	dprintf(STDERR_FILENO, "Error: %s %s\n", error_message, filename);
}

int main(int argc, char *argv[]) {
	int file_from, file_to, bytes_read, bytes_written, close_from, close_to;
	char buffer[BUFFER_SIZE];

	if (argc != 3) {
		print_usage(argv[0]);
		return 97;
	}

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1) {
		print_error("Can't read from file", argv[1]);
		return 98;
	}

	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_to == -1) {
		print_error("Can't write to", argv[2]);
		return 99;
	}

	while ((bytes_read = read(file_from, buffer, BUFFER_SIZE)) > 0) {
		bytes_written = write(file_to, buffer, bytes_read);
		if (bytes_written != bytes_read) {
			print_error("Write error to", argv[2]);
			return 99;
		}
	}

	if (bytes_read == -1) {
		print_error("Read error from", argv[1]);
		return 98;
	}

	close_from = close(file_from);
	close_to = close(file_to);
	if (close_from == -1 || close_to == -1) {
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", close_from == -1 ? file_from : file_to);
		return 100;
	}

	return 0;
}
