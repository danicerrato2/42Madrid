/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:31:42 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/13 16:36:36 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	comprobar_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (-1);
		else if ((base[i] > 8 && base[i] < 14) || base[i] == ' ')
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

int	calculate_number(char *base, char *str, int num_base)
{
	int	number;
	int	i;
	int	j;
	int	flag;

	number = 0;
	i = 0;
	flag = 0;
	while (flag == 0)
	{
		j = 0;
		while (base[j] != '\0' && j != -1)
		{
			if (str[i] == base[j])
			{
				number = num_base * number + j;
				j = -2;
			}
			j++;
		}
		if (j != -1)
			flag = 1;
		i++;
	}
	return (number);
}

void	reverse_number(char *number, int size)
{
	char	aux;
	int		i;

	i = 0;
	while (i < size / 2)
	{
		aux = number[i];
		number[i] = number[size - 1 - i];
		number[size - 1 - i] = aux;
		i++;
	}
}
