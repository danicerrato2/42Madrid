/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 20:22:17 by dcerrato          #+#    #+#             */
/*   Updated: 2021/06/25 20:22:20 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	rev_alpha;

	rev_alpha = 'z';
	while (rev_alpha >= 'a')
	{
		write(1, &rev_alpha, 1);
		rev_alpha--;
	}
}
