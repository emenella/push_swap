/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:31:47 by emenella          #+#    #+#             */
/*   Updated: 2021/05/25 18:31:48 by emenella         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_slack	*ft_arg_to_slack(char **arg, int argc)
{
	int		i;
	t_slack	*a;
	int		y;

	a = ft_init_slack(0);
	i = 0;
	while (i++ < argc - 1)
	{
		y = -1;
		while (y++ && arg[i][y] && !ft_isdigit(arg[i][y]))
			return (ft_exit(a));
		if (ft_lstadd_back(&a->lst, ft_lstnew(ft_atoi(arg[i]))))
			return (ft_exit(a));
		a->size++;
	}
	return (a);
}

int	ft_is_ok(t_slack *a)
{
	int		i;
	t_list	*lst;

	i = -1;
	lst = a->lst;
	while (++i < a->size - 1)
	{
		if (lst->content >= lst->next->content)
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
		else if (a->size <= 4)
			sort_5(a, b);
		else if (a->size == 3)
			sort_3(a);
		else if (a->size == 2)
			if (a->lst->content > a->lst->next->content)
				sa(a);
		ft_listfree(a->lst);
		ft_listfree(b->lst);
		free(a);
		free(b);
	}
}
