/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   optimize.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 14:15:36 by fpolycar      #+#    #+#                 */
/*   Updated: 2022/02/04 12:06:43 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	direction_a(t_stack *stack, t_direction *direction, int i)
{
	int	nb;
	int	nb_a;

	nb_a = stack->nb_a;
	direction->ins_b = 1;
	nb = nb_a / 2;
	if (i <= nb)
	{
		direction->ins_a = 1;
		direction->nb_ins_a = i;
	}
	else
	{
		direction->ins_a = 2;
		direction->nb_ins_a = nb_a - i;
	}
}

void	direction_b_bis(t_direction *direction, t_stack *stack, int below)
{
	int	nb_b;

	nb_b = stack->nb_b;
	if (below <= nb_b / 2)
	{
		direction->ins_b = 3;
		direction->nb_ins_b = (below);
	}
	else
	{
		direction->ins_b = 4;
		direction->nb_ins_b = (nb_b - below);
	}
}

void	direction_b(t_stack *stack, t_direction *direction, int i)
{
	int	above;
	int	below;
	int	nb_b;

	nb_b = stack->nb_b;
	above = closest_above(stack, stack->stack_a[i]);
	below = closest_below(stack, stack->stack_a[i]);
	if (below == -1 && above != -1)
	{
		if (above >= nb_b / 2)
		{
			direction->ins_b = 4;
			direction->nb_ins_b = (nb_b - 1 - above);
		}
		else
		{
			direction->ins_b = 3;
			direction->nb_ins_b = (above + 1);
		}
	}
	else
	{
		direction_b_bis(direction, stack, below);
	}
}

void	optimize_ins(t_stack *stack, t_direction *direction)
{
	int	i;
	int	nb;
	int	ref;

	i = 0;
	nb = INT_MAX;
	while (i < stack->nb_a)
	{
		direction_a(stack, direction, i);
		direction_b(stack, direction, i);
		if (direction->nb_ins_a + direction->nb_ins_b < nb)
		{
			nb = direction->nb_ins_a + direction->nb_ins_b;
			ref = i;
		}
		i++;
	}
	direction_a(stack, direction, ref);
	direction_b(stack, direction, ref);
	if (direction->nb_ins_a == 0)
		direction->ins_a = 0;
	if (direction->nb_ins_b == 0)
		direction->ins_b = 0;
}
