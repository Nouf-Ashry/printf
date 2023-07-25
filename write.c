#include "main.h"

/**
 * _puts - print string.
 * @st: input
 * Return: void
 */
int _puts(char *st)
{
	char *c = st;

	while (*st)
		_putchar(*st++);
	return (st - c);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int c)
{
	static int i;
	static char bufer[OUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUT_BUF_SIZE)
	{
		write(1, bufer, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		bufer[i++] = c;
	return (1);
}
