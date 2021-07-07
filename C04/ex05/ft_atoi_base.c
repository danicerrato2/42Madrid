/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:51:20 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/07 18:46:42 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	comprobar_base_atoi(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (-1);
		else if ((base[i] > 8 && base[i] < 14) || base[i] == ' ')
			return (-1);
		j = i - 1;
		while (j >= 0)
		{
			if (base[i] == base[j])
				return (-1);
			j--;
		}
		i++;
	}
	if (i < 2)
		return (-1);
	return (i);
}

int	is_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	calculate_number(char *base, char *str, int	num_base)
{
	int	number;
	int	i;
	int	value;

	number = 0;
	i = 0;
	value = is_in_base(str[i], base);
	while (value != -1)
	{
		number = num_base * number + value;
		i++;
		value = is_in_base(str[i], base);
	}
	return (number);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	number;
	int	signo;
	int	num_base;

	num_base = comprobar_base_atoi(base);
	if (num_base == -1)
		return (0);
	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	signo = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signo *= (-1);
		i++;
	}
	number = calculate_number(base, str + i, num_base);
	return (number * signo);
}
