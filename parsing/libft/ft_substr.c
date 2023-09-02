/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:48:06 by lsadiq            #+#    #+#             */
/*   Updated: 2022/11/10 07:15:34 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	l;

	if (!s)
		return (NULL);
	i = 0;
	l = ft_strlen(s);
	if (l < start)
		return (ft_strdup(""));
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
