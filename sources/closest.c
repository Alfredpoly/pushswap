/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   closest.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: alfred <alfred@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/31 13:03:46 by alfred        #+#    #+#                 */
/*   Updated: 2022/01/31 13:03:52 by alfred        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	closest_above(t_stack *stack, int a)
{
	int	b;
	int	i;
	int	result;

	i = 0;
	b = INT_MAX;
	result = -1;
	while (i < stack->nb_b)
	{
		if (a - stack->stack_b[i] < b && a - stack->stack_b[i] > 0
			&& stack->stack_b[i] > a)
		{
			b = a - stack->stack_b[i];
			result = i;
		}
		else if (stack->stack_b[i] - a < b && stack->stack_b[i] - a > 0
			&& stack->stack_b[i] > a)
		{
			b = stack->stack_b[i] - a;
			result = i;
		}
		i++;
	}
	return (result);
}

int	closest_below(t_stack *stack, int a)
{
	int	b;
	int	i;
	int	result;

	i = 0;
	b = INT_MAX;
	result = -1;
	while (i < stack->nb_b)
	{
		if (a - stack->stack_b[i] < b && a - stack->stack_b[i] > 0
			&& stack->stack_b[i] < a)
		{
			b = a - stack->stack_b[i];
			result = i;
		}
		else if (stack->stack_b[i] - a < b && stack->stack_b[i] - a > 0
			&& stack->stack_b[i] < a)
		{
			b = stack->stack_b[i] - a;
			result = i;
		}
		i++;
	}
	return (result);
}
