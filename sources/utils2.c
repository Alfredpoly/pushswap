/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alfred <alfred@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/31 13:14:46 by alfred        #+#    #+#                 */
/*   Updated: 2022/03/07 13:06:08 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

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

void	index_nb2(t_stack *stack, int **arr)
{
	int	i;
	int	pos;

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
}

int	**index_nb(t_stack *stack)
{
	int	**arr;
	int	i;

	i = 0;
	arr = (int **)malloc(stack->nb_a * sizeof(int *));
	if (!arr)
		exit(EXIT_FAILURE);
	while (i < stack->nb_a)
	{
		arr[i] = (int *)ft_calloc(2, sizeof(int));
		if (!arr[i])
			exit(EXIT_FAILURE);
		arr[i][0] = stack->stack_a[i];
		i++;
	}
	index_nb2(stack, arr);
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
