/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicerrato2 <danicerrato2@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:17:59 by dcerrato          #+#    #+#             */
/*   Updated: 2023/07/15 18:17:33 by danicerrato      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "ft_stack.h"

int		check_int(char *str);
int		is_in_stack(int num, t_stack *stack);
int		is_in_order(t_stack *stack);
void	convert_numbers(t_stack *stacks[]);
int		free_all(t_stack *stacks[], int errorValue);

#endif