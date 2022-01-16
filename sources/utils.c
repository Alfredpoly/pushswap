/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: alfred <alfred@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/13 10:19:40 by alfred        #+#    #+#                 */
/*   Updated: 2022/01/13 13:41:19 by alfred        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_it_sorted(int argc, char **stack)
{
	int	i;

	i = 0;
	while (i < argc - 2)
	{
		if (stack[0][i] > stack[0][i + 1])
			return (0);
		i++;
	}
	return (1);
}

char	*delete_spaces(int argc, char **arg)
{
	char	*no_spaces;
	int		i;

	i = 1;
	no_spaces = ft_calloc(argc, sizeof(char));
	while (arg[i] != NULL)
	{
		if (!arg[i])
			return (0);
		no_spaces[i - 1] = *arg[i];
		i++;
	}
	return (no_spaces);
}

void	swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
