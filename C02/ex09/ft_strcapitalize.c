/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:41:19 by dcerrato          #+#    #+#             */
/*   Updated: 2021/06/30 12:51:51 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alpha(char c)
{
	if (c < '0' || c > '9')
		if (c < 'A' || c > 'Z')
			if (c < 'a' || c > 'z')
				return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 'a' && str[i] <= 'z')
		{
			if (i == 0 || !is_alpha(str[i - 1]))
				str[i] -= 32;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
			if (i != 0 && is_alpha(str[i - 1]))
				str[i] += 32;
		i++;
	}
	return (str);
}
