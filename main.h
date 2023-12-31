#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
/**
* struct spec - Struct of specifiers
* @spec: specifiers
* @f: function associated
*/
typedef struct spec
{
char spec;
int (*f)(va_list);
} spec_t;
int _strlen(char *string);
int print_char(va_list args);
int print_string(va_list args);
int print_per(void);
int print_deci(va_list args);
int print_rev(va_list args);
int handler(char s, va_list args);
int func(const char *format, va_list args);
int _printf(const char *format, ...);
#endif

