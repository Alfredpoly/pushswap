#include "libft.h"

void	*ft_memset(void *str, int c, size_t nb)
{
	unsigned char	*trs;

	trs = (unsigned char *)str;
	while (nb > 0)
	{
		*trs++ = c;
		nb--;
	}
	return (str);
}
