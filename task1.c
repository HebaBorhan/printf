#include "main.h"
/**
* print_int - function that handels conversion specifiers
* of d and i specifiers
* @integers: list of arguments to be prented
* Return: integer
*/
int print_int(va_list integers)
{
int num = va_arg(integers, int);
int counter, decimal, digit, numcp;
char sign = '\0';
char integer;
decimal = 1;
counter = 0;
numcp = num;
if (num < 0)
{
sign = '-';
numcp = - num;
counter++;
write (1, &sign, 1);
}
while ((numcp / decimal) >= 10)
{
decimal = decimal * 10;
}
while (decimal > 0)
{
digit = numcp / decimal;
numcp = numcp % decimal;
decimal = decimal / 10;
integer = digit + '0';
write (1, &integer, 1);
counter++;
}
return (counter);
}
