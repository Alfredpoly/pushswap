#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	ch;
	char	first;

	ch = c;
	first = *str;
	while (*str != '\0')
		str++;
	while (*str != ch)
	{
		if (*str == first)
			return (NULL);
		str--;
	}
	return ((char *)str);
}
