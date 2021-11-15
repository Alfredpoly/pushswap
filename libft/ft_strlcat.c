#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	char		*s;
	size_t		n;
	size_t		dlen;
	size_t		slen;

	d = (char *)dst;
	s = (char *)src;
	n = size;
	slen = ft_strlen(src);
	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + slen);
	while (*s != '\0' && n)
	{
		if (n-- != 1)
			*d++ = *s;
		s++;
	}
	*d = '\0';
	return (dlen + slen);
}
