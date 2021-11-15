#include "libft.h"

int	intlen(int n)
{
	int	count;

	count = 0;
	if (n < 0)
		count++;
	if (n == 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		count;

	count = intlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ptr = malloc((count + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	if (n < 0)
	{
		n = n * -1;
		ptr[0] = '-';
	}
	else
		ptr[0] = '0';
	ptr[count] = '\0';
	while (n > 0)
	{
		ptr[count - 1] = (n % 10) + '0';
		n = n / 10;
		count--;
	}
	return (ptr);
}
