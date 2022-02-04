/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 13:01:40 by fpolycar      #+#    #+#                 */
/*   Updated: 2022/02/04 13:44:31 by fpolycar      ########   odam.nl         */
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
	return (arr_stack);
}

void	free_everything(int **arr_stack, t_stack *stack)
{
	ps_clear(arr_stack, stack->nb_a);
	free(stack->stack_b);
	free(stack->stack_a);
	free(stack);
}

int	main(int argc, char **argv)
{
	t_stack		*stack;
	t_direction	*direction;
	int			**arr_stack;
	int			i;

	i = 1;
	while (argv[i])
		if (check_digit(argv[i++]) == 1)
			argc = 1;
	if (argc == 1)
		write(1, "Error\n", 6);
	else
	{
		stack = (t_stack *)malloc(sizeof(t_stack));
		arr_stack = make_stacks(argc, argv, stack);
		if (argc <= 6)
			sort_small_stack(argc, stack);
		if (argc >= 7)
		{
			direction = sort_big_stack(stack);
			free(direction);
		}
		free_everything(arr_stack, stack);
	}
}
