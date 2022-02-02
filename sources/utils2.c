/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alfred <alfred@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/31 13:14:46 by alfred        #+#    #+#                 */
/*   Updated: 2022/02/02 17:40:11 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	max_value_2d(int **stack, int nb_stack)
{
	int	max;
	int	i;

	i = 0;
	max = INT_MIN;
	while (i < nb_stack)
	{
		if (stack[i][1] > max)
			max = stack[i][1];
	i++;
	}
	return (max);
}

int	between_nb(t_stack *stack)
{
	if (stack->stack_b[0] < stack->stack_a[0] 
		&& stack->stack_b[0] > stack->stack_a[stack->nb_a - 1])
		return (1);
	if (max_value(stack->stack_a, stack->nb_a) < stack->stack_b[0]
		&& max_value(stack->stack_a, stack->nb_a)
		== stack->stack_a[stack->nb_a - 1])
		return (1);
	if (min_value(stack->stack_a, stack->nb_a) > stack->stack_b[0]
		&& min_value(stack->stack_a, stack->nb_a) == stack->stack_a[0])
		return (1);
	return (0);
}

void	ra_or_rra(t_stack *stack, int initial)
{
	if (stack->nb_a - initial <= stack->nb_a / 2)
		rra(stack->nb_a, stack);
	else
		ra(stack->nb_a, stack);
}

int	**index_nb(t_stack *stack)
{
	int	**arr;
	int	i;
	int	pos;

	i = 0;
	arr = (int **)malloc(stack->nb_a * sizeof(int *));
	while (i < stack->nb_a)
	{
		arr[i] = (int *)ft_calloc(2, sizeof(int));
		arr[i][0] = stack->stack_a[i];
		i++;
	}
	i = 0;
	pos = 1;
	while (max_value_2d(arr, stack->nb_a) != stack->nb_a)
	{
		if (min_value_2d(arr, stack->nb_a) == arr[i][0])
			arr[i][1] = pos++;
		i++;
		if (i == stack->nb_a)
			i = 0;
	}
	return (arr);
}

void	arr_2_stack(int **arr, t_stack *stack)
{	
	int	i;

	i = 0;
	while (i < stack->nb_a)
	{
		stack->stack_a[i] = arr[i][1];
		i++;
	}
}
