/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 08:19:44 by aatki             #+#    #+#             */
/*   Updated: 2023/09/01 18:14:47 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	translation(t_data *data, t_pos pos)
{
	if (data->s[(int)pos.y / 70][(int)pos.x / 70] != '1')
	{
		data->pos->x = pos.x;
		data->pos->y = pos.y;
		mlx_destroy_image(data->mlx, data->img);
		affiche(data);
	}
}

void	rotation(t_data *data)
{
	if (data->keys.right == 1) //right
		data->angle += data->pi / 100;
	else if (data->keys.left == 1) //left
		data->angle -= data->pi / 100;
	//
	if (data->angle > 2 * data->pi)
		data->angle -= 2 * data->pi;
	if (data->angle < 2 * data->pi)
		data->angle += 2 * data->pi;
	mlx_destroy_image(data->mlx, data->img);
	affiche(data);
}

void	new_position(t_data *data)
{
	t_pos	pos;

	if (data->keys.w) //w
	{
		pos.x = data->pos->x + cos(data->angle);
		pos.y = data->pos->y + sin(data->angle);
	}
	else if (data->keys.s) //s
	{
		pos.x = data->pos->x - cos(data->angle);
		pos.y = data->pos->y - sin(data->angle);
	}
	if (data->keys.d) //d
	{
		pos.x = data->pos->x + sin(data->angle);
		pos.y = data->pos->y + cos(data->angle);
	}
	else if (data->keys.a) //a
	{
		pos.x = data->pos->x - sin(data->angle);
		pos.y = data->pos->y - cos(data->angle);
	}
	if (data->keys.w || data->keys.d || data->keys.a || data->keys.s)
		translation(data, pos);
	if (data->keys.left || data->keys.right)
		rotation(data);
}

int	check_key(t_data *data)
{
	new_position(data);
	return (1);
}
