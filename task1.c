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
int counter, cell, digit, numcp;
char sign = '\0';
char integer;
cell = 1;
counter = 0;
numcp = num;
if (num < 0)
{
sign = '-';
write (1, &sign, 1);
numcp = - numcp;
num = -num;
counter++;
}
if (numcp > 0)
{
while ((numcp / cell) >= 10)
{
cell = cell * 10;
}
while (cell > 0)
{
digit = numcp / cell;
integer = digit + '0';
write (1, &integer, 1);
numcp = numcp  % cell;
cell = cell / 10;
counter++;
}
}
return (counter);
}
