#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * formatPickers - prints special characters
 * @after: char follwing "%"
 * @arg: argument for identifier
 * Return:the number of characters printed, no null bytes
 */

int formatPickers(char after, va_list arg)
{
    int formtsIndex;

    pickerStruct formts[] ={
        {"c", print_char},
        {"s", print_str},
        {NULL,NULL}

    };
    for (formtsIndex=0;formts[formtsIndex].formt != NULL;formtsIndex++)
    {
        if (formts[formtsIndex].formt[0]== after)
        return (formts[formtsIndex].printer(arg));
    }
    return (0);
}
/**
 * _print - reprica of stdio printf
 * Description: outputs in a specified format
 * writes output to stdout, the standard output stream
 * @format: a character string. 
 * is composed of zero or more directives.
 * return: number of characters printed, no null bytes.
 * return -1 for incomplete picker errors
 */
int _printf(const char *format, ...)
{
    unsigned int i;
    int formterPrinted = 0, charPrinted = 0;
    va_list arg;

    va_start(arg, format);
    if(format ==NULL)
    return (-1);

    for (i=0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            _putchar(format[i]);
            charPrinted++;
        }
        if (format[i+1] == '%')
        {
            _putchar('%');
            charPrinted++;
            i++;
            continue;
        }
        if (format[i+1] == '\0')
        return(-1);

        formterPrinted=formatPickers(format[i+1],arg);
        if(formterPrinted == -1 || formterPrinted != 0 )
        i++;
        if(formterPrinted > 0)
        charPrinted += formterPrinted;
        if (formterPrinted == 0)
        {
            _putchar('%');
            charPrinted++;
        }
    }
    va_end(arg);
    return (charPrinted);
}
