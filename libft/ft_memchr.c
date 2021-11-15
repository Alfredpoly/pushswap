#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	ch;

	s = (unsigned char *)str;
	ch = c;
	while ((s && n > 0) || (s == NULL))
	{
		if (*s == ch)
		{
			return ((void *)s);
		}
		s++;
		n--;
	}
	return (NULL);
}
