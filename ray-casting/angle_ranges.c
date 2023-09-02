/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_ranges.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:01:20 by aatki             #+#    #+#             */
/*   Updated: 2023/09/02 15:55:27 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	angle_n(t_data *data, double angle, int i, t_pos_int p)
{
	data->rays[i].h.y = floor(data->pos->y / 70) * 70 + 70 - 0.1;
	while (p.x >= 0 && p.y >= 0 && p.y <= data->hight && p.x <= data->weidth
		&& data->s[p.y][p.x] != '1')
	{
		data->rays[i].h.y -= 70;
		data->rays[i].h.x = data->pos->x + fabs((data->pos->y
					- data->rays[i].h.y) / tan(angle));
		p.x = data->rays[i].h.x / 70;
		p.y = data->rays[i].h.y / 70;
	}
	p.x = data->pos->x / 70;
	p.y = data->pos->y / 70;
	data->rays[i].v.x = floor(data->pos->x / 70) * 70;
	while (p.x >= 0 && p.y >= 0 && p.y <= data->hight && p.x <= data->weidth
		&& data->s[p.y][p.x] != '1')
	{
		data->rays[i].v.x += 70;
		data->rays[i].v.y = data->pos->y - fabs((data->pos->x
					- data->rays[i].v.x) * tan(angle));
		p.x = data->rays[i].v.x / 70;
		p.y = data->rays[i].v.y / 70;
	}
}

void	angle_e(t_data *data, double angle, int i, t_pos_int p)
{
	data->rays[i].h.y = floor(data->pos->y / 70) * 70 + 0.1;
	while (p.x >= 0 && p.y >= 0 && p.y <= data->hight && p.x <= data->weidth
		&& data->s[p.y][p.x] != '1')
	{
		data->rays[i].h.y += 70;
		data->rays[i].h.x = data->pos->x + fabs((data->pos->y
					- data->rays[i].h.y) / tan(angle));
		p.x = data->rays[i].h.x / 70;
		p.y = data->rays[i].h.y / 70;
	}
	p.x = data->pos->x / 70;
	p.y = data->pos->y / 70;
	data->rays[i].v.x = floor(data->pos->x / 70) * 70;
	while (p.x >= 0 && p.y >= 0 && p.y < data->hight && p.x < data->weidth
		&& data->s[p.y][p.x] != '1')
	{
		data->rays[i].v.x += 70;
		data->rays[i].v.y = data->pos->y + fabs((data->pos->x
					- data->rays[i].v.x) * tan(angle));
		p.x = data->rays[i].v.x / 70;
		p.y = data->rays[i].v.y / 70;
	}
}

void	angle_s(t_data *data, double angle, int i, t_pos_int p)
{
	data->rays[i].h.y = floor(data->pos->y / 70) * 70 + 0.1;
	while (p.x >= 0 && p.y >= 0 && p.y <= data->hight && p.x <= data->weidth
		&& data->s[p.y][p.x] != '1')
	{
		data->rays[i].h.y += 70;
		data->rays[i].h.x = data->pos->x - fabs((data->pos->y
					- data->rays[i].h.y) / tan(angle));
		p.x = data->rays[i].h.x / 70;
		p.y = data->rays[i].h.y / 70;
	}
	p.x = data->pos->x / 70;
	p.y = data->pos->y / 70;
	data->rays[i].v.x = floor(data->pos->x / 70) * 70 - 0.1;
	while (p.x >= 0 && p.y >= 0 && p.y < data->hight && p.x < data->weidth
		&& data->s[p.y][p.x] != '1')
	{
		data->rays[i].v.x -= 70;
		data->rays[i].v.y = data->pos->y + fabs((data->pos->x
					- data->rays[i].v.x) * tan(angle));
		p.x = data->rays[i].v.x / 70;
		p.y = data->rays[i].v.y / 70;
	}
}

void	angle_w(t_data *data, double angle, int i, t_pos_int p)
{
	data->rays[i].h.y = floor(data->pos->y / 70) * 70 + 70 - 0.1;
	while (p.x >= 0 && p.y >= 0 && p.y < data->hight && p.x < data->weidth
		&& data->s[p.y][p.x] != '1')
	{
		data->rays[i].h.y -= 70;
		data->rays[i].h.x = data->pos->x - fabs((data->pos->y
					- data->rays[i].h.y) / tan(angle));
		p.x = data->rays[i].h.x / 70;
		p.y = data->rays[i].h.y / 70;
	}
	p.x = data->pos->x / 70;
	p.y = data->pos->y / 70;
	data->rays[i].v.x = floor((data->pos->x) / 70) * 70 - 0.1;
	while (p.x >= 0 && p.y >= 0 && p.y < data->hight && p.x < data->weidth
		&& data->s[p.y][p.x] != '1')
	{
		data->rays[i].v.x -= 70;
		data->rays[i].v.y = data->pos->y - fabs((data->pos->x
					- data->rays[i].v.x) * tan(angle));
		p.x = data->rays[i].v.x / 70;
		p.y = data->rays[i].v.y / 70;
		// if (x < pythagore(data->pos,&data->rays[i].v))
		//  x-=1;
	}
}