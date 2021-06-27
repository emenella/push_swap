/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:34:15 by emenella          #+#    #+#             */
/*   Updated: 2021/06/27 01:44:56 by emenella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_3(t_slack *a)
{
	int	e[3];

	e[0] = a->lst->content;
	e[1] = a->lst->next->content;
	e[2] = a->lst->next->next->content;
	if (e[0] > e[1] && e[1] < e[2] && e[2] > e[0])
		sa(a);
	if (e[0] > e[1] && e[1] > e[2] && e[2] < e[0])
	{
		sa(a);
		rra(a);
	}
	if (e[0] > e[1] && e[1] < e[2] && e[2] < e[0])
		ra(a);
	if (e[0] < e[1] && e[1]
		> e[2] && e[2] > e[0])
	{
		sa(a);
		ra(a);
	}
	if (e[0] < e[1] && e[1] > e[2] && e[2] < e[0])
		rra(a);
}

void	sort_5(t_slack *a, t_slack *b)
{
	if (a->size == 5)
	{
		push_min_to_b(a);
		pb(a, b);
		push_max_to_b(a);
		pb(a, b);
		sort_3(a);
		pa(a, b);
		ra(a);
		pa(a, b);
	}
	if (a->size == 4)
	{
		push_min_to_b(a);
		pb(a, b);
		sort_3(a);
		pa(a, b);
	}
}

int	push_chunk(int chunk, int size, t_slack *a, t_slack *b)
{
	t_list	*lst;
	int		element;
	int		intervall[2];

	lst = a->lst;
	intervall[0] = ft_min(a) + (size * chunk);
	intervall[1] = intervall[0] + size;
	element = 0;
	while (lst)
	{
		if (lst->content >= intervall[0] && lst->content < intervall[1])
		{
			element = lst->content;
			break ;
		}
		lst = lst->next;
	}
	if (lst == NULL)
		return (0);
	while (a->lst->content != element)
		ra(a);
	pb(a, b);
	return (1);
}

void	sort_100(t_slack *a, t_slack *b)
{
	int	i;
	int	ret;
	int	size;

	i = -1;
	size = a->size / 5;
	while (++i < 5)
	{
		ret = 1;
		while (ret)
			ret = push_chunk(i, size, a, b);
	}
	while (b->size)
	{
		push_max_to_a(b);
		pa(a, b);
	}
}

void	sort_500(t_slack *a, t_slack *b)
{
	int	i;
	int	ret;
	int	size;

	i = -1;
	size = a->size / 10;
	while (++i < 10)
	{
		ret = 1;
		while (ret)
			ret = push_chunk(i, size, a, b);
	}
	while (b->size)
	{
		push_max_to_a(b);
		pa(a, b);
	}
}
