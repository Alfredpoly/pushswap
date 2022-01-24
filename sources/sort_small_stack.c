/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small_stack.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: alfred <alfred@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/13 10:30:40 by alfred        #+#    #+#                 */
/*   Updated: 2022/01/20 10:01:05 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three(t_stack *stack)
{
	if (stack->stack_a[0] > stack->stack_a[1]
		&& stack->stack_a[1] < stack->stack_a[2]
		&& stack->stack_a[2] != max_value(stack->stack_a, stack->nb_a))
		ra(stack->nb_a, stack);
	if (stack->stack_a[0] > stack->stack_a[1])
		sa(stack);
	if (stack->stack_a[1] > stack->stack_a[2])
		rra(stack->nb_a, stack);
}

void	four(t_stack *stack)
{
	int initial;

	pb(stack);
	while (is_it_sorted(stack->nb_a, stack->stack_a) != -1)
		three(stack);
	while (between_nb(stack) != 1)
		ra(stack->nb_a, stack);
	pa(stack);
	initial = is_it_sorted(stack->nb_a, stack->stack_a);
	while (is_it_sorted(stack->nb_a, stack->stack_a) != -1)
		ra_or_rra(stack, initial);
}

void	five(t_stack *stack)
{
	int initial;

	pb(stack);
	pb(stack);
	while (is_it_sorted(stack->nb_a, stack->stack_a) != -1)
		three(stack);
	while (between_nb(stack) != 1)
		rra(stack->nb_a, stack);
	pa(stack);
	while (between_nb(stack) != 1)
		ra(stack->nb_a, stack);
	pa(stack);
	initial = is_it_sorted(stack->nb_a, stack->stack_a);
	while (is_it_sorted(stack->nb_a, stack->stack_a) != -1)
		ra_or_rra(stack, initial);
}

void	sort_small_stack(int argc, t_stack *stack)
{
	if (argc == 3 && stack->stack_a[0] > stack->stack_a[1])
		sa(stack);
	if (argc == 4)
		while (is_it_sorted(stack->nb_a, stack->stack_a) != -1)
			three(stack);
	if (argc == 5)
		four(stack);
	if (argc == 6)
		five(stack);
}
