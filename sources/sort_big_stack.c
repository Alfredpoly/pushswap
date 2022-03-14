/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_big_stack.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 15:03:53 by fpolycar      #+#    #+#                 */
/*   Updated: 2022/03/14 14:34:37 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	instructions_model(t_direction *direction, t_stack *stack)
{
	if (direction->ins_a == 1 && direction->ins_b == 3)
		rr(stack);
	optimize_ins(stack, direction);
	if (direction->ins_a == 2 && direction->ins_b == 4)
		rrr(stack);
	optimize_ins(stack, direction);
	if (direction->ins_a == 1)
		ra(stack->nb_a, stack);
	optimize_ins(stack, direction);
	if (direction->ins_a == 2)
		rra(stack->nb_a, stack);
	optimize_ins(stack, direction);
	if (direction->ins_b == 3)
		rb(stack->nb_b, stack);
	optimize_ins(stack, direction);
	if (direction->ins_b == 4)
		rrb(stack->nb_b, stack);
	optimize_ins(stack, direction);
}

t_direction	*sort_big_stack(t_stack *stack)
{
	t_direction	*direction;

	direction = (t_direction *)malloc(sizeof(t_direction));
	if (!direction)
		exit(EXIT_FAILURE);
	while (stack->nb_a != 0)
	{
		if (stack->nb_b < 2)
			pb(stack);
		else
		{
			optimize_ins(stack, direction);
			while (direction->nb_ins_a != 0 || direction->nb_ins_b != 0)
				instructions_model(direction, stack);
			if (stack->nb_a == 1)
				break ;
			pb(stack);
		}
	}
	while (stack->nb_b != 0)
		pa(stack);
	while (is_it_sorted(stack->nb_a, stack->stack_a) != -1)
		ra_or_rra(stack, is_it_sorted(stack->nb_a, stack->stack_a));
	return (direction);
}
