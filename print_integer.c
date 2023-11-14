#include "main.h"
/**
* print_int - function that handels conversion specifiers
* of d and i specifiers
* @integers: list of arguments to be prented
* Return: counter
*/
int print_int(va_list integers)
{
int num = va_arg(integers, int);
int counter, decimal, digit;
char sign = '\0';
char integer;
decimal = 1;
counter = 0;
if (num < 0)
{
sign = '-';
write(1, &sign, 1);
num = -num;
counter++;
}
if (num > 0)
{
while ((num / decimal) >= 10)
{
decimal = decimal * 10;
}
while (decimal > 0)
{
digit = num / decimal;
integer = digit + '0';
write(1, &integer, 1);
num = num  % decimal;
decimal = decimal / 10;
counter++;
}
}
return (counter);
}

