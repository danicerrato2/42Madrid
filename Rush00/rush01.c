/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 10:13:28 by dcerrato          #+#    #+#             */
/*   Updated: 2021/06/26 15:14:07 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c);

void	print_centro(char character, int columnas)
{
	int	j;

	j = 2;
	while (j <= columnas - 1)
	{
		ft_putchar(character);
		j++;
	}
}

void	print_linea_ini(int columnas)
{
	ft_putchar('/');
	print_centro('*', columnas);
	if (columnas > 1)
		ft_putchar('\\');
}

void	print_linea_last(int columnas)
{
	ft_putchar('\\');
	print_centro('*', columnas);
	if (columnas > 1)
		ft_putchar('/');
}

void	print_linea_intermedia(int columnas)
{
	ft_putchar('*');
	print_centro(' ', columnas);
	if (columnas > 1)
		ft_putchar('*');
}

void	rush(int columnas, int filas)
{
	int	i;

	if ((filas <= 0) || (columnas <= 0))
		return ;
	i = 1;
	while (i <= filas)
	{
		if (i == 1)
			print_linea_ini(columnas);
		else if (i == filas)
			print_linea_last(columnas);
		else
			print_linea_intermedia(columnas);
		ft_putchar('\n');
		i++;
	}	
}
