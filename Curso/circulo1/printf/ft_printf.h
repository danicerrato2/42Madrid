/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:41:26 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/13 14:45:12 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	int	width;
	int	minus;
	int	zero;
	int	dot;
	int	sharp;
	int	space;
	int	plus;
}	t_flags;

int		ft_printf(const char *format, ...);
int		ft_putchar(char c, t_flags flags);
int		ft_putstr(char *s, t_flags flags);
int		ft_strlen(char *str);
int		print_digits(unsigned int n, int is_negative, t_flags flags);
int		ft_putnbr(int n, t_flags flags);
int		print_ptr(unsigned long long ptr, t_flags flags);
int		print_hexa(unsigned int n, char case_type, t_flags flags);
void	ft_strcpy(char *dst, const char *src);
int		get_nbr_size_in_base(unsigned long long nbr, int base);

void	get_flags(char **str, t_flags *flags);
int		print_width(t_flags flags);
#endif
