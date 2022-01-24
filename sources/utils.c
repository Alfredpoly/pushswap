/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: alfred <alfred@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/13 10:19:40 by alfred        #+#    #+#                 */
/*   Updated: 2022/01/24 14:00:30 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	is_it_sorted(int nb, int *stack)
{
	int	i;

	i = 0;
	while (i < nb -1)
	{
		if (stack[i] > stack[i + 1])
			return (i);
		i++;
	}
	return (-1);
}

int	*delete_spaces(int argc, char **arg)
{
	int	*no_spaces;
	int	i;

	i = 1;
	no_spaces = ft_calloc(argc, sizeof(int));
	while (arg[i] != NULL)
	{
		if (!arg[i])
			return (0);
		no_spaces[i - 1] = ft_atoi(arg[i]);
		i++;
	}
	return (no_spaces);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	max_value(int *stack, int nb_stack)
{
	int	max;
	int	i;

	i = 0;
	max = INT_MIN;
	while (i < nb_stack)
	{
		if (stack[i] > max)
			max = stack[i];
	i++;
	}
	return (max);
}

int	min_value(int *stack, int nb_stack)
{
	int	min;
	int	i;

	i = 0;
	min = INT_MAX;
	while (i < nb_stack)
	{
		if (stack[i] < min)
			min = stack[i];
	i++;
	}
	return (min);
}

int	min_value_2d(int **stack, int nb_stack)
{
	int	min;
	int	i;

	i = 0;
	min = INT_MAX;
	while (i < nb_stack)
	{
		if (stack[i][0] < min && stack[i][1] == 0)
			min = stack[i][0];
		i++;
	}
	return (min);
}

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
	int **arr;
	int	i;
	int pos;

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

void arr_2_stack(int **arr, t_stack *stack)
{	
	int i;

	i = 0;
	while (i < stack->nb_a)
	{
		stack->stack_a[i] = arr[i][1];
		i++;
	}
}
