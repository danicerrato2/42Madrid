#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "inc/libft.h"

int	ft_printf(char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	print_ptr(void *ptr);
int	print_uint(unsigned int n);
int	print_hexa(unsigned int n, char case);

# endif
