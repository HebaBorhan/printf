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
int i, temp, count = 0;

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
temp = i;
while (format[i] == ' ')
i++;
if (format[i] == '\0' || format[temp] == '\0')
return (-1);
else if (format[i] == '%')
{
print_per();
count++;
}
else
count += handler(format[i], args);
}
}
return (count);
}

