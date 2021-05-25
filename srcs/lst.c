#include "pushswap.h"

int	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*lst;

	lst = *alst;
	while (lst && lst->next)
	{
		if (lst->content == new->content)
		{
			free(new);
			return (0);
		}
		lst = lst->next;
	}
	if (lst == NULL)
		*alst = new;
	else
		lst->next = new;
	return (1);
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst != NULL)
		new->next = *alst;
	*alst = new;
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstnew(int content)
{
	struct s_list	*list;

	list = malloc(sizeof(struct s_list));
	if ((void *)list == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
		while (lst->next != NULL)
			lst = lst->next;
	return (lst);
}
