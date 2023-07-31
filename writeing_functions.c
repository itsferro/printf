#include "main.h"

/**
 * print_from_to - prints the characters from a pointer ro a pointer.
 * @start: the starting pointer.
 * @end: the ending pointer.
 *
 * Return: the nnumber of bytes printed.
 *	or -1 if the write function fails.
 */
int print_from_to(char *start, char *end)
{
	int i = 0;

	for (; start <= end; i++)
	{
		handle_buffer(*start);
		start++;
	}
	return (i);
}

/**
 * handle_buffer - writing the buffer.
 * @c: a character to write to the buffer.
 *
 * Return:
 *	1 on succes
 *	-1 if write function fails
 */
int handle_buffer(char c)
{
	static int i;
	static char buffer[BUF_SIZE];

	if (c == BUF_FLUSH || i == BUF_SIZE)
	{
		write(1, buffer, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buffer[i++] = c;

	return (1);
}
