#include "push_swap.h"
#include "libft/libft.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// int	output_len(t_swap_list *list, int argc)
// {
// 	int			i;
// 	int			j;
// 	int			data_i;
// 	t_swap_list	*count;

// 	count = list;
// 	i = 0;
// 	data_i = 0;
// 	while (argc > 1)
// 	{
// 		i = 0;
// 		while (count[i].nb > 0)
// 		{
// 			j = i;
// 			while (count[j].nb > count[j + 1].nb
// 				&& count[j + 1].nb != 0)
// 			{
// 				swap(&count[j].nb, &count[j + 1].nb);
// 				j++;
// 				data_i++;
// 			}
// 			i++;
// 		}
// 		argc--;
// 	}
// 	printf("|%d|", data_i);
// 	return (data_i);
// }

void	output_swap(t_swap_list *list, int argc)
{
	int			i;
	int			j;

	i = 0;
	while (argc > 1)
	{
		i = 0;
		while (list[i].nb > 0)
		{
			j = i;
			while (list[j].nb > list[j + 1].nb
				&& list[j + 1].nb != 0)
			{
				swap(&list[j].nb, &list[j + 1].nb);
				j++;
				printf("%d|", j);
			}
			printf(" ");
			i++;
		}
		argc--;
	}
}

int	main(int argc, char **argv)
{
	int			i;
	int			digit;
	t_swap_list	*list;

	i = 1;
	list = ft_calloc(argc, sizeof(t_swap_list));
	while (argv[i] != 0)
	{
		digit = ft_atoi(argv[i]);
		list[i - 1].nb = digit;
		i++;
	}
	i = 0;	
	printf("original number = ");
	while (list[i].nb)
	{
		printf("%d ", list[i].nb);
		i++;
	}
	printf(" where did the swap happen = ");
	output_swap(list, argc);
	i = 0;
	printf(" final output = ");
	while (list[i].nb)
	{
		printf("%d ", list[i].nb);
		i++;
	}
}
