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
unsigned int numcp;
char sign = '\0';
char integer;
decimal = 1;
counter = 0;
if (num < 0)
{
sign = '-';
write (1, &sign, 1);
numcp = - num;
counter++;
}
else
{
    numcp = num;
}
if (numcp > 0)
{
while ((numcp / decimal) >= 10)
{
decimal = decimal * 10;
}
while (decimal > 0)
{
digit = numcp / decimal;
integer = digit + '0';
write (1, &integer, 1);
numcp = numcp  % decimal;
decimal = decimal / 10;
counter++;
}
}
return (counter);
}


&& *(sps[i].spec) != format[i]