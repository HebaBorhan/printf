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
{'\0', NULL}};
int i, j, count = 0;

for (i = 0; format[i] && format; i++)
{
if (format[i] != '%')
{
char a = format[i];

count++;
write(1, &a, 1);
}
else if (format[i] == '%')
{
i++;
while (format[i] == ' ')
{
i++;
}
if (format[i] == '\0')
{
return (-1);
}
else if (format[i] == '%')
{
write(1, "%", 1);
count++;
}
for (j = 0; sps[j].spec != '\0'; j++)
{
if (format[i] == sps[j].spec)
{
count += sps[j].f(args);
}
}
}
}
return (count);
}

