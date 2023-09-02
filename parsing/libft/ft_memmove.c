/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 09:49:11 by lsadiq            #+#    #+#             */
/*   Updated: 2022/11/10 06:44:06 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*d;
	char	*s;

	if (dst == src)
		return (dst);
	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (s > d)
		ft_memcpy(dst, src, len);
	else
	{
		while (len--)
			d[len] = s[len];
	}
	return (dst);
}
