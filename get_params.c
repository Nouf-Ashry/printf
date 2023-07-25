#include "main.h"

/**
 * get_params - get_params
 * @param: pointer struct
 * @p: pointer
 *
 * Return: void
 */
void get_params(paramter *param, va_list p)
{
	param->unsign = 0;
	param->plus_f = 0;
	param->space_f = 0;
	param->hash_f = 0;
	param->zero_f = 0;
	param->width_f = 0;
	param->minus_f = 0;
	param->precision_f = UINT_MAX;
	param->l_m = 0;
	param->h_m = 0;
	(void)p;
}
/**
 * catsh_mod - catsh_mod
 * @param: pointer struct
 * @s: string
 * Return: modifier
 */
int catsh_mod(char *s, paramter *param)
{
	int m = 0;

	switch (*s)
	{
		case 'h':
			m = param->h_m = 1;
			break;
		case 'l':
			m = param->l_m = 1;
			break;
	}
	return (m);
}
