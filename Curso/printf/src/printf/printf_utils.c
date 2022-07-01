#include "libftprintf.h"

int	print_ptr(void *ptr)
{
	char			digits[12];
	int				i;
	unsigned int	p;

	i = 11;
	p = (unsigned int)ptr;
	while (p != 0)
	{
		digits[i] = "0123456789abcdef"[dir % 16];
		i--;
		p /= 16;
	}
	while (i >= 0)
	{
		digits[i] = '0';
		i--;
	}
	return write(1, "0x", 2) + write(1, digits, 12);
}

int	print_hexa(unsigned int n, char case)
{
	char	base16[16];
	int		written;

	base16 = "0123456789abcdef";
	if (case == 'X')
		base16 = "0123456789ABCDEF";
	written = 0;
	while (n >= 16)
	{
		written += write(1, &base16[n / 16], 1);
		n %= 16;
	}
	written += write(1, &base16[n], 1);
	return written;
}
