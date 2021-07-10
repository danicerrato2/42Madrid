/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 18:16:32 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/10 18:55:19 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_02_H
#define RUSH_02_H
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*translate_number(int num_size, char *num, char *dic);
void	print_number(char *str);
char	*concat(char *str, char last, int size);
char	*read_line(int fd);



#endif
