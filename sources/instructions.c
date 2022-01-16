/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: alfred <alfred@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/13 10:30:40 by alfred        #+#    #+#                 */
/*   Updated: 2022/01/14 16:20:41 by alfred        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(char **stack)
{
	write(1, "sa\n", 3);
	swap(&stack[0][0], &stack[0][1]);
}

void	rra(int argc, char **stack)
{
	int		i;

	write(1, "rra\n", 4);
	i = argc - 2;
	while (i > 0)
	{
		swap(&stack[0][i], &stack[0][i - 1]);
		i--;
	}
}

void	pa(int argc, char **stack)
{
	int		i;

	write(1, "pa\n", 3);
	i = argc - 2;
	while (i > 0)
	{
		swap(&stack[1][i], &stack[1][i - 1]);
		i--;
	}
	stack[1][0] = stack[0][0];
}
