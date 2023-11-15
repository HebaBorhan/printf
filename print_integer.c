#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
* print_int - function that handels conversion specifiers
* of d and i specifiers
* @integers: list of arguments to be prented
* Return: counter
*/
int print_int(va_list args)
{
int num = va_arg(args, int);
int counter, decimal, digit;
char integer, sign = '\0';
decimal = 1;
counter = 0;
if (num < 0)
{
sign = '-';
write(1, &sign, 1);
num = -num;
counter++;
}
while ((num / decimal) >= 10)
{
decimal = decimal * 10;
}
while (decimal >= 1)
{
digit = num / decimal;
integer = digit + '0';
write(1, &integer, 1);
num = num - (decimal * 10);
decimal = decimal / 10;
counter++;
}
return (counter);
}

