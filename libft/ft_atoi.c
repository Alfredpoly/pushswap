#include "libft.h"

int	ft_atoi(const char *str)
{
	int	nb;
	int	sign;

	nb = 0;
	while (*str == '\t' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == '\n' || *str == 32 )
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else
	{
		sign = 1;
		if (*str == '+')
			str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (nb * sign);
}
