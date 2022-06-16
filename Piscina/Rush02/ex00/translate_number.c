/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 12:25:54 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/11 22:42:30 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

char	*g_digit;
char	*g_units;

int	check_number(char *str, int *num_size)
{
	int			i;
	long long	number;

	if (str == NULL)
		return (-1);
	i = 0;
	number = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		number = number * 10 + str[i] - '0';
		if (number > 4294967295)
			return (-1);
		i++;
	}
	*num_size = i;
	return (0);
}

char	*search(struct s_dicc *entry, char *num, int num_size)
{
	g_digit = "";
	g_units = "";
	if (num_size % 3 == 0 && num[0] != '0')
	{
		g_digit = search_in_dic(entry, num[0]);
		g_units = search_units(entry, num, 3);
	}
	if (num_size % 3 == 2 && num[0] == '1')
		g_digit = search_pair(entry, num);
	else if (num_size % 3 == 2 && num[0] != '0')
	{
		g_digit = search_dec(entry, num[0]);
		g_units = search_units(entry, num, 2);
	}
	if (num_size % 3 == 1)
	{
		if (num[-1] != '1')
			g_digit = search_in_dic(entry, num[0]);
		g_units = search_units(entry, num, num_size);
	}
	if (g_digit == NULL || g_units == NULL)
		return (NULL);
	return (concat_strs(g_digit, g_units));
}

void	print_number(char *str)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

char	*translate_number(int num_size, char *num, struct s_dicc *entry)
{
	char	*unit;
	char	*string;

	unit = search(entry, num, num_size);
	if (num[0] == '\0')
		return ("\0");
	else if (unit == NULL)
	{
		write(1, "Dict Error\n", 11);
		return (NULL);
	}
	else
		string = translate_number(num_size - 1, &num[1], entry);
	if (string == NULL)
		return (NULL);
	return (concat_strs(unit, string));
}
