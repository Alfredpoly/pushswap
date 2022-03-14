/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alfred <alfred@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/31 13:14:46 by alfred        #+#    #+#                 */
/*   Updated: 2022/03/07 13:06:54 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	max_value_2d(int **stack, int nb_stack)
{
	int	max;
	int	i;

	i = 0;
	max = INT_MIN;
	while (i < nb_stack)
	{
		if (stack[i][1] > max)
			max = stack[i][1];
	i++;
	}
	return (max);
}
