#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* TASK --> 4 */
#define BUFFER_SIZE 1024

/**
 * struct flags - struct containing flags to "turn on"
 *
 * * @plus: flag for the '+' (forces to precede the result with (+ or -) sign)
 * * @space: flag for the ' ' (if no sign is going to be written,
 * a blank space is inserted befor the value)
 * * @hash: flag for the '#' (Used with o, x or X specifiers the value is
 * preceeded with 0, 0x or 0X respectively for values different than zero.)
 * * @lg: flag for the 'l' (long) length (Used with d, i, u, o, x, X)
 * * @sh: flag for the 'h' (short) length (Used with d, i, u, o, x, X)
 *
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
	int lg;
	int sh;
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

/* GLOBAL FUNCTIONS */
int _putchar(char c);
char *copy_str(char c1);
void print_num_base(int *char_len, long n, int base, int uppercase);
void (*get_print_format(char *spc))(int *char_len, va_list args, flags_t *f);

int _printf(const char *format, ...);
int handle_format_specifier(const char *format, va_list args);
char *handle_flags(const char *format, int *i, flags_t *flags);
void flags_init(flags_t *flags);

/* TASK --> 0 */
void print_char(int *char_len, va_list args, flags_t *flags);
void print_str(int *char_len, va_list args, flags_t *flags);
void print_perc(int *char_len, va_list args, flags_t *flags);

/* TASK --> 1 */
void print_dec(int *char_len, va_list args, flags_t *flags);

/* TASK --> 2 */
void print_bin(int *char_len, va_list args, flags_t *flags);

/* TASK --> 3 */
void print_un(int *char_len, va_list args, flags_t *flags);
void print_oct(int *char_len, va_list args, flags_t *flags);
void print_hex(int *char_len, va_list args, flags_t *flags);
void print_HEX(int *char_len, va_list args, flags_t *flags);

/* TASK --> 5 */
void print_ascii(int *char_len, va_list args, flags_t *flags);

/* TASK --> 6 */
void print_address(int *char_len, va_list args, flags_t *flags);

/* TASK --> 13 */
void print_rev(int *char_len, va_list args, flags_t *flags);

/* TASK --> 14 */
void print_rot13(int *char_len, va_list args, flags_t *flags);

#endif
