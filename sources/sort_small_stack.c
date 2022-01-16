/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small_stack.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: alfred <alfred@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/13 10:30:40 by alfred        #+#    #+#                 */
/*   Updated: 2022/01/14 16:47:08 by alfred        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three(int argc, char **stack)
{
	if (stack[0][0] > stack[0][1])
		sa(stack);
	if (stack[0][1] > stack[0][2])
		rra(argc, stack);
}

void	four(int argc, char **stack)
{
	if (stack[0][0] > stack[0][1] && stack[0][0] - stack[0][1] == 1)
		sa(stack);
	if (stack[0][2] - stack[0][3] > 1)
	{
		rra(argc, stack);
		rra(argc, stack);
	}
}

void	sort_small_stack(int argc, char **stack)
{
	if (argc == 3 && stack[0][0] > stack[0][1])
		sa(stack);
	if (argc == 4)
		while (is_it_sorted(argc, stack) != 1)
			three(argc, stack);
	if (argc == 5)
		// while (is_it_sorted(argc, stack) != 1)
			four(argc, stack);
}
