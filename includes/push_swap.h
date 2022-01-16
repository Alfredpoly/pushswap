#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <wchar.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_swap_list
{
	int					nb;
	struct s_swap_list	*next;
} t_swap_list;

char	*delete_spaces(int argc, char **arg);
void	sa(char **stack);
void	rra(int argc, char **stack);
void	swap(char *a, char *b);
void	sort_small_stack(int argc, char **stack);
int		is_it_sorted(int argc, char **stack);

#endif