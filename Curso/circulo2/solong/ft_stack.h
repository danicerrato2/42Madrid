/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:17:48 by dcerrato          #+#    #+#             */
/*   Updated: 2023/08/23 11:45:41 by dcerrato         ###   ########.fr       */
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
