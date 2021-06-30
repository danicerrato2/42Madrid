/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:40:16 by dcerrato          #+#    #+#             */
/*   Updated: 2021/06/30 19:56:53 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_addr(unsigned long dir)
{
	char	digits[16];
	int		i;

	i = 15;
	while (dir != 0)
	{
		if (dir % 16 <= 9)
			digits[i] = '0' + dir % 16;
		else
			digits[i] = 'a' + dir % 16 - 10;
		i--;
		dir /= 16;
	}
	while (i >= 0)
	{
		digits[i] = '0';
		i--;
	}
	write (1, digits, 16);
	write (1, ": ", 2);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_print_hexa(char *dir)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (i < 16)
	{
		if (flag == 0 && i % 2 == 1)
			write (1, " ", 1);
		else if (flag == 1 && *(dir + i) != '\0')
		{	
			ft_putchar("0123456789abcdef"[*(dir + i) / 16]);
			ft_putchar("0123456789abcdef"[*(dir + i) % 16]);
		}
		else if (flag == 1)
		{
			flag = 0;
			write (1, "00", 2);
		}
		if (i % 2 == 1)
			write (1, " ", 1);
		i++;
	}
}

void	ft_print_text(char *dir)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (i < 16 && flag == 1)
	{
		if (dir[i] < 32 || dir[i] == 127)
		{
			if (dir[i] == 0)
				flag = 0;
			write (1, ".", 1);
		}
		else
			write (1, &dir[i], 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	if (size <= 0)
		return (addr);
	i = 0;
	while (i < size)
	{
		ft_print_addr((unsigned long)addr + i);
		ft_print_hexa((char *)addr + i);
		ft_print_text((char *)addr + i);
		write (1, "\n", 1);
		i += 16;
	}
	return (addr);
}
