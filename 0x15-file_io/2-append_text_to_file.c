#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: the name of the file to append content to
 * @text_content: the content to be appended to the file
 * Return: 1 on seccess or -1 if it faills
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int len;
	int rwr;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	if (text_content)
	{
		for (len = 0; text_content[len];)
			len++;
		rwr = write(fd, text_content, len);

		if (rwr == -1)
			return (-1);
	}
	close(fd);
	return (1);
}

