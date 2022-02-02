/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 13:01:40 by fpolycar      #+#    #+#                 */
/*   Updated: 2022/02/02 18:54:21 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_clear(int **arr, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	**make_stacks(int argc, char **argv, t_stack *stack)
{
	int		**arr_stack;
	int		i;

	i = 0;
	stack->stack_a = malloc(argc * sizeof(int));
	stack->stack_b = malloc(argc * sizeof(int));
	stack->nb_a = argc - 1;
	stack->nb_b = 0;
	while (argv[i + 1])
	{
		stack->stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	arr_stack = index_nb(stack);
	arr_2_stack(arr_stack, stack);
	return (arr_stack);
}

int	main(int argc, char **argv)
{
	t_stack		*stack;
	int			**arr_stack;
	t_direction	*direction;

	stack = (t_stack *)malloc(sizeof(t_stack));
	arr_stack = make_stacks(argc, argv, stack);
	if (argc <= 6)
	{
		sort_small_stack(argc, stack);
		ps_clear(arr_stack, stack->nb_a);
		free(stack->stack_b);
		free(stack->stack_a);
		free(stack);
	}
	if (argc >= 7)
	{
		direction = sort_big_stack(stack);
		
		free(stack->stack_b);
		free(stack);		
		ps_clear(arr_stack, stack->nb_a);
		free(direction);
		printf("%p\n\n\n\n\n\n\n\n\n", stack->stack_a);
		free(stack->stack_a);
	}
	// check_leaks();
}
