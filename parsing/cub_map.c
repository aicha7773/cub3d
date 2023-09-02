/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:08:27 by lsadiq            #+#    #+#             */
/*   Updated: 2023/09/01 17:41:05 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_reader(char **holder, t_unit *elem, int i, t_map *map)
{
	int	j;

	j = skip_space(holder[i]);
	if (holder[i][j] == 'N' && holder[i][j + 1] == 'O' && holder[i][j
		+ 2] == ' ')
	{
		North(&holder[i][j], map);
		elem->count_elem++;
		elem->no++;
	}
	else if (holder[i][j] == 'E' && holder[i][j + 1] == 'A' && holder[i][j
			+ 2] == ' ')
	{
		East(&holder[i][j], map);
		elem->count_elem++;
		elem->ea++;
	}
	else if (holder[i][j] == 'W' && holder[i][j + 1] == 'E' && holder[i][j
			+ 2] == ' ')
	{
		West(&holder[i][j], map);
		elem->count_elem++;
		elem->we++;
	}
	else if (holder[i][j] == 'S' && holder[i][j + 1] == 'O' && holder[i][j
			+ 2] == ' ')
	{
		South(&holder[i][j], map);
		elem->count_elem++;
		elem->so++;
	}
	else if (holder[i][j] == 'C' && holder[i][j + 1] == ' ')
	{
		Ceiling(holder[i], map);
		elem->count_elem++;
		elem->c++;
	}
	else if (holder[i][j] == 'F' && holder[i][j + 1] == ' ')
	{
		Floor(holder[i], map);
		elem->count_elem++;
		elem->f++;
	}
	return (elem->count_elem);
}

// 1
void	valid_elem(t_unit elem, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < elem.num_elem - 1)
	{
		j = skip_space(map[i]);
		if (map[i][j] == 'N' && map[i][j + 1] == 'O' && map[i][j + 2] == ' ')
			i++;
		else if (map[i][j] == 'W' && map[i][j + 1] == 'E' && map[i][j
				+ 2] == ' ')
			i++;
		else if (map[i][j] == 'E' && map[i][j + 1] == 'A' && map[i][j
				+ 2] == ' ')
			i++;
		else if (map[i][j] == 'S' && map[i][j + 1] == 'O' && map[i][j
				+ 2] == ' ')
			i++;
		else if (map[i][j] == 'F' && map[i][j + 1] == ' ')
			i++;
		else if (map[i][j] == 'C' && map[i][j + 1] == ' ')
			i++;
		else if (!map[i][j])
			i++;
		else
			print_error("wrong element!");
	}
}

// 2
void	check_map(char **holder, t_unit *elem, t_map *param)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	elem->count_elem = 0;
	while (holder[i])
	{
		if (safe_line(holder[i]) && elem->count_elem == 6)
			break ;
		else if (!safe_line(holder[i]))
			j++;
		elem->count_elem = map_reader(holder, elem, i, param);
		i++;
	}
	if (elem->count_elem != 6)
		print_error("Invalid number");
	elem->num_elem = elem->count_elem + j;
}

void	get_real_map(t_unit elem, t_map *src, char **map)
{
	int	k;
	int	j;

	src->i = 0;
	k = elem.num_elem;
	while (map[k])
	{
		k++;
		src->i++;
	}
	src->map = malloc(sizeof(char *) * (src->i + 1));
	j = 0;
	while (map[elem.num_elem])
		src->map[j++] = ft_strdup(map[elem.num_elem++]);
	src->map[j] = NULL;
}
