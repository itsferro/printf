#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: a string to print contains format specifiers.
 * 
 * Return:the number of characters printed
 *	(excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list arg_list;
	unsigned int nbprinted = 0;
	char *f_str = (char *)format, *check_point;

	if (f_str == NULL)
		return (-1);

	va_start(arg_list, format);
	while (*f_str != '\0')
	{
		if (*f_str != '%')
		{
			nbprinted += handle_buffer(*f_str);
		}
		else
		{
			check_point = f_str;
			f_str++;
			if (get_format_specifier(f_str) == NULL)
			{
				nbprinted += print_from_to(check_point, f_str);
			}
			else
			{
				nbprinted += get_handling_function(f_str, arg_list);
			}
		}
		f_str++;
	}
	handle_buffer(BUF_FLUSH);
	va_end(arg_list);
	return (nbprinted);
}
