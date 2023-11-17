#include "main.h"
#include <stddef.h>
#include <unistd.h>
/**
* handler - functions that handle specifiers
* @s: string
* @args: arguments
* Return: count
*/
int handler(char s, va_list args)
{
int i, count = 0;
spec_t sps[] = {
	{'c', print_char},
	{'s', print_string},
	{'r', print_rev},
	{'\0', NULL}
};
for (i = 0; i <= 4; i++)
{
if (s == sps[i].spec)
{
count += sps[i].f(args);
break;
}
else if (i == 4 && s != sps[i].spec)
{
count += 2;
write(1, "%", 1);
write(1, &s, 1);
}
}
return (count);
}

