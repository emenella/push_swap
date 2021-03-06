/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:31:47 by emenella          #+#    #+#             */
/*   Updated: 2021/06/27 01:39:48 by emenella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_slack	*ft_arg_to_slack(char **arg, int argc)
{
	int		i;
	t_slack	*a;
	int		y;
	long	result;

	if (argc == 1)
		return (NULL);
	a = ft_init_slack(0);
	i = 0;
	while (i++ < argc - 1)
	{
		y = -1;
		while (y++ && arg[i][y] && !ft_isdigit(arg[i][y]))
			return (ft_exit(a));
		result = ft_atoi(arg[i]);
		if ((result > 2147483647 || result < -2147483647))
			return (ft_exit(a));
		if (ft_lstadd_back(&a->lst, ft_lstnew((int)result)))
			return (ft_exit(a));
		a->size++;
	}
	return (a);
}

int	ft_min(t_slack *slack)
{
	t_list	*lst;
	int		min;

	lst = slack->lst;
	min = INT_MAX;
	while (lst)
	{
		if (min > lst->content)
			min = lst->content;
		lst = lst->next;
	}
	return (min);
}

int	ft_is_ok(t_slack *a)
{
	t_list	*lst;

	lst = a->lst;
	while (lst->next)
	{
		if (lst->content > lst->next->content)
		{
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

int	main(int argc, char **arg)
{
	t_slack	*a;
	t_slack	*b;

	a = ft_arg_to_slack(arg, argc);
	if (a != NULL && ft_is_ok(a))
	{
		b = ft_init_slack(0);
		if (a->size >= 500)
			sort_500(a, b);
		else if (a->size > 5)
			sort_100(a, b);
		else if (a->size == 4 || a->size == 5)
			sort_5(a, b);
		else if (a->size == 3)
			sort_3(a);
		else if (a->size == 2)
			if (a->lst->content > a->lst->next->content)
				sa(a);
		ft_listfree(b->lst);
		free(b);
		ft_listfree(a->lst);
		free(a);
	}
}
