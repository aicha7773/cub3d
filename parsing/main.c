/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 01:52:52 by lsadiq            #+#    #+#             */
/*   Updated: 2023/09/02 16:07:11 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"
// # include "../ray-casting/cub.h"

void	ft_len(char *file, t_map *src)
{
	int		i;
	char	*str;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		src->len++;
	}
}

void	wei_hei(t_map *src, t_unit *elem)
{
	int	i;
	int	curr;
	int	tmp;

	tmp = 0;
	i = 0;
	while (src->map[i])
	{
		curr = ft_strlen(src->map[i]);
		if (curr > tmp)
			tmp = curr;
		i++;
	}
	src->weidth = tmp;
	src->height = src->len - elem->num_elem;
	printf("%d\n", src->height);
}

void	elem_checker(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'E'
				&& map[i][j] != ' ' && map[i][j] != 'N' && map[i][j] != 'S'
				&& map[i][j] != 'W')
				print_error("missing element!");
			j++;
		}
		i++;
	}
}

void	check_sides(int curr, char *next, char *prev)
{
	int	i;
	int	j;

	i = ft_strlen(prev);
	j = ft_strlen(next);
	if (curr >= i || curr >= j)
		print_error("something went wrong");
}

int	main(int ac, char **av)
{
	t_map	*map;
	t_unit	elem;

	if (ac == 2)
	{
		map = ft_calloc(sizeof(t_map), 1);
		check_filename(av[1]);
		ft_len(av[1], map);
		save_map(av[1], map);
		elem = init_elem();
		check_map(map->arr, &elem, map);
		valid_elem(elem, map->arr);
		get_real_map(elem, map, map->arr);
		wei_hei(map, &elem);
		// print_2d(map->map);
		parse_map(map);
		transmitter(map->map, map->weidth,map->height-1);
	}
}
