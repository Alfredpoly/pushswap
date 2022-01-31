/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 13:01:40 by fpolycar      #+#    #+#                 */
/*   Updated: 2022/01/31 13:07:04 by alfred        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_stacks(int argc, char **argv, t_stack *stack)
{
	int		**arr_stack;
	int		i;

	i = 0;
	stack->stack_a = ft_calloc(argc, sizeof(int));
	stack->stack_b = ft_calloc(argc, sizeof(int));
	stack->nb_a = argc - 1;
	stack->nb_b = 0;
	while (argv[i + 1])
	{
		stack->stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	arr_stack = index_nb(stack);
	arr_2_stack(arr_stack, stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	make_stacks(argc, argv, stack);
	if (argc <= 6)
		sort_small_stack(argc, stack);
	if (argc >= 7)
		sort_big_stack(stack);
}
