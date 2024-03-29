/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:16:43 by dcerrato          #+#    #+#             */
/*   Updated: 2023/07/20 17:33:15 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils.h"

int		swap(t_stack *stack, char *move);
int		push(t_stack *stack1, t_stack *stack2, char *move);
void	rotate_stacks(t_stack *stacks[], int up_or_down);
int		binary_search(t_stack *stack, int value);
void	do_moves_to_a(t_stack *stacks[], int move_code, int moves, int rras);

#endif