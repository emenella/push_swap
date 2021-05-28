/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:31:03 by emenella          #+#    #+#             */
/*   Updated: 2021/05/28 18:07:10 by emenella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == '-')
		return (1);
	return (0);
}

void	spacejump(int *i, const char *nptr, int *j)
{
	while ((nptr[*i] >= 9 && nptr[*i] <= 13) || nptr[*i] == 32)
		*i += 1;
	*j = *i;
}

void	signjump(int *i, const char *nptr, int *minuscount)
{
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			*minuscount = 1;
		*i += 1;
	}
}

long	ft_atoi(const char *nptr)
{
	int		i;
	int		j;
	int		minuscount;
	long	result;

	i = 0;
	minuscount = 0;
	result = 0;
	spacejump(&i, nptr, &j);
	signjump(&i, nptr, &minuscount);
	while (ft_isdigit(nptr[i]))
	{
		result *= 10;
		result += nptr[i++] - 48;
	}
	if (minuscount == 1)
		result = -result;
	return (result);
}

void	*ft_exit(t_slack *a)
{
	ft_listfree(a->lst);
	free(a);
	write(1, "Error\n", 6);
	return (NULL);
}
