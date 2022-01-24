/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_big_stack.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 15:03:53 by fpolycar      #+#    #+#                 */
/*   Updated: 2022/01/20 13:12:47 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	between_nb_b(t_stack *stack)
{
	printf("nb = %d\n", stack->nb_a - 1);
	if (stack->nb_a == 1)
	{
		if (stack->stack_a[0] > stack->stack_b[0] 
			&& stack->stack_a[0] < stack->stack_b[stack->nb_b - 1])
			return (1);
		return (0);
	}
	else
	{
		if (stack->stack_a[0] > stack->stack_b[0] 
			&& stack->stack_a[0] < stack->stack_b[stack->nb_b - 1])
		return (1);
		if (max_value(stack->stack_b, stack->nb_b) > stack->stack_a[stack->nb_a - 1]
			&& max_value(stack->stack_b, stack->nb_b)
			== stack->stack_b[0])
			return (1);
		if (min_value(stack->stack_b, stack->nb_b) < stack->stack_a[stack->nb_a - 1]
			&& min_value(stack->stack_b, stack->nb_b) == stack->stack_b[stack->nb_b - 1])
			return (1);
		return (0);
	}
	return (-1);
}

// void pb_if_bigger(t_stack *stack)
// {
	
// }

void	sort_big_stack(t_stack *stack)
{
	int i = 0;
	while (stack->nb_a != 0)
	{
		if (stack->nb_b < 1)
			pb(stack);
		else
		{
			printf("-------------------------------------------\n");
			i = 0;
			while (i < stack->nb_a)
					printf("%d ", stack->stack_a[i++]);
			printf("	");
			i = 0;
			while (i < stack->nb_b)
				printf("%d ", stack->stack_b[i++]);
			printf("\n");
			printf("between: %d\n", between_nb_b(stack));
			while (between_nb_b(stack) != 1)
			{
				rb(stack->nb_b, stack);
				printf("between: %d\n", between_nb_b(stack));
			}
			pb(stack);
			i = 0;
			while (i < stack->nb_a)
					printf("%d ", stack->stack_a[i++]);
			printf("	");
			i = 0;
			while (i < stack->nb_b)
				printf("%d ", stack->stack_b[i++]);
			printf("\n\n");
			printf("-------------------------------------------\n");
		}	
	}
	while (stack->nb_b != 0)
		pa(stack);
	// while (is_it_sorted(stack->nb_a, stack->stack_a) != -1)
	// 	ra(stack->nb_a, stack);
}