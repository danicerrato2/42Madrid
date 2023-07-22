/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:34:51 by dcerrato          #+#    #+#             */
/*   Updated: 2023/07/21 20:01:13 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (-1);
}

int	main(int argc, char *argv[])
{
	if (argc < 5 && argv)
		return (error("Número de argumentos incorrecto\n"));
	return (0);
}
