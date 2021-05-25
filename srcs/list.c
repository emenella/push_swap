/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:31:23 by emenella          #+#    #+#             */
/*   Updated: 2021/05/25 18:31:25 by emenella         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_lstfree(t_list *lst, t_list **alst)
{
	t_list	*tmp;

	tmp = *alst;
	while (tmp && tmp != lst)
	{
		if (tmp->next == lst)
			tmp->next = lst->next;
		tmp = tmp->next;
	}
	if (lst == *alst)
		*alst = lst->next;
	free(lst);
	lst = NULL;
}

void	ft_listfree(t_list *lst)
{
	t_list	*tmp;

	while (lst != NULL)
	{
		tmp = lst->next;
		free(lst);
		lst = NULL;
		lst = tmp;
	}
}

int	ft_cmd_to_operation(char *cmd)
{
	char	*operation[11];
	int		i;

	operation[0] = "sa";
	operation[1] = "sb";
	operation[2] = "ss";
	operation[3] = "pa";
	operation[4] = "pb";
	operation[5] = "ra";
	operation[6] = "rb";
	operation[7] = "rr";
	operation[8] = "rra";
	operation[9] = "rrb";
	operation[10] = "rrr";
	i = -1;
	while (++i < 11)
		if (ft_strncmp(cmd, operation[i], ft_strlen(cmd)) == 0)
			return (i);
	return (-1);
}

void	ft_swap(int *a, int *b)
{
	if (a != b)
	{
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	}
}

void	push_max_to_a(t_slack *b)
{
	t_list	*lst;
	int		max;
	int		i;

	max = INT_MIN;
	i = 0;
	lst = b->lst;
	while (lst)
	{
		if (max < lst->content)
			max = lst->content;
		lst = lst->next;
	}
	lst = b->lst;
	while (lst && lst->content != max)
	{
		lst = lst->next;
		i++;
	}
	if (i <= b->size / 2)
		while (b->lst->content != max)
			rb(b);
	else
		while (b->lst->content != max)
			rrb(b);
}
