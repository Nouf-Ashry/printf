#include "main.h"

/**
 * prints_int - prints_int
 * @p: paramter
 * @param: struct
 * Return: number
 */
int prints_int(va_list p, paramter *param)
{
	long n;

	if (param->l_m)
		n = va_arg(p, long);
	else if (param->h_m)
		n = (short int)va_arg(p, int);
	else
		n = (int)va_arg(p, int);
	return (prints_num(conve(n, 10, 0, param), param));
}
/**
 * prints_str - prints_str
 * @p: paramter
 * @param: struct
 * Return: number
 */
int prints_str(va_list p, paramter *param)
{
	char *st = va_arg(p, char *);
	char *h;
	int code = 0;

	if ((int)(!st))
		return (_puts(NULL_STRING));
	for (; *st; st++)
	{
		if ((*st > 0 && *st < 32) || *st >= 127)
		{
			code += _putchar('\\');
			code += _putchar('x');
			h = conve(*st, 16, 0, param);
			if (!h[1])
				code += _putchar('0');
			code += _puts(h);
		}
		else
		{
			code += _putchar(*st);
		}
	}
	return (code);
}
