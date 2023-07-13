/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:16:43 by dcerrato          #+#    #+#             */
/*   Updated: 2023/07/13 19:42:32 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils.h"

int		swap(t_stack *stack, char *move);
int		push(t_stack *stack1, t_stack *stack2, char *move);
void	change_stack(t_stack *stack_from, t_stack *stack_to);
void	sort_three(t_stack *stack);
void	sort_stacks(t_stack *stacks);

#endif