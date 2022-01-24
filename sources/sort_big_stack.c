/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_big_stack.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 15:03:53 by fpolycar      #+#    #+#                 */
/*   Updated: 2022/01/24 14:29:39 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	closest_above(t_stack *stack)
{
	int	a;
	int	b;
	int	i;
	int	result;

	i = 0;
	a = stack->stack_a[0];
	b = INT_MAX;
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

int	closest_below(t_stack *stack)
{
	int	a;
	int	b;
	int	i;
	int	result;

	i = 0;
	a = stack->stack_a[0];
	b = INT_MAX;
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

void	sort_big_stack(t_stack *stack)
{
	int i = 0;
	while (stack->nb_a != 0)
	{
		if (stack->nb_b < 2)
			pb(stack);
		else
		{
			while (closest_below(stack) != 0
				&& closest_above(stack) != stack->nb_b - 1)
			{
				if (closest_above(stack) < stack->nb_b / 2)
					rb(stack->nb_b, stack);
				else
					rrb(stack->nb_b, stack);
			}
				i = 0;
			while (i < stack->nb_a)
				printf("%d ", stack->stack_a[i++]);
			printf("	");
			i = 0;
			while (i < stack->nb_b)
				printf("%d ", stack->stack_b[i++]);
			printf("\n\n");
			pb(stack);
		}	
	}
	while (stack->nb_b != 0)
		pa(stack);
	while (is_it_sorted(stack->nb_a, stack->stack_a) != -1)
		ra_or_rra(stack, is_it_sorted(stack->nb_a, stack->stack_a));
}
