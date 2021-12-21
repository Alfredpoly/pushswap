#include "push_swap.h"
#include "libft/libft.h"

int	get_last(char *str)
{
	int	i;

	while (str != '\0')
		i++;
	return (i);
}

void	swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	s(char *stack, char *name)
{
	if (name)
		write(1, name, 2);
	swap(&stack[0], &stack[1]);
}

void	ss(char **stack)
{
	write(1, "ss", 2);
	s(stack[0], NULL);
	s(stack[1], NULL);
}

void	pa(char **stack)
{
	int	stacklen;

	stacklen = ft_strlen(stack[0]);
	while (stack[0][0] != 0)
	{
		swap(stack[0][stacklen], stack[0][stacklen + 1]);
		stacklen--;
	}
	swap(stack[1][0], stack[0][0]);
	stacklen = ft_strlen(stack[1]);
	while (stack[0][0] != 0)
	{
		swap(stack[0][stacklen], stack[0][stacklen + 1]);
		stacklen--;
	}
}

char	**make_stacks(int argc, char *str)
{
	char	*stack[2];

	stack[0] = str;
	stack[1] = ft_calloc(argc, sizeof(char));
	instruction(stack);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*b;

	i = 1;
	b = ft_calloc(argc, sizeof(char));
	while (argv[i] != NULL)
	{
		if (!argv[i])
			return (0);
		b[i - 1] = *argv[i];
		i++;
	}
	make_stacks(argc, b);
	printf("%s", b);
}
