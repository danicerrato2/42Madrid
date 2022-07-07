/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:07:41 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/07 13:54:32 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	initialize_flags(t_flags *flags)
{
	flags->width = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->sharp = 0;
	flags->space = 0;
	flags->plus = 0;
}

void	get_width(char **str, t_flags *flags)
{
	int	width;

	width = 0;
	while ((*str)[0] >= '0' && (*str)[0] <= '9')
	{
		width = width * 10 + (*str)[0] - '0';
		*str += 1;
	}
	*str -= 1;
	flags->width = width;
}

void	get_flags(char **str, t_flags *flags)
{
	initialize_flags(flags);
	while ((*str)[0] == '-' || (*str)[0] == '0' || (*str)[0] == '.' || \
			(*str)[0] == '#' || (*str)[0] == ' ' || (*str)[0] == '+' || \
			ft_isdigit((*str)[0]) == 1)
	{
		if ((*str)[0] == '-')
			flags->minus = 1;
		else if ((*str)[0] == '0')
			flags->zero = 1;
		else if ((*str)[0] == '.')
			flags->dot = 1;
		else if ((*str)[0] == '#')
			flags->sharp = 1;
		else if ((*str)[0] == ' ')
			flags->space = 1;
		else if ((*str)[0] == '+')
			flags->plus = 1;
		else
			get_width(str, flags);
		*str += 1;
	}
}

int	print_width(t_flags flags)
{
	int	written;

	written = 0;
	while(flags.width > 0)
	{
		written += write(1, " ", 1);
		flags.width--;
	}
	return (written);
}
