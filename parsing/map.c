/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 02:07:08 by lsadiq            #+#    #+#             */
/*   Updated: 2023/09/01 18:05:07 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_unit	init_elem(void)
{
	t_unit	cub;

	cub.c = 0;
	cub.f = 0;
	cub.ea = 0;
	cub.no = 0;
	cub.so = 0;
	cub.we = 0;
	return (cub);
}

void	save_map(char *file, t_map *map)
{
	int		fd;
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("file can't be opened\n");
		close(fd);
		exit(1);
	}
	map->arr = malloc(sizeof(char *) * (map->len + 1));
	if (!map->arr)
		print_error("erreur");
	line = get_next_line(fd);
	tmp = line;
	while (line)
	{
		map->arr[i] = tmp;
		line = get_next_line(fd);
		tmp = line;
		i++;
	}
	map->arr[i] = NULL;
	print_2d(map->arr);
}

void	check_filename(char *name)
{
	while (*name)
	{
		if (*name == '.')
		{
			if (ft_strncmp(".cub", name, 5) == 0)
				return ;
		}
		name++;
	}
	ft_putstr_fd("file is not valid !", 1);
	exit(1);
}
void	print_2d(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		printf("%s\n", str[i]);
}

void	ft_player(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'N'
				|| map[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		print_error("player error");
}
int	ft_strnstr_modf(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lenh;

	i = 0;
	j = 0;
	if ((!haystack || !needle) && len == 0)
		return (1);
	lenh = ft_strlen(haystack);
	if (lenh <= len)
		return (1);
	if (!ft_strncmp(haystack + lenh - len, needle, len))
		return (0);
	return (1);
}
