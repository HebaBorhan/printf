#include "main.h"
#include <stddef.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format specifier string
 * Return: Number of char printed excluding null byte
 */
int _printf(const char *format, ...)
{
va_list args;
int counter;

if (format == NULL || (format[0] == '%' && format[1] == '\0'))
{
return (-1);
}

counter = 0;

va_start(args, format);

counter = func(format, args);

va_end(args);
return (counter);
}
