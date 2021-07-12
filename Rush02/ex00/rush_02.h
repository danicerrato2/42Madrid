/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 18:16:32 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/11 22:43:07 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_02_H
# define RUSH_02_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

struct s_dicc
{
	char			*number_and_word[2];
	struct s_dicc	*next;
};

char	*translate_number(int num_size, char *num, struct s_dicc *dic);
void	print_number(char *str);
char	*read_line(int fd);
char	*safe_number(char *line, int *i);
char	*safe_word(char *line, int *i);
int		check_number(char *str, int	*num_size);
char	*concat_strs(char *s1, char *s2);
char	*search_in_dic(struct s_dicc *entry, char digit);
char	*search_units(struct s_dicc *entry, char *num, int large);
char	*search_pair(struct s_dicc *entry, char *num);
char	*search_dec(struct s_dicc *entry, char num);

#endif
