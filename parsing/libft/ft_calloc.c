/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:57:25 by lsadiq            #+#    #+#             */
/*   Updated: 2022/11/10 06:37:34 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p1;

	// if (count == SIZE_MAX || size == SIZE_MAX)
	// {
	// 	return (NULL);
	// }
	p1 = malloc(count * size);
	if (!p1)
		return (NULL);
	ft_memset (p1, 0, count * size);
	return (p1);
}
