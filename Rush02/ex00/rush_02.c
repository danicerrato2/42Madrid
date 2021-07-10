/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 10:40:08 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/10 18:55:34 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char	*translate_number(int num_size, char *num, char *dic);
void	print_number(char *str);
char	*concat(char *str, char last, int size);
char	*read_line(int fd);

char	*safe_word(char *line)
{
	int		i;
	char	*word;

	i = 0;
	word = NULL;
	while (line[i] != '\0')
	{
		if (line[i] < 32 || line[i] == 127)
			return (NULL);
		if (line[i] != ' ' || line[i - 1] != ' ')
		{
			size++;
			concat(word, line[i], size);
		}
		i++;
	}
	return (word);
}

int	check_line(char	*line, t_dicc *entry)
{
	int				i;
	unsigned int	num;
	char			*word;

	i = 0;
	num = 0;
	while (line[i] >= '0' && line[i] <= '9')
	{
		num = num * 10 + line[i] - '0';
		i++;
	}
	if (i == 0)
		return (-1);
	while (line[i] == ' ')
		i++;
	if (line[i++] != ':')
		return (-1);
	while (line[i] == ' ')
		i++;
	word = safe_word(&line[i]);
	if (word == NULL)
		return (-1);
	entry = malloc(sizeof(t_dicc));
	entry->number = num;
	entry->word = word;
	return (0);
}

int	check_dictionary(char *dic)
{
	int		fd;
	char	*line;
	int		num;
	t_dicc	*entry;

	fd = open(dic, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = read_line(fd, entry);
	while (line != NULL)
	{	
		line = read_line(fd, entry->next);
	}
	close(fd);
	return (-1);
}

int	check_number(char *str)
{
	int			i;
	long long	number;

	if (str == NULL)
		return (-1);
	i = 0;
	number = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		number = number * 10 + str[i] - '0';
		if (number > 4294967295)
			return (-1);
		i++;
	}
	return (i);
}

int	main(int argc, char *args[])
{
	int		num_size;
	char	*number;
	char	*dicc;

	number = NULL;
	if (argc == 2)
	{
		number = args[1];
		dicc = "numbers.dict";
	}
	else if (argc == 3)
	{
		dicc = args[1];
		number = args[2];
	}
	num_size = check_number(number);
	if (num_size == -1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (check_dictionary(dicc) != -1)
		print_number(translate_number(num_size, number, dicc));
	else
		write (1, "Dict Error\n", 11);
}
