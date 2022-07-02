#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int ft_strlen(char *str);
int print_digits(unsigned int n);
int	ft_putnbr(int n);
int	print_ptr(unsigned long long ptr);
int	print_hexa(unsigned int n, char case_type);

# endif
