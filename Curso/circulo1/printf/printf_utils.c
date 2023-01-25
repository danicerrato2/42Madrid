/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:45:30 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/14 09:28:49 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	get_nbr_size_in_base(unsigned long long nbr, int base)
{
	int	size;

	size = 1;
	while (nbr >= (unsigned long long)base)
	{
		nbr /= base;
		size++;
	}
	return (size);
}

int	print_nbr(char *nbr, t_flags flags, char case_type)
{
	int	written;
	int	nbr_size;

	written = 0;
	nbr_size = ft_strlen(nbr);
	if (nbr[0] == '0' && flags.dot == 0)
		nbr_size = 0;
	flags.dot -= nbr_size;
	if (flags.dot < 0)
		flags.dot = 0;
	flags.width -= flags.dot + nbr_size;
	if (case_type == 'x' || case_type == 'X')
		flags.width -= 2;
	if (flags.width < 0)
		flags.width = 0;
	if (flags.minus == 0)
		written += print_width(flags);
	if (case_type == 'x' || case_type == 'X')
		written += write(1, "0", 1) + write(1, &case_type, 1);
	while (flags.dot-- > 0)
		written += write(1, "0", 1);
	written += write(1, nbr, nbr_size);
	if (flags.minus != 0)
		written += print_width(flags);
	return (written);
}

int	print_ptr(unsigned long long ptr, t_flags flags)
{
	int		written;
	char	*nbr;
	int		nbr_size;

	nbr_size = get_nbr_size_in_base(ptr, 16);
	nbr = malloc(nbr_size + 1);
	if (nbr == NULL)
		return (0);
	nbr[nbr_size] = 0;
	while (--nbr_size >= 0)
	{
		nbr[nbr_size] = "0123456789abcdef"[ptr % 16];
		ptr /= 16;
	}
	written = print_nbr(nbr, flags, 'x');
	free(nbr);
	return (written);
}

int	print_hexa(unsigned int n, char case_type, t_flags flags)
{
	char	base16[16];
	int		written;
	char	*nbr;
	int		nbr_size;

	ft_strcpy(base16, "0123456789abcdef");
	if (case_type == 'X')
		ft_strcpy(base16, "0123456789ABCDEF");
	written = 0;
	nbr_size = get_nbr_size_in_base(n, 16);
	nbr = malloc(nbr_size + 1);
	if (nbr == NULL)
		return (written);
	nbr[nbr_size] = 0;
	while (--nbr_size >= 0)
	{
		nbr[nbr_size] = base16[n % 16];
		n /= 16;
	}
	if (flags.sharp != 0 && nbr[0] != '0')
		written += print_nbr(nbr, flags, case_type);
	else
		written += print_nbr(nbr, flags, 0);
	free(nbr);
	return (written);
}
