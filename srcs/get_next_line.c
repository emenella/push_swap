/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:31:11 by emenella          #+#    #+#             */
/*   Updated: 2021/05/25 18:31:13 by emenella         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	size_t	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (&str[i]);
	return (NULL);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		lens1;
	int		lens2;
	int		i;
	char	*str;

	i = 0;
	lens1 = 0;
	if (s1)
		lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (str == NULL)
		return (NULL);
	while (i < lens1 + lens2)
	{
		if (i < lens1)
			str[i] = s1[i];
		else if (i >= lens1)
			str[i] = s2[i - lens1];
		i++;
	}
	str[lens1 + lens2] = '\0';
	free(s1);
	return (str);
}

int	get_next_line(char **line)
{
	static char	buffer[2];
	int			readed;

	readed = 1;
	buffer[0] = 0;
	(*line = malloc(sizeof(char)));
	if (*line == NULL)
		return (-1);
	*line[0] = 0;
	while (readed > 0)
	{
		readed = read(0, buffer, 1);
		if (buffer[0] == '\n')
			break ;
		*line = ft_strjoin_free(*line, buffer);
	}
	if (readed != 1)
		return (0);
	else
		return (1);
}
