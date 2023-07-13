/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:17:59 by dcerrato          #+#    #+#             */
/*   Updated: 2023/07/13 17:42:33 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft/libft.h"
# include "ft_stack.h"

int		check_int(char *str);
int		is_in_stack(int num, t_stack *stack);
int		is_in_order(t_stack *stack);
void	get_minmax_values(t_stack *stack, int *min_value, int *max_value);
int		free_all(t_stack *stacks[], int errorValue);

#endif