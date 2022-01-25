/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   optimize.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 14:15:36 by fpolycar      #+#    #+#                 */
/*   Updated: 2022/01/25 16:03:00 by fpolycar      ########   odam.nl         */
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

int	direction_a(t_stack *stack, t_direction *direction, int i)
{
	int nb;
	
	direction->ins_b = 1;
	if (stack->nb_a % 2 != 0)
		nb = stack->nb_a / 2 + 1;
	else
		nb = stack->nb_a / 2;
	if (i <= nb)
		return (i);
	else 
		return (stack->nb_a - i + 1);
}

int	direction_b(t_stack *stack, t_direction *direction, int i)
{
	direction->ins_b = 1;
	printf("%d ", closest_above(stack, stack->stack_a[i]));
	printf("%d \n", closest_below(stack, stack->stack_a[i]));
	
	return (0);
}

t_direction optimize_ins(t_stack *stack)
{
	t_direction	*direction;
	int			i;

	i = 0;
	direction = malloc(sizeof(t_direction));
	while (i <= stack->nb_a)
	{
		printf("%d\n", direction_a(stack, direction, i));
		direction_b(stack, direction, i);
		i++;
	}
	return (*direction);
}