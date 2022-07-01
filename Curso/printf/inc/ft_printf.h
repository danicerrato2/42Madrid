#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int print_digits(unsigned int n);
int	ft_putnbr(int n);
int	print_ptr(void *ptr);
int	print_hexa(unsigned int n, char case_type);

# endif
