#include "main.h"
#include <stddef.h>
#include <unistd.h>

/**
 * print_rev - prints a string in reverse
 * @args: arguments
 * @s: string to be printed
 *
 * Return: int number of char printed
 */

int print_rev(va_list args)
{
	char *s;
	int i, count;

	char *s = va_arg(args, char *);

	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	while (i--)
	{
		char c = s[i];

		count = 0;

		write(1, &c, 1);
		count++;
	}
		return (count);
}
