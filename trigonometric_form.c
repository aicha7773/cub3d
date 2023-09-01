/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigonometric_form.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:23:09 by aatki             #+#    #+#             */
/*   Updated: 2023/09/01 18:47:08 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	carre_t(t_data *data, int k, int d)
{
	int	harf;
	int	i;
	int	j;

	harf = 70;
	i = 0;
	while (j < harf)
	{
		my_mlx_pixel_put(data, d + i, k + j, 0xFF5FFF);
		j++;
	}
	j = 0;
	while (j < harf)
	{
		my_mlx_pixel_put(data, d + i + 70, k + j, 0xFF5FFF);
		j++;
	}
	while (i < harf)
	{
		my_mlx_pixel_put(data, d + i, k + j + 70, 0xFF5FFF);
		i++;
	}
	i = 0;
	while (j < harf)
	{
		my_mlx_pixel_put(data, d + i, k + j, 0xFF5FFF);
		i++;
	}
}

void	carre(t_data *data, int k, int d)
{
	int	harf;
	int	i;
	int	j;

	harf = 70;
	i = 0;
	while (i < harf)
	{
		j = 0;
		while (j < harf)
		{
			my_mlx_pixel_put(data, d + i, k + j, 0xFF5FFF);
			j++;
		}
		i++;
	}
}

void	put_ray(t_data *data, double angle, double dis)
{
	double x, y;
	x = data->pos->x;
	y = data->pos->y;
	while (dis > 0)
	{
		x += cos(angle);
		y += sin(angle);
		my_mlx_pixel_put(data, x, y, 0x00FF0000);
		dis--;
	}
}

void	circle(t_data *data, int centerX, int centerY, int radius)
{
	int	dx;
	int	dy;

	int x, y;
	for (y = centerY - radius; y <= centerY + radius; y++)
	{
		for (x = centerX - radius; x <= centerX + radius; x++)
		{
			dx = x - centerX;
			dy = y - centerY;
			if (dx * dx + dy * dy <= radius * radius)
			{
				my_mlx_pixel_put(data, x, y, 0x00FF0000);
			}
		}
	}
	raycasting(data);
}
