#include "pushswap.h"

void	swap(t_slack *slack)
{
	if (slack->size >= 2)
		ft_swap(&slack->lst->content, &slack->lst->next->content);
}

void	swap_a_b(t_slack *a, t_slack *b)
{
	swap(a);
	swap(b);
}

void	sa(t_slack *a)
{
	write(1, "sa\n", 3);
	swap(a);
}

void	sb(t_slack *b)
{
	write(1, "sb\n", 3);
	swap(b);
}

void	ss(t_slack *a, t_slack *b)
{
	write(1, "ss\n", 3);
	swap(a);
	swap(b);
}
