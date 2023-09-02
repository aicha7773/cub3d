/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 01:57:35 by lsadiq            #+#    #+#             */
/*   Updated: 2022/11/08 01:48:05 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		len;

	len = 0;
	i = 0;
	if (dst == src)
		return (ft_strlen(src));
	while (src[len])
		len++ ;
	if (dstsize == 0)
		return (len);
	while ((src[i] != '\0') && (i < len) && (i < (dstsize - 1)))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
