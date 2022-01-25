/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_big_stack.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 15:03:53 by fpolycar      #+#    #+#                 */
/*   Updated: 2022/01/25 16:00:46 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>





void	sort_big_stack(t_stack *stack)
{
	
	while (stack->nb_a != 0)
	{
		if (stack->nb_b < 2)
			pb(stack);
		else
		{
		optimize_ins(stack);
	// 		while (stack_a et stack_b sont bien positionne)// fonction pour calculer le nombre min de mouvement retournant leurs valeur a index 0  
	// 		{
	// 			if (stack_a et stack_b vont dans la meme direction -> rr)
	// 			{
					
	// 			}
	// 			if (stack_a et stack_b vont dans la meme direction -> rrr)
	// 			{
					
	// 			}
	// 			if (stack_a va ra) // i
	// 			{
					
	// 			}
	// 			if (stack_a va rra)
	// 			{
					
	// 			}
	// 			if (stack_b va rb)
	// 			{
					
	// 			}
	// 			if (stack_b va rrb)
	// 			{
					
	// 			}
	// 		}
	// 		while (closest_below(stack) != 0
	// 			&& closest_above(stack) != stack->nb_b - 1)
	// 		{
	// 			if (closest_above(stack) < stack->nb_b / 2)
	// 				rb(stack->nb_b, stack);
	// 			else
	// 				rrb(stack->nb_b, stack);
	// 		}
	// 		if (stack->nb_a == 1)
	// 			break ;
	// 		pb(stack);
		}	
	}
	while (stack->nb_b != 0)
		pa(stack);
	// while (is_it_sorted(stack->nb_a, stack->stack_a) != -1)
	// 	ra_or_rra(stack, is_it_sorted(stack->nb_a, stack->stack_a));
}
