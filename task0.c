#include "main.h"
/**
 * _printf - Custom printf func
 * @format: Format specifier string
 * Return: Number of char printed excluding null byte
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, length;
	
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
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
		}
		else if (format[i] == '%')
		{
			i++;
			while (format[i] == ' ')
			{
				i++;
			}
			if (format[i] == '%')
			{
				char b = format[i];
				write(1, &b, 1);
			}
			else if (format[i] == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
			}
			else if (format[i] == 's')
			{
				char *string = va_arg(args, char *);

				if (string == NULL)
				{
					write(1, "(null)", 6);
				}
				else if (string == 0)
				{
					break;
				}
				else
				{
					length = _strlen(string);
					write(1, string, length);
				}
			}
		}
	}
	va_end(args);
	return (i);
}
