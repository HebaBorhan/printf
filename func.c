#include "main.h"
#include <stddef.h>
#include <unistd.h>
/**
 * func - dealing with struct and format
 * @format: string
 * @args: arguments
 *
 * Return: count
 */
int func(const char *format, va_list args)
{
spec_t sps[] = {
{'c', print_char},
{'s', print_string},
{'%', print_per},
{'\0', NULL}};
int i, j, tmp, count = 0;
char a, b;
for (i = 0; format[i]; i++)
{
Start:
if (format[i] != '%')
{
a = format[i];
count += write(1, &a, 1);
}
else if (format[i] == '%')
{
i++;
tmp = i;
while (format[i] == ' ')
{
i++;
}
if (format[i] == '\0' || format[tmp] == '\0')
{
return (-1);
}
for (j = 0; sps[j].spec; j++)
{
if (format[i] == sps[j].spec)
{
count += sps[j].f(args);
goto Start;
}
if (sps[j].spec == '\0')
{
b = format[i];
count += write (1, &b, 1);
}
}
}
}
return (count);
}

