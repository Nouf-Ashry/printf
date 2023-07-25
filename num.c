#include "main.h"
/**
 * conve - turn function
 * @n: number
 * @base: base
 * @flag: arg flag
 * @param: paramter struct
 * Return: str
 */
char *conve(long int n, int base, int flag, paramter *param)
{
	static char *arr;
	static char buf[50];
	char sig = 0;
	char *ptr;
	unsigned long num = n;
	(void)param;

	if (!(flag & CONV_UNSIGNED) && n < 0)
	{
		num = -n;
		sig = '-';
	}
	arr = flag & CONV_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buf[49];
	*ptr = '\0';
	do {
		*--ptr = arr[num % base];
		num /= base;
	} while (num != 0);
	if (sig)
		*--ptr = sig;
	return (ptr);
}
/**
 * prints_unsigned - prints_unsigned
 * @param: pointer struct
 * @p: pointer
 * Return: void
 */
int prints_unsigned(va_list p, paramter *param)
{
	unsigned long k;

	if (param->l_m)
		k = (unsigned long)va_arg(p, unsigned long);
	else if (param->h_m)
		k = (unsigned short int)va_arg(p, unsigned int);
	else
		k = (unsigned int)va_arg(p, unsigned int);
	param->unsign = k;
	return (prints_num(conve(k, 10, CONV_UNSIGNED, param), param));
}
/**
 * prints_address - prints_address
 * @param: pointer struct
 * @p: pointer
 * Return: void
 */
int prints_address(va_list p, paramter *param)
{
	unsigned long int num = va_arg(p, unsigned long int);
	char *st;

	if (!num)
	{
		return (_puts("(nil)"));
	}
	st = conve(num, 16, CONV_UNSIGNED | CONV_LOWERCASE, param);
	*--st = 'x';
	*--st = '0';
	return (prints_num(st, param));
}
/**
 * _isdigit - _isdigit
 * @c: character
 * Return: 1 for digit - 0 for not
*/
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
