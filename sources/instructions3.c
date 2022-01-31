/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions3.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alfred <alfred@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/31 12:54:50 by alfred        #+#    #+#                 */
/*   Updated: 2022/01/31 12:55:12 by alfred        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *stack)
{
	int		i;

	write(1, "rrr\n", 4);
	i = stack->nb_a - 1;
	while (i > 0)
	{
		swap(&stack->stack_a[i], &stack->stack_a[i - 1]);
		i--;
	}
	i = stack->nb_b - 1;
	while (i > 0)
	{
		swap(&stack->stack_b[i], &stack->stack_b[i - 1]);
		i--;
	}
}
