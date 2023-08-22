/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:58:31 by aatki             #+#    #+#             */
/*   Updated: 2023/08/22 15:55:16 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double Pythagore(t_pos s, t_pos d)
{
    // return (sqrt((s.x - d.y)^2 + (d.x- d.y)^2));
    return 1;
}

t_pos *find_wall(t_data *data)
{
    int x,y;
    t_pos *ret=malloc(sizeof(t_data));
    x=data->pos->x;
    y=data->pos->y;
    int h=1;
    if (h)
    {
        while(data->s[x][y]!='1')
        {
            x=tan(data->angle) * y;
        }
    }
    else
    {
        while(data->s[x][y]!='1')
        {
            y=tan(data->angle) * x;
        }
    }
    ret->x=x;
    ret->y=y;
    return ret;
}
