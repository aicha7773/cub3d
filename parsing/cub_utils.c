/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:21:18 by lsadiq            #+#    #+#             */
/*   Updated: 2023/08/31 17:15:07 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//
char	*ft_strjoin_modif(char const *s1, char c)
{
	char	*p;
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	p = (char *)malloc(sizeof(char) * ft_strlen(s1) + 2);
	if (!p)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = c;
	p[i + 1] = '\0';
	// free(s1);
	return (p);
}
//

int	check_line_cf(char *holder)
{
	int	i;

	i = skip_space(holder);
	while (holder[i])
	{
		if (ft_isdigit(holder[i]))
			return (i);
		else if (holder[i] != ' ' && holder[i] != '\t' && !ft_isdigit(holder[i])
				&& holder[i] != 'F' && holder[i] != 'C')
			return (-1);
		i++;
	}
	return (-1);
}
