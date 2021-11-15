#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	ptr = ft_calloc((len + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	while (start < ft_strlen(s) && len > 0)
	{
		ptr[i] = s[start];
		start++;
		len--;
		i++;
	}
	return (ptr);
}
