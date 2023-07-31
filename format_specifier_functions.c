#include "main.h"

/**
 * get_format_specifier - checks what format specifier used.
 * @s: the format string.
 *
 * Return: a pointer to a function.
 */
int (*get_format_specifier(char *s))(va_list arg_list)
{
	specifier_f specifier[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"u", print_unsigned},
		{NULL, NULL}
	};
	int i;

	for (i = 0; specifier[i].c != NULL; i++)
	{
		if (specifier[i].c[0] == *s)
			return (specifier[i].f);
	}
	return (NULL);
}

/**
 * get_handling_function - call the chosen handeling function.
 * @s: the format string.
 * @arg_list: a pointer to the arguments list.
 *
 * Return: the number of bytes printed.
 */
int get_handling_function(char *s, va_list arg_list)
{
	int (*f)(va_list);

	f = get_format_specifier(s);
	if (f != NULL)
		return (f(arg_list));

	return (0);
}
