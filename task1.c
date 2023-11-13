#include "main.h"
/**
* print_int - function that handels conversion specifiers
* of d and i specifiers
* @format: list of types of specifiers passed to the function
* @...: A variable number of integers to be printed
* Return: integer
*/
int print_int(const char *format, ...)
{
va_list integers;
int num, counter, decimal, digit;
char sign = '\0';
char integer;
decimal = 1;
counter = 0;
va_start(integers, format);
while (*format)
{
if (*format == '%' && (format[1] == 'd' || format[1] == 'i'))
{
num = va_arg(integers, int);
if (num < 0)
{
sign = '-';
num = -(num);
counter++;
write(1, &sign, 1);
}
while ((num / decimal) >= 10)
{
decimal = decimal * 10;
}
while (decimal > 0)
{
digit = num / decimal;
num = num % decimal;
decimal = decimal / 10;
integer = digit + '0';
write(1, &integer, 1);
counter++;
}
}
format++;
}
va_end(integers);
return (counter);
}

