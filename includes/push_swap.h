/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 13:54:35 by fpolycar      #+#    #+#                 */
/*   Updated: 2022/02/04 13:58:20 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <wchar.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	nb_a;
	int	nb_b;
}		t_stack;

typedef struct s_direction
{
	int	nb_ins_a;
	int	ins_a;
	int	nb_ins_b;
	int	ins_b;
}		t_direction;

int			*delete_spaces(int argc, char **arg);
void		sa(t_stack *stack);
void		rra(int argc, t_stack *stack);
void		ra(int argc, t_stack *stack);
void		rr(t_stack *stack);
void		rrr(t_stack *stack);
void		pb(t_stack *stack);
void		pa(t_stack *stack);
void		swap(int *a, int *b);
void		sort_small_stack(int argc, t_stack *stack);
int			is_it_sorted(int nb, int *stack);
int			between_nb(t_stack *stack);
int			max_value(int *stack, int nb_stack);
int			min_value(int *stack, int nb_stack);
void		ra_or_rra(t_stack *stack, int initial);
t_direction	*sort_big_stack(t_stack *stack);
void		rb(int argc, t_stack *stack);
void		rrb(int argc, t_stack *stack);
int			**index_nb(t_stack *stack);
int			min_value_2d(int **stack, int nb_stack);
int			max_value_2d(int **stack, int nb_stack);
void		arr_2_stack(int **arr, t_stack *stack);
void		optimize_ins(t_stack *stack, t_direction *direction);
int			closest_above(t_stack *stack, int a);
int			closest_below(t_stack *stack, int a);
int			check_digit(char *nb);

#endif