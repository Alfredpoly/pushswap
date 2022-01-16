#include "push_swap.h"

// int	get_last(char *str)
// {
// 	int	i;

// 	while (str != '\0')
// 		i++;
// 	return (i);
// }

// void	swap(char *a, char *b)
// {
// 	char	temp;

// 	temp = *a;
// 	*a = *b;
// 	*b = temp;
// }

// void	s(char *stack, char *name)
// {
// 	if (name)
// 		write(1, name, 2);
// 	swap(&stack[0], &stack[1]);
// }

// void	ss(char **stack)
// {
// 	write(1, "ss", 2);
// 	s(stack[0], NULL);
// 	s(stack[1], NULL);
// }

// void	pa(char **stack)
// {
// 	int	stacklen;

// 	stacklen = ft_strlen(stack[0]);
// 	while (stack[0][0] != 0)
// 	{
// 		swap(stack[0][stacklen], stack[0][stacklen + 1]);
// 		stacklen--;
// 	}
// 	swap(stack[1][0], stack[0][0]);
// 	stacklen = ft_strlen(stack[1]);
// 	while (stack[0][0] != 0)
// 	{
// 		swap(stack[0][stacklen], stack[0][stacklen + 1]);
// 		stacklen--;
// 	}
// }

char	**make_stacks(int argc, char *str)
{
	char	**stack;

	stack = (char **)ft_calloc(2, sizeof(char *));
	stack[0] = str;
	stack[1] = ft_calloc(argc, sizeof(char));
	return (stack);
}

int	main(int argc, char **argv)
{
	char	*a;
	char	**stack;

	a = delete_spaces(argc, argv);
	stack = make_stacks(argc, a);
	if (argc <= 6)
		sort_small_stack(argc, stack);
	// else
	// 	sort_big_stack();
	printf("%s", stack[0]);
}
