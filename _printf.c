#include "main.h"
/**
* _printf - a function that prints anything
* @format:  is a list of types of arguments passed to the function*
* Return: returns nothing
*/
int _printf(const char *format, ...)
{
	p_dtype tok[] = {
		{"%s", print_string},
		{"%d", print_d},
		{"%c", print_char},
		{"%i", print_int},
		{"%%", percent}
	};
	const char *str = format;
	va_list args;
	int num = 0, i, j;

	va_start(args, format);
	if (str == NULL || (str[0] == '%' && str[1] == '\0'))
		return (-1);
start:
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			for (j = 0; j < 5; ++j)
			{
				if (str[i + 1] == tok[j].specifer[1])
				{
					num = num + tok[j].ops(args);
					i + 2;
					goto start;
				}
				j--;
			}
		}
		_putchar(str[i]);
		num++;
		i++;
	}
	va_end(args);
	return (num);
}
