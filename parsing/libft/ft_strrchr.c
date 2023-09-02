/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:00:12 by lsadiq            #+#    #+#             */
/*   Updated: 2022/11/08 01:48:21 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	const char	b = c;

	i = ft_strlen(s) + 1;
	while (i > 0)
	{
		i-- ;
		if (s[i] == b)
		{
			return ((char *)s + i);
		}
	}
	return (0);
}
