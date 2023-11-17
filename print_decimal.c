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
int decimal = 1, count = 0;
long int digit, num = va_arg(args, int);
if (num < 0)
{
count++;
write(1, "-", 1);
num = -num;
}
while ((num / decimal) >= 10)
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

