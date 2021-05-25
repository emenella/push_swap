/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:32:18 by emenella          #+#    #+#             */
/*   Updated: 2021/05/25 18:32:19 by emenella         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_slack *slack)
{
	t_list	*result;
	t_list	*lst;

	if (slack->size > 0)
	{
		result = slack->lst->next;
		lst = ft_lstlast(result);
		lst->next = slack->lst;
		lst->next->next = NULL;
		slack->lst = result;
	}
}

void	rotate_a_b(t_slack *a, t_slack *b)
{
	rotate(a);
	rotate(b);
}

void	ra(t_slack *a)
{
	write(1, "ra\n", 3);
	rotate(a);
}

void	rb(t_slack *b)
{
	write(1, "rb\n", 3);
	rotate(b);
}

void	rr(t_slack *a, t_slack *b)
{
	write(1, "rr\n", 3);
	rotate(a);
	rotate(b);
}
