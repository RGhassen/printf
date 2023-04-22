#include "main.h">

/**
 * _printf - produces output according to a format.
 * @format: The format string is composed of zero or more directives.
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, count = 0;

	va list args;
	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				int c = va_arg(args, int);
				_putchar(c);
				count++;
			}
			else if (format[i] == 's')
			{
				char *s = va_arg(args, char *);
				while (s)
				{
					_putchar(*s);
					s++;
					count++;
				}
			}
			else if (format[i] == '%')
			{
				_putchar('%');
				count++;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
