/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_f.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:03:26 by lsadiq            #+#    #+#             */
/*   Updated: 2023/09/01 17:52:48 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	Ceiling(char *holder, t_map *map)
{
	char	*tmp;
	int		count;
	int		i;
	int		flag;

	i = 0;
	tmp = ft_strdup("");
	count = check_line_cf(holder);
	if (count == -1)
	{
		printf("error ce!\n");
		exit(0);
	}
	while (holder[count])
		tmp = ft_strjoin_modif(tmp, holder[count++]);
	tmp = spaces_end(tmp);
	if (ft_strrchr(tmp, ' '))
	{
		free(tmp);
		puts("error with the space");
		exit(0);
	}
	if (!map->c)
		map->c = tmp;
	else
		free(tmp);
	flag = ft_calculate(map->c, ',');
	if (flag == 2)
	{
		map->rgb = ft_split(map->c, ',');
		while (map->rgb[i])
		{
			map->rgbc = ft_atoi(map->rgb[i]);
			if ((map->rgbc < 0) || (map->rgbc > 255))
				print_error("out of range!");
			i++;
		}
		if (i != 3)
			print_error("wrong number of rgb elem!");
	}
	else
		print_error("comma issue");
}

void	Floor(char *holder, t_map *map)
{
	char	*tmp;
	int		count;
	int		i;
	int		flag;

	i = 0;
	tmp = ft_strdup("");
	count = check_line_cf(holder);
	if (count == -1)
	{
		printf("error ce!\n");
		exit(0);
	}
	while (holder[count])
		tmp = ft_strjoin_modif(tmp, holder[count++]);
	tmp = spaces_end(tmp);
	if (ft_strrchr(tmp, ' '))
	{
		free(tmp);
		puts("error with the space");
		exit(0);
	}
	if (!map->f)
		map->f = tmp;
	else
		free(tmp);
	flag = ft_calculate(map->f, ',');
	if (flag == 2)
	{
		map->rgb = ft_split(map->f, ',');
		while (map->rgb[i])
		{
			map->rgbf = ft_atoi(map->rgb[i]);
			if ((map->rgbf < 0) || (map->rgbf > 255))
				print_error("out of range!");
			i++;
		}
		if (i != 3)
			print_error("wrong number of rgb elem!");
	}
	else
		print_error("comma issue");
}
