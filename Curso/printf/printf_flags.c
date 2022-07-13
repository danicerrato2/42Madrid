/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:07:41 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/13 13:19:32 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_flags(t_flags *flags)
{
	flags->width = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = -1;
	flags->sharp = 0;
	flags->space = 0;
	flags->plus = 0;
}

int	ft_atoi(char **str)
{
	int	nbr;

	nbr = 0;
	while ((*str)[0] >= '0' && (*str)[0] <= '9')
	{
		nbr = nbr * 10 + (*str)[0] - '0';
		*str += 1;
	}
	*str -= 1;
	return (nbr);
}

void	get_flags(char **str, t_flags *flags)
{
	initialize_flags(flags);
	while ((*str)[0] == '-' || (*str)[0] == '0' || (*str)[0] == '.' || \
			(*str)[0] == '#' || (*str)[0] == ' ' || (*str)[0] == '+' || \
			((*str)[0] >= '1' && (*str)[0] <= '9'))
	{
		if ((*str)[0] == '-')
			flags->minus = 1;
		else if ((*str)[0] == '0')
			flags->zero = 1;
		else if ((*str)[0] == '.')
		{
			*str += 1;
			flags->dot = ft_atoi(str);
		}
		else if ((*str)[0] == '#')
			flags->sharp = 1;
		else if ((*str)[0] == ' ')
			flags->space = 1;
		else if ((*str)[0] == '+')
			flags->plus = 1;
		else
			flags->width = ft_atoi(str);
		*str += 1;
	}
}

int	print_width(t_flags flags)
{
	int		written;
	char	c;

	written = 0;
	c = ' ';
	if (flags.zero != 0 && flags.minus == 0)
		c = '0';
	while (flags.width > 0)
	{
		written += write(1, &c, 1);
		flags.width--;
	}
	return (written);
}

int	ft_strlen(char *str)
{
	int	i;
	int	length;

	length = 0;
	if (str != NULL)
	{
		i = 0;
		while (str[i] != '\0')
		{
			i++;
			length++;
		}
	}
	return (length);
}
