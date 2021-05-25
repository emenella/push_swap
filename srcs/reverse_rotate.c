#include "pushswap.h"

void	reverse_rotate(t_slack *slack)
{
	t_list	*last;
	t_list	*lst;

	if (slack->size > 0)
	{
		lst = slack->lst;
		last = ft_lstlast(slack->lst);
		while (lst)
		{
			if (lst->next == last)
				break ;
			lst = lst->next;
		}
		lst->next = NULL;
		last->next = slack->lst;
		slack->lst = last;
	}
}

void	reverse_rotate_a_b(t_slack *a, t_slack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

void	rra(t_slack *a)
{
	write(1, "rra\n", 4);
	reverse_rotate(a);
}

void	rrb(t_slack *b)
{
	write(1, "rrb\n", 4);
	reverse_rotate(b);
}

void	rrr(t_slack *a, t_slack *b)
{
	write(1, "rrr\n", 4);
	reverse_rotate(a);
	reverse_rotate(b);
}
