#include "push_swap.h"
#include "libft/libft.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	output_swap(t_swap_list *list, int argc)
{
	int			i;
	int			j;

	i = 0;
	while (i != argc - 2)
	{
		j = i;
		while (list[j].nb > list[j + 1].nb
			&& j != argc - 2)
		{
			swap(&list[j].nb, &list[j + 1].nb);
			j++;
			printf("|%d", j);
		}	
		i++;
	}
	printf(" ");
	argc--;
}

t_swap_list	*clone(t_swap_list *list)
{
	t_swap_list	*result;

	if (list == NULL)
		return (NULL);
	result = (t_swap_list *)ft_calloc(4, sizeof(t_swap_list));
	result->nb = list->nb;
	result->next = clone(list->next);
	return (result);
}

void	addLast(t_swap_list **head, int val)
{
	t_swap_list	*newNode;
	t_swap_list	*lastNode;

	newNode = malloc(sizeof(t_swap_list));
	newNode->nb = val;
	newNode->next = NULL;
	if (*head == NULL)
		 *head = newNode;
	else
	{
		lastNode = *head;
		while (lastNode->next != NULL)
			lastNode = lastNode->next;
		lastNode->next = newNode;
	}
}

void	printList(t_swap_list *head)
{
	t_swap_list	*temp;

	temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->nb);
		temp = temp->next;
	}
	printf("\n");
}

int	is_it_in_order(t_swap_list *list, int argc)
{
	int			i;
	t_swap_list	*copy;

	copy = clone(list);
	i = 0;
	while (argc > 1)
	{
		printList(list);
		if (list->nb > list->next->nb)
			return (i);
		list = list->next;
		argc--;
		i++;
	}
	printf("||%d||\n", list->nb);
	return (-1);
}

int	main(int argc, char **argv)
{
	int			i;
	int			digit;
	t_swap_list	*list;

	i = 1;
	while (argv[i] != 0)
	{
		digit = ft_atoi(argv[i]);
		addLast(&list, digit);
		i++;
	}
	i = 0;
	while (is_it_in_order(list, argc) != -1)
	{
		output_swap(list, argc);
		printf("\n");
		i++;
	}
	printList(list);
}
