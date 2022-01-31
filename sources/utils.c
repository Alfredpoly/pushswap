/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: alfred <alfred@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/13 10:19:40 by alfred        #+#    #+#                 */
/*   Updated: 2022/01/31 13:16:09 by alfred        ########   odam.nl         */
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
