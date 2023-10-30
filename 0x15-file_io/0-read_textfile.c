#include "main.h"
/**
 * read_textfile- A function reads text file print to STDOUT
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: number of letters printed
 *
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fd;
	ssize_t nrd;
	ssize_t nwr;
	char *buff;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buff = malloc(sizeof(char) * letters);
	nrd = read(fd, buff, letters);
	nwr = write(STDOUT_FILENO, buff, nrd);

	close(fd);
	free(buff);
	return (nwr);
}
