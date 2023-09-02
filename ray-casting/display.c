/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 22:46:20 by aatki             #+#    #+#             */
/*   Updated: 2023/09/01 18:23:47 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= 1280 || y >= 720)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	affiche(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	while (data->s[i])
	{
		y = 0;
		j = 0;
		while (data->s[i][j])
		{
			// printf("%c",data->s[i][j]);
			if (data->s[i][j] == '1')
				carre(data, x, y);
			carre_t(data, x, y);
			y += 70;
			j++;
		}
		// printf("\n");
		i++;
		x += 70;
	}
	circle(data, data->pos->x, data->pos->y, 10);
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
}
