#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	void	*data;
	void	*element;

	ret = 0;
	while (lst)
	{
		data = f(lst->content);
		element = ft_lstnew(data);
		if (!element)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, element);
		lst = lst->next;
	}
	return (ret);
}
