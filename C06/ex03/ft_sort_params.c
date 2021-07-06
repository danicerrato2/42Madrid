/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:24:40 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/06 18:43:03 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	cmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if (str1[i] != '\0' && str2[i] == '\0')
		return (str1[i]);
	if (str2[i] != '\0' && str1[i] == '\0')
		return (-str2[i]);
	return (0);
}

void	print_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*aux;

	if (argc > 2)
	{
		i = argc - 1;
		while (i >= 1)
		{
			j = 0;
			while (j < i)
			{
				if (cmp(argv[j], argv[j + 1]) > 0)
				{
					aux = argv[j];
					argv[j] = argv[j + 1];
					argv[j + 1] = aux;
				}
				j++;
			}
			i--;
		}
		print_args(argc, argv);
	}
}
