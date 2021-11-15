#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char		*d;
	const char	*s;
	char		*backd;
	const char	*backs;

	d = (char *)dest;
	s = (const char *)src;
	if (dest == 0 && src == 0)
	{
		return (NULL);
	}
	if (d < s)
	{
		while (size--)
			*d++ = *s++;
	}
	else
	{
		backd = d + (size - 1);
		backs = s + (size - 1);
		while (size--)
			*backd-- = *backs--;
	}	
	return (dest);
}
