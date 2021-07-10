/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 12:25:54 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/10 18:55:32 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush-02.h"

char	*translate_number(int num_size, char *num, char *dic)
{
	abrir fichero
	cadena/null = buscar ocurrencia
	cerramos fichero
	si caso base (num[i] == '\0')
		devolver '\0'
	sino si fallo
		imprimir error
		devolver NULL
	sino
		actual = llamar recursion
	si actual  = NULL
		devolver NULL
	sino
		devolver concat(cadena, actual)
}
