#include "main.h"
/**
 * _printf - Custom printf function
 * @format: Format specifier string
 * Return: Number of char printed excluding null byte
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, length;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			char a = format[i];

			write(1, &a, 1);
		} else if (format[i] == '%' && format[i + 1] == '%')
		{
			char b = format[i];

			write(1, &b, 1);
			i++;
		} else if (format[i] == '%' && format[i + 1] == 'c')
		{
			char c = va_arg(args, int);

			write(1, &c, 1);
			i++;
		} else if (format[i] == '%' && format[i + 1] == 's')
		{
			char *string = va_arg(args, char *);
			int length = _strlen(string);

			write(1, string, length);
			i++;
		}
	}
	va_end(args);
	return (i);
}
