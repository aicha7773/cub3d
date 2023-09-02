/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:06:49 by lsadiq            #+#    #+#             */
/*   Updated: 2023/09/01 15:07:02 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_space(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] && !ft_isalnum(s[i]))
	{
		if (s[i] == ' ' || s[i] == '\t')
			count++;
		i++;
	}
	return (count);
}

int	safe_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]))
			return (1);
		i++;
	}
	return (0);
}
int	check_line(char *holder)
{
	int	i;

	i = 0;
	while (holder[i] && holder[i] != ' ')
		i++;
	if (i == 0)
		return (-1);
	while (holder[i] && holder[i] == ' ')
		i++;
	return (i);
}

char	*spaces_end(char *s)
{
	int		i;
	int		j;
	char	*ret;

	ret = ft_strdup("");
	i = ft_strlen(s) - 1;
	j = 0;
	while (j < i)
	{
		if (s[i] == ' ')
			i--;
		else
			break ;
		j++;
	}
	j = 0;
	while (j <= i)
	{
		ret = ft_strjoin_modif(ret, s[j++]);
	}
	free(s);
	return (ret);
}

void	print_error(char *str)
{
	printf("%s\n", str);
	exit(0);
}