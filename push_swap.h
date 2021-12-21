#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <wchar.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_swap_list
{
	int					nb;
	struct s_swap_list	*next;
} t_swap_list;

#endif