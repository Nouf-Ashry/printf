#include "main.h"
/**
 * _printf - function that produces output according to a format.
 * @format: string.
 * Return: the number of characters printed,
 *(excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	int code = 0;
	va_list p;
	char *pt, *first;
	paramter param = PARAM;

	va_start(p, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (pt = (char *)format; *pt; pt++)
	{
		get_params(&param, p);
		if (*pt != '%')
		{
			code += _putchar(*pt);
			continue;
		}
		first = pt;
		pt++;
		while (get_f(pt, &param))
		{
			pt++;
		}
		pt = catsh_wid(pt, &param, p);
		pt = catsh_pre(pt, &param, p);
		if (catsh_mod(pt, &param))
			pt++;
		if (!get_spec(pt))
			code += print_from_to(first, pt, param.l_m || param.h_m ? pt - 1 : 0);
		else
			code += catsh_printfunction(pt, p, &param);
	}
	_putchar(BUF_FLUSH);
	va_end(p);
	return (code);
}
