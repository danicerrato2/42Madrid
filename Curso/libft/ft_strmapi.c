/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:40:49 by dcerrato          #+#    #+#             */
/*   Updated: 2022/06/20 17:59:46 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
    char    *newStr;
    int     sLen;
    int     i;

    sLen = ft_strlen((char *)s);
    newStr = malloc(sLen + 1);
    if (newStr == NULL)
        return (NULL);
    i = 0;
    while (i != sLen)
    {
        newStr[i] = f(i, s[i]);
        i++;
    }
    newStr[i] = '\0';
    return (newStr);
}
