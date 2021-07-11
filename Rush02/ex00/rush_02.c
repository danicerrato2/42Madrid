/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 10:40:08 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/11 17:33:17 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "rush_02.h"

struct s_dicc
{
	char			*number_and_word[2];
	struct s_dicc	*next;
};

void	free_dictionary(struct s_dicc *entry)
{
	struct s_dicc	*aux;

	while (entry->next != NULL)
	{
		aux = entry->next;
		free(entry);
		entry = aux;
	}
	free(entry);
}

int	check_line(char *line, struct s_dicc *entry)
{
	int		i;
	char	*key_and_value[2];

	i = 0;
	if (line[0] == '\0')
		return (0);
	key_and_value[0] = safe_number(line, &i);
	if (key_and_value[0] == NULL)
		return (-1);
	while (line[i] == ' ')
		i++;
	if (line[i++] != ':')
		return (-1);
	while (line[i] == ' ')
		i++;
	key_and_value[1] = safe_word(line, &i);
	if (key_and_value[1] == NULL)
		return (-1);
	entry->number_and_word[0] = key_and_value[0];
	entry->number_and_word[1] = key_and_value[1];
	entry->next = NULL;
	return (0);
}

int	check_dictionary(char *dic, struct s_dicc *entry)
{
	int				fd;
	char			*line;
	struct s_dicc	*aux;

	fd = open(dic, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = read_line(fd);
	aux = entry;
	while (line != NULL && check_line(line, aux) != -1)
	{
		if (line[0] != '\0')
		{
			free(line);
			aux->next = malloc(sizeof(struct s_dicc));
			aux = aux->next;
		}
		line = read_line(fd);
	}
	aux->next = NULL;
	close(fd);
	if (line == NULL)
		return (0);
	free(line);
	return (-1);
}

void	checker(char *num_and_dicc[2], struct s_dicc *entry)
{
	int	num_size;

	if (check_number(num_and_dicc[0], &num_size) != -1)
	{
		if (check_dictionary(num_and_dicc[1], entry) != -1)
		{
			print_number(translate_number(num_size, num_and_dicc[0], entry));
			return ;
		}
		else
			write (1, "Dict ", 5);
	}
	write(1, "Error\n", 6);
}

int	main(int argc, char *args[])
{
	char			*num_and_dicc[2];
	struct s_dicc	*entry;

	num_and_dicc[0] = NULL;
	if (argc == 2)
	{
		num_and_dicc[0] = args[1];
		num_and_dicc[1] = "numbers.dict";
	}
	else if (argc == 3)
	{
		num_and_dicc[0] = args[2];
		num_and_dicc[1] = args[1];
	}
	entry = malloc(sizeof(struct s_dicc));
	entry->next = NULL;
	checker(num_and_dicc, entry);
	free_dictionary(entry);
}
