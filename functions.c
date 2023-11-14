#include "main.h"
#include <stddef.h>
#include <unistd.h>
/**
* _strlen - returns the length of a string
* @string: the string to be checked
* Return: i which is the length of the string
*/
int _strlen(char *string)
{
int length;
for (length = 0; string[length] != '\0'; length++)
{
}
return (length);
}
/**
* print_char - prints character
* @args: arguments
* Return: 1 which is char length
*/
int print_char(va_list args)
{
char c = va_arg(args, int);
write(1, &c, 1);
return (1);
}
/**
* print_string - prints string
* @args: arguments
* Return: string length
*/
int print_string(va_list args)
{
char *string = va_arg(args, char *);
int length;
if (string == NULL)
{
write(1, "(null)", 6);
return (6);
}
length = _strlen(string);
write(1, string, length);
return (length);
}
/**
* print_per - prints %
* Return: 1 which is % length
*/
int print_per(void)
{
char b = '%';
write(1, &b, 1);
return (1);
}
