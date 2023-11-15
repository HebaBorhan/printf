#include "main.h"
#include <stddef.h>
#include <unistd.h>
/**
* func - dealing with struct and format
* @format: string
* @args: arguments
* Return: count
*/
int func(const char *format, va_list args)
{
spec_t sps[] = {
{'c', print_char}, {'s', print_string}, {'%', print_per}};
int i, j, temp, count = 0;
char a, b;
for (i = 0; format[i] && format; i++)
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
temp = i;
while (format[i] == ' ')
{
temp++;
}
if (format[i] == '\0' || format[temp] == '\0')
{
return (-1);
}
else
{
while (j >= 0)
{
if (format[i] == sps[j].spec)
{
count += sps[j].f(args);
i++;
goto Start;
}
j--;
}
b = format[i];
count += write(1, &b, 1);
i++;
}
}
}
return (count);
}
