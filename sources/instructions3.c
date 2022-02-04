/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions3.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alfred <alfred@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/31 12:54:50 by alfred        #+#    #+#                 */
/*   Updated: 2022/02/04 13:49:16 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	rrr(t_stack *stack)
{
	int		i;

	write(1, "rrr\n", 4);
	i = stack->nb_a - 1;
	while (i > 0)
	{
		swap(&stack->stack_a[i], &stack->stack_a[i - 1]);
		i--;
	}
	i = stack->nb_b - 1;
	while (i > 0)
	{
		swap(&stack->stack_b[i], &stack->stack_b[i - 1]);
		i--;
	}
}

int	check_digit(char *nb)
{
	int	i;

	i = 0;
	if (nb[0] == '-')
		i++;
	while (nb[i] != 0)
		if (ft_isdigit(nb[i++]) == 0)
			return (1);
	if (ft_atoi(nb) > INT_MAX)
		return (1);
	return (0);
}
