/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: alfred <alfred@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/13 10:30:40 by alfred        #+#    #+#                 */
/*   Updated: 2022/02/04 11:01:00 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	write(1, "sa\n", 3);
	swap(&stack->stack_a[0], &stack->stack_a[1]);
}

void	sb(t_stack *stack)
{
	write(1, "sb\n", 3);
	swap(&stack->stack_b[0], &stack->stack_b[1]);
}

void	ss(t_stack *stack)
{
	write(1, "ss\n", 3);
	swap(&stack->stack_a[0], &stack->stack_a[1]);
	swap(&stack->stack_b[0], &stack->stack_b[1]);
}

void	pa(t_stack *stack)
{
	int		i;

	write(1, "pa\n", 3);
	i = stack->nb_a;
	while (stack->stack_a[0] != 0)
	{
		swap(&stack->stack_a[i], &stack->stack_a[i - 1]);
		i--;
	}
	stack->stack_a[0] = stack->stack_b[0];
	stack->stack_b[0] = 0;
	i = 0;
	while (i < stack->nb_b)
	{
		swap(&stack->stack_b[i], &stack->stack_b[i + 1]);
		i++;
	}
	stack->nb_a += 1;
	stack->nb_b -= 1;
}

void	pb(t_stack *stack)
{
	int		i;

	write(1, "pb\n", 3);
	i = stack->nb_b;
	while (stack->stack_b[0] != 0)
	{
		swap(&stack->stack_b[i], &stack->stack_b[i - 1]);
		i--;
	}
	stack->stack_b[0] = stack->stack_a[0];
	stack->stack_a[0] = 0;
	i = 0;
	while (i < stack->nb_a)
	{
		swap(&stack->stack_a[i], &stack->stack_a[i + 1]);
		i++;
	}
	stack->nb_b += 1;
	stack->nb_a -= 1;
}
