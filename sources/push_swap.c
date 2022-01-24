/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 13:01:40 by fpolycar      #+#    #+#                 */
/*   Updated: 2022/01/24 14:00:48 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	make_stacks(int argc, char **argv)
{
	t_stack	stack;
	int	**arr_stack;
	int		i;

	i = 0;
	stack = *(t_stack *)malloc(sizeof(t_stack));
	stack.stack_a = ft_calloc(argc, sizeof(int));
	stack.stack_b = ft_calloc(argc, sizeof(int));
	stack.nb_a = argc - 1;
	stack.nb_b = 0;
	while (argv[i + 1])
	{
		stack.stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	arr_stack = index_nb(&stack);
	arr_2_stack(arr_stack, &stack);
	return (stack);
}

int	main(int argc, char **argv)
{
	// int		i;
	t_stack	stack;

	stack = make_stacks(argc, argv);
	if (argc <= 6)
		sort_small_stack(argc, &stack);
	if (argc >= 7)
		sort_big_stack(&stack);
	// i = 0;
	// while (i < stack.nb_a)
	// 	printf("%d ", stack.stack_a[i++]);
	// printf("	");
	// i = 0;
	// while (i < stack.nb_b)
	// 	printf("%d ", stack.stack_b[i++]);
}
