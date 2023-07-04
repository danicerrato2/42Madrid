/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:48:57 by dcerrato          #+#    #+#             */
/*   Updated: 2023/07/04 11:56:16 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main (int argc, char *argv[])
{
    if (argc < 5){
        ft_printf("Error: número de argumentos incorrecto\n\
Sintaxis: %s [infile] [comando 1] ... [comando N] [outfile]", argv[0]);
        return (-1);
    }



    return (0);
}