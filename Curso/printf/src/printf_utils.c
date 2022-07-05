/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:45:30 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/05 10:40:46 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_strcpy(char *dst, const char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

int	get_nbr_size_in_hexa(unsigned long long nbr)
{
	int	size;

	size = 1;
	while (nbr >= 16)
	{
		nbr /= 16;
		size++;
	}
	return (size);
}

int	print_ptr(unsigned long long ptr)
{
	int		written;
	char	base16[16];
	char	*nbr;
	int		nbr_size;

	ft_strcpy(base16, "0123456789abcdef");
	written = write(1, "0x", 2);
	nbr_size = get_nbr_size_in_hexa(ptr);
	nbr = malloc(nbr_size + 1);
	if (nbr == NULL)
		return (written);
	nbr[nbr_size] = 0;
	while (nbr_size > 0)
	{
		nbr[nbr_size - 1] = base16[ptr % 16];
		ptr /= 16;
		nbr_size--;
	}
	written += write(1, nbr, ft_strlen(nbr));
	free(nbr);
	return (written);
}

int	print_hexa(unsigned int n, char case_type)
{
	char	base16[16];
	int		written;
	char	*nbr;
	int		nbr_size;

	if (case_type == 'X')
		ft_strcpy(base16, "0123456789ABCDEF");
	else
		ft_strcpy(base16, "0123456789abcdef");
	written = 0;
	nbr_size = get_nbr_size_in_hexa(n);
	nbr = malloc(nbr_size + 1);
	if (nbr == NULL)
		return (written);
	nbr[nbr_size] = 0;
	while (nbr_size > 0)
	{
		nbr[nbr_size - 1] = base16[n % 16];
		n /= 16;
		nbr_size--;
	}
	written += write(1, nbr, ft_strlen(nbr));
	free(nbr);
	return (written);
}
