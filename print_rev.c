#include "main.h"
#include <stddef.h>
#include <unistd.h>

/**
 * print_rev - prints a string in reverse
 * @args: arguments
 *
 * Return: int number of char printed
 */

int print_rev(va_list args)
{
	char *s = va_arg(args, char *);

	int i, count;

	i = 0;
	count = 0;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		count = 6;
	}
	else
	{
		while (s[i] != '\0')
		{
			i++;
		}
		while (i--)
		{
			char c = s[i];

			write(1, &c, 1);
			count++;
		}
	}
		return (count);
}
