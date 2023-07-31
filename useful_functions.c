#include "main.h"

/**
 * itoa - changes a number to a string.
 * @value: the number.
 * @str: a pointer to a block of memory.
 * @base: an integer stands for the base of the number.
 *
 * Return: a string.
 */
char *itoa(int value, char *str, int base)
{
	int i = 0;
	int is_negative = 0, digit;

	if (value == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}

	if (value < 0 && base == 10)
	{
		is_negative = 1;
		value = abs(value);
	}

	while (value != 0)
	{
		digit = value % base;
		str[i++] = (digit > 9) ? (digit - 10) + 'a' : digit + '0';
		value /= base;
	}

	if (is_negative)
		str[i++] = '-';

	str[i] = '\0';

	reverse_string(str);

	return (str);
}

/**
 * reverse_string - reverses a string.
 * @str: a string.
 *
 * Return: void.
 */
void reverse_string(char *str)
{
	int i = 0;
	int j = strlen(str) - 1;
	char temp;

	while (i < j)
	{
		temp = str[i];
		str[i++] = str[j];
		str[j--] = temp;
	}
}
