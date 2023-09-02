/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:18:35 by lsadiq            #+#    #+#             */
/*   Updated: 2023/09/01 17:32:12 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s && s[i] != '\0' && s[i] != (char)c)
		i++;
	if (s[i] == '\n')
		return (1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	i;
	size_t	j;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	p = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
	{
		while (s1[++i])
			p[i] = s1[i];
	}
	while (s2[j])
	{
		p[i + j] = s2[j];
		j++;
	}
	return (free(s1), p[i + j] = '\0', p);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	l;

	if (!s)
		return (NULL);
	i = 0;
	l = ft_strlen(s);
	if (l < start)
		return (ft_strdup("\0"));
	if (len >= l)
		p = malloc(sizeof(char) * (l + 1));
	else
		p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (s[i] && len > 0 && s[start])
	{
		p[i++] = s[start++];
		len--;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strdup(char *s1)
{
	size_t i;
	char *p;

	i = 0;
	p = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}