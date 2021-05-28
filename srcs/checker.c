/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:30:25 by emenella          #+#    #+#             */
/*   Updated: 2021/05/28 15:22:30 by emenella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_slack	*ft_arg_to_slack(char **arg, int argc)
{
	int		i;
	t_slack	*a;
	int		y;
	long	result;

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

t_cmd	*ft_read_cmd(void)
{
	t_cmd	*cmd;
	int		ret;
	char	*line;

	ret = 1;
	cmd = NULL;
	line = NULL;
	while (ret == 1)
	{
		ret = get_next_line(&line);
		ft_cmdadd_back(&cmd, ft_cmdnew(line));
	}
	return (cmd);
}

int	ft_exec_cmd(t_cmd **cmd, t_slack *a, t_slack *b)
{
	t_cmd	*lst;

	lst = *cmd;
	while (lst && lst->content[0] != 0)
	{
		if (ft_cmd_to_operation(lst->content) < 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		ft_exec_operation(ft_cmd_to_operation(lst->content), a, b);
		lst = lst->next;
	}
	return (1);
}

void	ft_is_ok(t_slack *a, t_slack *b)
{
	t_list	*lst;

	lst = a->lst;
	while (lst->next)
	{
		if (lst->content > lst->next->content)
		{
			write(1, "KO\n", 3);
			return ;
		}
		lst = lst->next;
	}
	if (b->size == 0)
		write(1, "OK\n", 3);
}

int	main(int argc, char **arg)
{
	t_slack	*a;
	t_slack	*b;
	t_cmd	*cmd;

	a = ft_arg_to_slack(arg, argc);
	cmd = NULL;
	if (a != NULL && argc > 1)
	{
		b = ft_init_slack(0);
		cmd = ft_read_cmd();
		if (ft_exec_cmd(&cmd, a, b))
			ft_is_ok(a, b);
		ft_listfree(a->lst);
		ft_listfree(b->lst);
		ft_cmdfree(cmd);
		free(a);
		free(b);
	}
}
