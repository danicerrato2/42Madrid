/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:07:41 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/05 11:42:45 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	get_flags(char **str, t_flags *flags)
{
	initiate_flags(flags);
	while ((*str)[0] == '-' || (*str)[0] == '0' || (*str)[0] == '.' || \
			(*str)[0] == '#' || (*str)[0] == ' ' || (*str)[0] == '+' || \
			ft_is_digit((*str)[0]) == 1)
	{
		if ((*str)[0] == '-')
			flags->minus = 1;
		else if ((*str)[0] == '0')
			flags->zero = 1;
		else if((*str)[0] == '.')
			flags->dot = 1;
		else if((*str)[0] == '#')
			flags->sharp = 1;
		else if((*str)[0] == ' ')
			flags->space = 1;
		else if((*str)[0] == '+')
			flags->plus = 1;
		else
			get_width(str, flags);
	}
	return (0);
}
