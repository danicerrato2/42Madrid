/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicerrato2 <danicerrato2@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:17:48 by dcerrato          #+#    #+#             */
/*   Updated: 2023/07/15 18:17:57 by danicerrato      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int	*content;
	int	top;
	int	size;
}	t_stack;

t_stack	*stack_init(int size);
int		stack_push(t_stack *stack, int num);
int		stack_pop(t_stack *stack, int *num);
int		stack_rotate(t_stack *stack, int upOrDown);
void	stack_free(t_stack *stack);

#endif
