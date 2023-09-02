/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:40:17 by lsadiq            #+#    #+#             */
/*   Updated: 2023/09/01 15:19:21 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	North(char *holder, t_map *map)
{
	char	*tmp;
	int		count;
	int		i;

	i = 0;
	tmp = ft_strdup("");
	count = check_line(holder);
	if (count == -1)
	{
		printf("errorrr!\n");
		exit(0);
	}
	while (holder[count])
		tmp = ft_strjoin_modif(tmp, holder[count++]);
	tmp = spaces_end(tmp);
	if (ft_strrchr(tmp, ' '))
	{
		free(tmp);
		puts("error wwith the spaceeee");
		exit(0);
	}
	if (ft_strnstr_modf(tmp, ".xpm", 4))
		print_error("not a xpm file!");
	if (!map->NO)
		map->NO = tmp;
	else
		free(tmp);
}

void	West(char *holder, t_map *map)
{
	char	*tmp;
	int		count;
	int		i;

	i = 0;
	tmp = ft_strdup("");
	count = check_line(holder);
	if (count == -1)
	{
		printf("errooor!\n");
		exit(0);
	}
	while (holder[count])
		tmp = ft_strjoin_modif(tmp, holder[count++]);
	tmp = spaces_end(tmp);
	if (ft_strrchr(tmp, ' '))
	{
		free(tmp);
		puts("errooor with the space");
		exit(0);
	}
	if (ft_strnstr_modf(tmp, ".xpm", 4))
		print_error("not a xpm file!");
	if (!map->WE)
		map->WE = tmp;
	else
		free(tmp);
}
void	East(char *holder, t_map *map)
{
	char	*tmp;
	int		count;
	int		i;

	i = 0;
	tmp = ft_strdup("");
	count = check_line(holder);
	if (count == -1)
	{
		printf("error!\n");
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
	if (ft_strnstr_modf(tmp, ".xpm", 4))
		print_error("not a xpm file!");
	if (!map->EA)
		map->EA = tmp;
	else
		free(tmp);
}

void	South(char *holder, t_map *map)
{
	char	*tmp;
	int		count;
	int		i;

	i = 0;
	tmp = ft_strdup("");
	count = check_line(holder);
	if (count == -1)
	{
		printf("errorrrr!\n");
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
	if (ft_strnstr_modf(tmp, ".xpm", 4))
		print_error("not a xpm file!");
	if (!map->SO)
		map->SO = tmp;
	else
		free(tmp);
}

int	ft_calculate(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
			j++;
		i++;
	}
	return (j);
}
