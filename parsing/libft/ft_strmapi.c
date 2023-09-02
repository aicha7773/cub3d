/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:09:50 by lsadiq            #+#    #+#             */
/*   Updated: 2022/11/08 01:34:59 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*sr;
	unsigned int	len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	sr = (char *) malloc (sizeof(char) * (len + 1));
	if (!sr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		sr[i] = (*f)(i, s[i]);
		i++;
	}
	sr[i] = 0;
	return (sr);
}
