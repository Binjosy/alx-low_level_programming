#include "main.h"
#include <stdio.h>
/**
 * error_file - check if a file is opened and handles errors
 * @file_from: initial file to copy from and to check
 * @file_to: destination file to copy to
 * @argv: argument vector
 * Return: no return
 */
void error_file(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: cant't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't write to %s\n", argv[2]);
	       exit(99);
	}
}

/**
 * main - copies the contents of a file to another file
 * @argc: arument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, err_close;
	ssize_t n, nwr;
	char buff[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "usage: cp file_from file_to");
		exit(97);
	}
	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(file_from, file_to, argv);

	n = 1024;
	while (n == 1024)
	{
		n = read(file_from, buff, 1024);
		if (n == -1)
			error_file(-1, 0, argv);
		nwr = write(file_to, buff, n);
		if (nwr == -1)
		error_file(0, -1, argv);
	}

	err_close = close(file_from);
if (err_close == -1)
{
dprintf(STDERR_FILENO, "Error: can't close fd %d\n", file_from);
exit(100);
}
err_close = close(file_to);
if (err_close == -1)
{
	dprintf(STDERR_FILENO, "Error: can't close fd %d\n", file_to);
	exit(100);
}
return (0);
}
