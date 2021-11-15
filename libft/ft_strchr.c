#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	ch;

	ch = c;
	while (*str != ch)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return ((char *)str);
}
