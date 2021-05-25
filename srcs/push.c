#include "pushswap.h"

void	push(t_slack *dest, t_slack *src)
{
	t_list	*lst;

	if (src->size > 0)
	{
		lst = ft_lstnew(src->lst->content);
		ft_lstadd_front(&dest->lst, lst);
		ft_lstfree(src->lst, &src->lst);
		dest->size++;
		src->size--;
	}
}

void	pa(t_slack *a, t_slack *b)
{
	write(1, "pa\n", 3);
	push(a, b);
}

void	pb(t_slack *a, t_slack *b)
{
	write(1, "pb\n", 3);
	push(b, a);
}

void	push_min_to_b(t_slack *a)
{
	t_list	*lst;
	int		min;
	int		i;

	min = INT_MAX;
	i = 0;
	lst = a->lst;
	while (lst)
	{
		if (min > lst->content)
			min = lst->content;
		lst = lst->next;
	}
	lst = a->lst;
	while (lst && lst->content != min)
	{
		lst = lst->next;
		i++;
	}
	if (i <= a->size / 2)
		while (a->lst->content != min)
			ra(a);
	else
		while (a->lst->content != min)
			rra(a);
}

void	push_max_to_b(t_slack *a)
{
	t_list	*lst;
	int		max;
	int		i;

	max = INT_MIN;
	i = 0;
	lst = a->lst;
	while (lst)
	{
		if (max < lst->content)
			max = lst->content;
		lst = lst->next;
	}
	lst = a->lst;
	while (lst && lst->content != max)
	{
		lst = lst->next;
		i++;
	}
	if (i <= a->size / 2)
		while (a->lst->content != max)
			ra(a);
	else
		while (a->lst->content != max)
			rra(a);
}
