#include "main.h"
/**
 * get_spec - get_spec
 * @s: the format string
 * Return: the number
 */
int (*get_spec(char *s))(va_list p, paramter *param)
{
	spec specifiers[] = {
		{"c", prints_c},
		{"s", prints_s},
		{"%", prints_per},
		{"i", prints_int},
		{"d", prints_int},
		{"b", prints_bin},
		{"o", prints_octal},
		{"u", prints_unsigned},
		{"x", prints_hex},
		{"X", prints_HEX},
		{"p", prints_address},
		{"S", prints_str},
		{"r", prints_rev},
		{"R", prints_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}
/**
 * catsh_printfunction - catsh_printfunction
 * @s: the format string
 * @p: pointer
 * @param: struct
 * Return: number
 */
int catsh_printfunction(char *s, va_list p, paramter *param)
{
	int (*f)(va_list, paramter *) = get_spec(s);

	if (f)
		return (f(p, param));
	return (0);
}
/**
 * get_f - get_f
 * @s: input
 * @param: struct
 * Return: flag
*/
int get_f(char *s, paramter *param)
{
	int i = 0;

	switch (*s)
	{
	case '+':
		i = param->plus_f = 1;
		break;
	case ' ':
		i = param->space_f = 1;
		break;
	case '#':
		i = param->hash_f = 1;
		break;
	case '-':
		i = param->minus_f = 1;
		break;
	case '0':
		i = param->zero_f = 1;
		break;
	}
	return (i);
}
/**
 * catsh_wid - catsh_wid
 * @s: input
 * @param: struct
 * @p: struct parameter
 * Return: pointer
*/
char *catsh_wid(char *s, paramter *param, va_list p)
{
	int r = 0;

	if (*s == '*')
	{
		r = va_arg(p, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			r = r * 10 + (*s++ - '0');
	}

	param->width_f = r;
	return (s);
}
