/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:59:42 by fpolycar      #+#    #+#                 */
/*   Updated: 2022/01/19 14:59:04 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(int argc, t_stack *stack)
{
	int		i;

	write(1, "ra\n", 3);
	i = 0;
	while (i < argc - 1)
	{
		swap(&stack->stack_a[i], &stack->stack_a[i + 1]);
		i++;
	}
}

void	rra(int argc, t_stack *stack)
{
	int		i;

	write(1, "rra\n", 4);
	i = argc - 1;
	while (i > 0)
	{
		swap(&stack->stack_a[i], &stack->stack_a[i - 1]);
		i--;
	}
}

void	rb(int argc, t_stack *stack)
{
	int		i;

	write(1, "rb\n", 3);
	i = 0;
	while (i < argc - 1)
	{
		swap(&stack->stack_b[i], &stack->stack_b[i + 1]);
		i++;
	}
}

void	rrb(int argc, t_stack *stack)
{
	int		i;

	write(1, "rrb\n", 4);
	i = argc - 1;
	while (i > 0)
	{
		swap(&stack->stack_b[i], &stack->stack_b[i - 1]);
		i--;
	}
}
