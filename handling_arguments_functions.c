#include "main.h"

/**
 * print_char - prints a character.
 * @arg_list: a pointer to the arguments list.
 *
 * Return: the number of bytes printed.
 */
int print_char(va_list arg_list)
{
	char c = va_arg(arg_list, int);

	return (handle_buffer(c));
}

/**
 * print_int - prints an integer.
 * @arg_list: a pointer to the arguments list.
 *
 * Return: the number of bytes printed.
 */
int print_int(va_list arg_list)
{
	int i = va_arg(arg_list, int),
	    nbprinted = 0,
	    n = 0;
	char *str, *mem;

	str = itoa(i, malloc(sizeof(i)), 10);
	mem = str;

	n = strlen(str);
	while (nbprinted < n)
	{
		handle_buffer(*str);
		str++;
		nbprinted++;
	}
	free(mem);
	return (nbprinted);
}

/**
 * print_string - printing a string.
 * @arg_list: a pointer to the arguments list.
 *
 * Return: the number of bytes printed.
 */
int print_string(va_list arg_list)
{
	char *s = va_arg(arg_list, char *);
	unsigned int i = 0;
	int nbprinted = 0;

	if (s == NULL)
		return (0);

	i = strlen(s);
	while (nbprinted < (int)i)
	{
		handle_buffer(*s);
		s++;
		nbprinted++;
	}
	return (nbprinted);
}

/**
 * print_percent - prints a percent sign.
 * @arg_list: a pointer to the arguments list.
 *
 * Return: the number of bytes printed.
 */
int print_percent(va_list arg_list)
{
	(void)arg_list;
	return (handle_buffer('%'));
}

/**
 * print_unsigned - prints an unsigned number.
 * @arg_list: a pointer to the arguments list.
 *
 * Return: the number of bytes printed.
 */
int print_unsigned(va_list arg_list)
{
	unsigned int ui = va_arg(arg_list, unsigned int),
		     nbprinted = 0,
		     n = 0;
	char *str, *mem;
	
	str = uitoa(ui, malloc(sizeof(ui)), 10);
	mem = str;
	
	n = strlen(str);
	while (nbprinted < n)
	{
		handle_buffer(*str);
		str++;
		nbprinted++;
	}
	free(mem);
	return (nbprinted);
}
