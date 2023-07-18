/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicerrato2 <danicerrato2@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:16:43 by dcerrato          #+#    #+#             */
/*   Updated: 2023/07/18 19:11:49 by danicerrato      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils.h"

int		swap(t_stack *stack, char *move);
int		push(t_stack *stack1, t_stack *stack2, char *move);
void	sort_three(t_stack *stack);
void	move_to_b(t_stack *stacks[], float chunks[]);

//void	change_stack(t_stack *stack_from, t_stack *stack_to);

#endif