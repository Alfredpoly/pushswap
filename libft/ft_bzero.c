#include "libft.h"

void	ft_bzero(void *dest, size_t len)
{
	size_t	i;

	i = 0;
	while (i <= len - 1 && len != 0)
	{
		*(char *)dest = '\0';
		i++;
		dest++;
	}
}
