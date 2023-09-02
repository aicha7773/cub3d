/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:00:06 by aatki             #+#    #+#             */
/*   Updated: 2023/09/02 16:04:45 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	initialize(t_data *data)
{
	data->pos = position(data->s);
	data->rays = malloc(sizeof(t_rays) * 1280);
	data->keys.w = 0;
	data->keys.d = 0;
	data->keys.s = 0;
	data->keys.a = 0;
	data->keys.left = 0;
	data->keys.right = 0;
	data->pi = M_PI;
	initialize_angle(data);
}

void	transmitter(char **s,int weidth, int hight)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->s = s;
	data->weidth = weidth;
	data->hight = hight;
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, 1280, 720, "Hello world!");
	data->img = mlx_new_image(data->mlx, 1280, 720);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	initialize(data);
	affiche(data);
	mlx_hook(data->window, 03, 1L << 1, key_up, data);
	mlx_hook(data->window, 02, 1L << 0, key_down, data);
	mlx_hook(data->window, 17, 0, ft_exit, NULL);
	mlx_loop_hook(data->mlx, check_key, data);
	mlx_loop(data->mlx);
}
