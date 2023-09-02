/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:24:59 by lsadiq            #+#    #+#             */
/*   Updated: 2022/11/08 02:31:30 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			count++;
		}
		i++;
	}
	return (count);
}

static void	strfree(char **p, size_t word)
{
	while (word-- > 0)
		free (p[word]);
	free (p);
}

static char	**my_substr(char **p, const char *s, char c, size_t i)
{
	size_t	seperator;
	size_t	word;

	word = 0;
	while (s[i])
	{
		seperator = i;
		while (s[i] && s[i] != c)
			i++;
		p[word] = ft_substr (s, seperator, i - seperator);
		if (!p[word])
		{
			strfree(p, word);
			return (NULL);
		}
		while (s[i] && s[i] == c)
			i++;
		word++;
	}
	p[word] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	i;

	if (!s)
		return (NULL);
	p = (char **)malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	return (my_substr(p, s, c, i));
}
