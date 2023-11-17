#include "main.h"
#include <stddef.h>
#include <unistd.h>

/**
 * print_rev - prints a string in reverse
 * @s: string to be printed
 *
 * Return: int number of char printed
 */

int print_rev(va_list args, char *s)
{
	int i, count;

	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	while (i--)
	{
		char c = va_arg(args, char *s);

		count = 0;

		write(1, &c, 1);
		count++;
	}
		return (count);
}
