#include "main.h"

/**
 * _strlen -  function that returns the length of a string.
 * @s : string input.
 * * Return: length of a string.
 */
int _strlen(char *s)
{
	int x = 0;

	for (; *s != '\0'; s++)
		x++;
	return (x);
}
/**
 * catsh_pre - catsh_pre
 * @ap: fmat string
 * @param: struct
 * @p: struct parameter
 * Return: pointer
*/
char *catsh_pre(char *ap, paramter *param, va_list p)
{
	int r = 0;

	if (*ap != '.')
		return (ap);
	ap++;
	if (*ap == '*')
	{
		r = va_arg(p, int);
		ap++;
	}
	else
	{
		while (_isdigit(*ap))
			r = r * 10 + (*ap++ - '0');
	}
	param->precision_f = r;
	return (ap);
}
