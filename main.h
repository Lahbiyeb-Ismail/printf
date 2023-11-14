#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct flags - struct containing flags to "turn on"
 *
 * * @plus: flag for the '+' (forces to precede the result with (+ or -) sign)
 * * @space: flag for the ' ' (if no sign is going to be written,
 * a blank space is inserted befor the value)
 * * @hash: flag for the '#' (Used with o, x or X specifiers the value is
 * preceeded with 0, 0x or 0X respectively for values different than zero.)
 *
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct prints - Struct op
 *
 * @specifier: The specifier type
 * @print_func: The function associated
 */
typedef struct prints
{
	char *specifier;
	void (*print_func)(int *char_len, va_list args, flags_t *flags);
} print_t;

int _printf(const char *format, ...);
int handle_format_specifier(const char *format, va_list args);
char *handle_flags(const char *format, int *i, flags_t *flags);
int _putchar(char c);
void (*get_print_format(char *spc))(int *char_len, va_list args, flags_t *f);
char *copy_str(char c1);

/* TASK --> 0 */
void print_char(int *char_len, va_list args, flags_t *flags);
void print_str(int *char_len, va_list args, flags_t *flags);
void print_perc(int *char_len, va_list args, flags_t *flags);

#endif