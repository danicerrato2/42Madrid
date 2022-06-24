/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:39:37 by dcerrato          #+#    #+#             */
/*   Updated: 2022/06/20 17:55:12 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int get_num_digits(int n)
{
    int numDigits;

    numDigits = 1;
    while (n > 9)
    {
        n /= 10;
        numDigits++;
    }
    return numDigits;
}

char	*ft_itoa(int n)
{
    int     isNegative;
    int     numDigits;
    char    *number;

    if (n == -2147483648)
        return ft_strdup("-2147483648");
    isNegative = 0;
    if (n < 0)
    {
        isNegative = 1;
        n = -n;
    }
    numDigits = get_num_digits(n);
    number = malloc(isNegative + numDigits + 1);
    if (number == NULL)
        return (NULL);
    if (isNegative)
        number[0] = '-';
    number[isNegative + numDigits] = '\0';
    while (--numDigits >= 0)
    {
        number[isNegative + numDigits] = n % 10 + 48;
        n /= 10;
    }
    return (number);
}
