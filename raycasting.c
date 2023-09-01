/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:58:31 by aatki             #+#    #+#             */
/*   Updated: 2023/09/01 19:02:27 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	which_way(t_data *data, int i)
{
	if (pythagore(&data->rays[i].h, data->pos) > pythagore(data->pos,
															&data->rays[i].v))
	{
		data->rays[i].cas = 1;
		data->rays[i].dis = pythagore(&data->rays[i].v, data->pos);
	}
	else
	{
		data->rays[i].cas = 0;
		data->rays[i].dis = pythagore(&data->rays[i].h, data->pos);
	}
}

void	finding_wall(t_data *data, double angle, int i)
{
	t_pos_int	p;

	p.x = data->pos->x / 70;
	p.y = data->pos->y / 70;
	if (angle >= (3 * data->pi) / 2 && angle <= 2 * data->pi)
	{
		angle_n(data, angle, i, p);
	}
	else if (angle >= 0 && angle <= data->pi / 2)
	{
		angle_e(data, angle, i, p);
	}
	else if (angle > data->pi / 2 && angle <= data->pi)
	{
		angle_s(data, angle, i, p);
	}
	else if (angle > data->pi && angle < (3 * data->pi) / 2)
	{
		angle_w(data, angle, i, p);
	}
}

void	distance(t_data *data, double angle, int i)
{
	finding_wall(data, angle, i);
	which_way(data, i);
}

void	raycasting(t_data *data)
{
	int		nbr;
	double	angle;
	int		i;

	nbr = 0;
	angle = data->angle - data->pi / 6;
	i = 0;
	while (nbr < 1280)
	{
		angle += ((data->pi / 3) / 1280);
		if (angle > 2 * data->pi)
			angle -= 2 * data->pi;
		if (angle < 0)
			angle += 2 * data->pi;
		distance(data, angle, i);
		put_ray(data, angle, data->rays[i].dis);
		nbr++;
		i++;
	}
}
