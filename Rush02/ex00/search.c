/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 18:53:40 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/11 22:41:28 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

char	*search_pair(struct s_dicc *entry, char *num)
{
	struct s_dicc	*aux;

	aux = entry;
	while (aux->next != NULL)
	{
		if (aux->number_and_word[0][2] == '\0')
			if (aux->number_and_word[0][0] == num[0])
				if (aux->number_and_word[0][1] == num[1])
					return (aux->number_and_word[1]);
		aux = aux->next;
	}
	return (NULL);
}

char	*search_dec(struct s_dicc *entry, char num)
{
	struct s_dicc	*aux;

	aux = entry;
	while (aux->next != NULL)
	{
		if (aux->number_and_word[0][0] == num)
			if (aux->number_and_word[0][1] == '0')
				return (aux->number_and_word[1]);
		aux = aux->next;
	}
	return (NULL);
}

char	*search_in_dic(struct s_dicc *entry, char digit)
{
	struct s_dicc	*aux;

	aux = entry;
	while (aux->next != NULL)
	{
		if (aux->number_and_word[0][1] == '\0')
			if (aux->number_and_word[0][0] == digit)
				return (aux->number_and_word[1]);
		aux = aux->next;
	}
	return (NULL);
}

char	*search_units(struct s_dicc *entry, char *num, int large)
{
	int				i;
	struct s_dicc	*aux;

	if (large < 3 && num)
		return ("");
	aux = entry;
	while (aux->next != NULL)
	{
		if (aux->number_and_word[0][0] == '1')
		{
			i = 1;
			while (aux->number_and_word[0][i] != '\0' && i < large)
				i++;
			if (aux->number_and_word[0][i] == '\0' && i == large)
				return (aux->number_and_word[1]);
		}
		aux = aux->next;
	}
	return (NULL);
}
