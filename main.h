#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int print_char(va_list arg);
int print_str(va_list arg);
int _printf(const char *format, ...);
int print_int(va_list arg);
int print_unsignedToBinary(va_list arg);
int print_unsigned_int(va_list arg);
/**
 * struct identifierStruct- picks structure to printout
 * @indentifier: type
 * @printer: printing function
 */

typedef struct identifierStruct
{
char *indentifier;
int (*printer)(va_list);
} identifierStruct;

#endif
