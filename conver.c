#include "main.h"
/**
 * print_from_to - print_from_to
 * @start: start
 * @stop: stop
 * @except: except
 * Return: number
 */
int print_from_to(char *start, char *stop, char *except)
{
	int code = 0;

	while (start <= stop)
	{
		if (start != except)
			code += _putchar(*start);
		start++;
	}
	return (code);
}
/**
 * prints_rev - prints_rev
 * @p: input
 * @param: struct
 * Return: number
*/
int prints_rev(va_list p, paramter *param)
{
	int l, code = 0;
	char *st = va_arg(p, char *);
	(void)param;

	if (st)
	{
		for (l = 0; *st; st++)
			l++;
		st--;
		for (; l > 0; l--, st--)
		code += _putchar(*st);
	}
	return (code);
}
/**
 * prints_rot13 - prints_rot13
 * @p: input
 * @param: struct
 * Return: number
*/
int prints_rot13(va_list p, paramter *param)
{
	int i, in;
	int c = 0;
	char ar[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
	char *b = va_arg(p, char *);
	(void)param;

	i = 0;
	in = 0;
	while (b[i])
	{
		if ((b[i] >= 'A' && b[i] <= 'Z') || (b[i] >= 'a' && b[i] <= 'z'))
		{
			in = b[i] - 65;
			c += _putchar(ar[in]);
		}
		else
			c += _putchar(b[i]);
		i++;
	}
	return (c);
}
