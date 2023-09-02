/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:39:38 by lsadiq            #+#    #+#             */
/*   Updated: 2023/09/01 18:13:22 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parse(char **map)
{
	int		j;
	int		k;
	int		i;
	char	*elem;

	elem = "10ENSW";
	i = -1;
	k = 0;
	while (map[k])
		k++;
	// print_2d(map);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'S' || map[i][j] == 'N' || map[i][j] == 'E'
				|| map[i][j] == '0' || map[i][j] == 'W')
			{
				if ((j == 0 || i == 0) || i == k - 1 || j == ft_strlen(map[i])
					- 1)
					print_error("Error");
				check_sides(j, map[i + 1], map[i - 1]);
				if (ft_strchr(elem, map[i - 1][j]) || ft_strchr(elem, map[i
						+ 1][j]) || ft_strchr(elem, map[i][j - 1])
					|| ft_strchr(elem, map[i][j + 1]))
					print_error("ERROOR");
			}
		}
	}
}

void	parse_map(t_map *src)
{
	elem_checker(src->map);
	ft_parse(src->map);
	ft_player(src->map);
}