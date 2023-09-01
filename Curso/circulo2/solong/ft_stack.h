/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:17:48 by dcerrato          #+#    #+#             */
/*   Updated: 2023/09/01 18:54:59 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int	**content;
	int	top;
	int	size;
}	t_stack;

t_stack	*stack_init(int size);
int		stack_push(t_stack *stack, int x, int y);
int		stack_pop(t_stack *stack, int *x, int *y);
void	stack_free(t_stack *stack);

#endif
