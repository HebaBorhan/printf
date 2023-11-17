#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "main.h"
/**
* print_deci - function that handels conversion specifiers
* of d and i specifiers
* @args: list of arguments to be prented
* Return: counter
*/
int print_deci(va_list args)
{
int digit, num = va_arg(args, int);
int decimal, count = 0;
char integer;
decimal = 1;
if (num < 0)
{
count++;
write(1, "-", 1);
num = -num;
}
while ((num / decimal) > 1)
decimal = decimal * 10;
while (decimal >= 1)
{
digit = num / decimal;
if (digit == 0)
write(1, "0", 1);
else
{
integer = digit + '0';
write(1, &integer, 1);
}
num = num % decimal;
decimal = decimal / 10;
count++;
}
return (count);
}

