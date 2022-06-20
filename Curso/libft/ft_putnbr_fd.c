/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:46:05 by dcerrato          #+#    #+#             */
/*   Updated: 2022/06/20 20:34:57 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    print_digits(int n, int fd)
{
    int        i;
    char    digit[10];

    i = 0;
    while (n > 9)
    {
        digit[i] = '0' + n % 10;
        i++;
        n /= 10;
    }
    digit[i] = '0' + n;
    while (i >= 0)
    {
        write (fd, &digit[i], 1);
        i--;
    }
}

void    ft_putnbr_fd(int n, int fd)
{
    if (n < 0)
    {
        write (fd, "-", 1);
        if (n == -2147483648)
        {
            write (fd, "2", 1);
            n = 147483648;
        }
        else
            n *= (-1);
    }
    print_digits(n, fd);
}
