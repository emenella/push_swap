#include "pushswap.h"

int	ft_cmdsize(t_cmd *lst)
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

t_cmd	*ft_cmdnew(char *content)
{
	 t_cmd	*list;

	list = malloc(sizeof(t_cmd));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

t_cmd	*ft_cmdlast(t_cmd *lst)
{
	if (lst)
		while (lst->next != NULL)
			lst = lst->next;
	return (lst);
}

void	ft_cmdfree(t_cmd *lst)
{
	t_cmd	*tmp;

	while (lst != NULL)
	{
		tmp = lst->next;
		free(lst->content);
		free(lst);
		lst = NULL;
		lst = tmp;
	}
}

void	ft_cmdadd_back(t_cmd **alst, t_cmd *new)
{
	t_cmd	*lstlast;

	lstlast = ft_cmdlast(*alst);
	if (lstlast == NULL)
		*alst = new;
	else
		lstlast->next = new;
}
