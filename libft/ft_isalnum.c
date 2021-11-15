int	ft_isalnum(int c)
{
	if (((060 <= c) && (c <= 071)) || ((65 <= c)
			&& (c <= 90)) || ((97 <= c) && (c <= 122)))
		return (1);
	else
		return (0);
}
