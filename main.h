#ifndef MAIN_H
#define MAIN_H

/*inserting the #include files*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

/*defining the strukts and macrose*/
#define BUF_SIZE 1024
#define BUF_FLUSH -1

/**
 * struct specifiers - making a 2 dimentional array.
 * @c: a string holds the format speccifiers charactrs.
 * @f: a pointer to a function that will handle the argument.
 *
 * Description: making a 2 dimentional array that that holdes the format speccifiers charactrs and a pointer to it's associate function.
 */
typedef struct specifiers
{
	char *c;
	int (*f)(va_list arg_list);
} specifier_f;

/*_____________________________________functions prototypes_____________________________________*/

/*useful_functions.c*/
char* itoa(int value, char* str, int base);
void reverse_string(char* str);

/*writeing_functions.c*/
int handle_buffer(char c);
int print_from_to(char *start, char *end);

/*format_specifier_functions.c*/
int (*get_format_specifier(char *s))(va_list arg_list);
int get_handling_function(char *s, va_list arg_list);

/*handling_arguments_functions.c*/
int print_char(va_list arg_list);
int print_int(va_list arg_list);
int print_string(va_list arg_list);
int print_percent(va_list arg_list);
int print_unsigned(va_list arg_list);

/*myprintf.c*/
int _printf(const char *format, ...);

#endif /*the end of #ifndef MAIN_H*/
