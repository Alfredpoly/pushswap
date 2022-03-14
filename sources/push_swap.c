/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 13:01:40 by fpolycar      #+#    #+#                 */
/*   Updated: 2022/03/14 14:34:24 by fpolycar      ########   odam.nl         */
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
	if (!stack->stack_a)
		exit(EXIT_FAILURE);
	stack->stack_b = ft_calloc(argc, sizeof(int));
	if (!stack->stack_b)
		exit(EXIT_FAILURE);
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

void	sort_algo(int argc, char **argv)
{
	t_stack		*stack;
	t_direction	*direction;
	int			**arr_stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		exit(EXIT_FAILURE);
	arr_stack = make_stacks(argc, argv, stack);
	if (argc <= 6)
		sort_small_stack(argc, stack);
	if (argc >= 7 && is_it_sorted(stack->nb_a, stack->stack_a) != -1)
	{
		direction = sort_big_stack(stack);
		free(direction);
	}
	free_everything(arr_stack, stack);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 11
			|| check_digit(argv[i++]) == 1 || check_digit2(argv) == 1)
		{
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
	}
	if (argc != 1)
		sort_algo(argc, argv);
}
