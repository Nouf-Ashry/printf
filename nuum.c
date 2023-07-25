#include "main.h"
/**
 * prints_num - prints_num
 * @st: base number
 * @param: paramter struct
 * Return: char
 */
int prints_num(char *st, paramter *param)
{
	unsigned int i = _strlen(st);
	int g = (!param->unsign && *st == '-');

	if (!param->precision_f && *st == '0' && !st[1])
		st = "";
	if (g)
	{
		st++;
		i--;
	}
	if (param->precision_f != UINT_MAX)
	{
		while (i++ < param->precision_f)
			*--st = '0';
	}
	if (g)
		*--st = '-';
	if (!param->minus_f)
		return (prints_num_rs(st, param));
	else
		return (prints_num_ls(st, param));
}
/**
 * prints_num_rs - prints_num_rs
 * @st: base number
 * @param: paramter struct
 * Return: char
 */
int prints_num_rs(char *st, paramter *param)
{
	unsigned int n = 0, g, g2, i =  _strlen(st);
	char ch = ' ';

	if (!param->zero_f && param->minus_f)
		ch = '0';
	g = g2 = (!param->unsign && *st == '-');
	if (g && i < param->width_f && ch == '0' && !param->minus_f)
		st++;
	else
		g = 0;
	if ((param->plus_f && !g2) ||
		(!param->plus_f && param->space_f && !g2))
		i++;
	if (g && ch == '0')
		n += _putchar('-');
	if (param->plus_f && !g2 && ch == '0' && !param->unsign)
		n += _putchar('+');
	else if (!param->plus_f && param->space_f && !g2
		&& !param->unsign && param->zero_f)
		n += _putchar(' ');
	while (i++ < param->width_f)
		n += _putchar(ch);
	if (g && ch == ' ')
		n += _putchar('-');
	if (param->plus_f && !g2 && ch == ' ' && !param->unsign)
		n += _putchar('+');
	else if (!param->plus_f && param->space_f && !g2
		&& !param->unsign && param->zero_f)
		n += _putchar(' ');
	n += _puts(st);
	return (n);
}
/**
 * prints_num_ls - prints_num_ls
 * @st: base number
 * @param: paramter struct
 * Return: char
 */
int prints_num_ls(char *st, paramter *param)
{
	unsigned int n = 0, g, g2, i =  _strlen(st);
	char ch = ' ';

	if (!param->zero_f && param->minus_f)
		ch = '0';
	g = g2 =  (!param->unsign && *st == '-');
	if (g && i < param->width_f && ch == '0' && !param->minus_f)
		st++;
	else
		g = 0;

	if (param->plus_f && !g2 && !param->unsign)
		n += _putchar('+'), i++;
	else if (param->space_f && !g2 && !param->unsign)
		n += _putchar(' '), i++;
	n += _puts(st);
	while (i++ < param->width_f)
		n += _putchar(ch);
	return (n);
}
