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
int i, j, count = 0;

 i = 0;

if (format == NULL || (format[i] == '\0'))
{
return (-1);
}
for (i = 0; format[i] && format; i++)
{
if (format[i] != '%')
{
char a = format[i];

count += write(1, &a, 1);
}
else if (format[i] == '%')
{
while (format[i + 1] == ' ')
{
i++;
}
if (format[i + 1] == '\0')
{
return (-1);
}
for (j = 0; sps[j].spec != '\0'; j++)
{
if (format[i + 1] == sps[j].spec)
{
count += sps[j].f(args);
i += 1;
}
}
}
}
return (count);
}

