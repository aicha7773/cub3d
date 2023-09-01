/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:12:49 by aatki             #+#    #+#             */
/*   Updated: 2023/09/01 18:38:07 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_exit(void)
{
	exit(0);
}

t_pos	*position(char **s)
{
	int		i;
	int		j;
	t_pos	*pos;

	i = 0;
	pos = malloc(sizeof(t_pos));
	if (!s)
		return (0);
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == 'S' || s[i][j] == 'N' || s[i][j] == 'E'
				|| s[i][j] == 'W')
			{
				pos->y = i * 70;
				pos->x = j * 70;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

void	initialize_angle(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->s[i])
	{
		j = 0;
		while (data->s[i][j])
		{
			if (data->s[i][j] == 'N')
			{
				data->angle = (3 * data->pi) / 2;
			}
			else if (data->s[i][j] == 'S')
				data->angle = data->pi / 2;
			else if (data->s[i][j] == 'E')
				data->angle = 0;
			else if (data->s[i][j] == 'W')
				data->angle = data->pi;
			j++;
		}
		i++;
	}
}
