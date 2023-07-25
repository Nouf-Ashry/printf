#include "main.h"
/**
 * prints_bin - prints_bin
 * @p: pointer
 * @param: struct
 * Return: binary num
 */
int prints_bin(va_list p, paramter *param)
{

	unsigned int num = va_arg(p, unsigned int);
	char *st = conve(num, 2, CONV_UNSIGNED, param);
	int b = 0;

	if (param->hash_f && num)
		*--st = '0';
	param->unsign = 1;
	return (b += prints_num(st, param));
}
/**
 * prints_hex - prints_hex
 * @p: pointer
 * @param: struct
 * Return: hex num
 */
int prints_hex(va_list p, paramter *param)
{
	unsigned long h;
	int a = 0;
	char *st;

	if (param->l_m)
		h = (unsigned long)va_arg(p, unsigned long);
	else if (param->h_m)
		h = (unsigned short int)va_arg(p, unsigned int);
	else
		h = (unsigned int)va_arg(p, unsigned int);

	st = conve(h, 16, CONV_UNSIGNED | CONV_LOWERCASE, param);
	if (param->hash_f && h)
	{
		*--st = 'x';
		*--st = '0';
	}
	param->unsign = 1;
	return (a += prints_num(st, param));
}
/**
 * prints_HEX - prints_HEX
 * @p: pointer
 * @param: struct
 * Return: HEX num
 */
int prints_HEX(va_list p, paramter *param)
{
	unsigned long h;
	int a = 0;
	char *st;

	if (param->l_m)
		h = (unsigned long)va_arg(p, unsigned long);
	else if (param->h_m)
		h = (unsigned short int)va_arg(p, unsigned int);
	else
		h = (unsigned int)va_arg(p, unsigned int);

	st = conve(h, 16, CONV_UNSIGNED, param);
	if (param->hash_f && h)
	{
		*--st = 'x';
		*--st = '0';
	}
	param->unsign = 1;
	return (a += prints_num(st, param));
}
/**
 * prints_octal - prints_octal
 * @p: pointer
 * @param: struct
 * Return: octal num
 */
int prints_octal(va_list p, paramter *param)
{
	unsigned long h;
	int a = 0;
	char *st;

	if (param->l_m)
		h = (unsigned long)va_arg(p, unsigned long);
	else if (param->h_m)
		h = (unsigned short int)va_arg(p, unsigned int);
	else
		h = (unsigned int)va_arg(p, unsigned int);

	st = conve(h, 8, CONV_UNSIGNED, param);
	if (param->hash_f && h)
	{
		*--st = 'x';
		*--st = '0';
	}
	param->unsign = 1;
	return (a += prints_num(st, param));
}
