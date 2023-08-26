/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:58:31 by aatki             #+#    #+#             */
/*   Updated: 2023/08/26 23:43:32 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double pythagore(t_pos *s, t_pos *d)
{
    return (sqrt(pow(s->x - d->x, 2) + pow (s->y- d->y, 2)));
}

t_pos *find_wall(t_data *data,double angle)
{
    int x,y;
    t_pos *ret=malloc(sizeof(t_data));

    x=data->pos->x/70;
    y=data->pos->y/70;
    int h=1;
    int i=5;
    if (h)
    {
        // DEBUGGING
        while(x < 1 && x>=0 && y>=0 && data->s[x][y]!='1')
        {
            x+=tan(angle) * y;
            i--;
        }
        printf("coords: %d, %d\n", x, y);
    }
    else
    {
        while(data->s[x][y]!='1')
        {
            y*=tan(angle) * x;
        }
    }
    ret->x=x;
    ret->y=y;
    return ret;
}

double distance(t_data *data, double angle)
{
    t_pos *pos=find_wall(data,angle);
    double distance;
    distance = pythagore(pos,data->pos);
    free(pos);
    printf("distance =%f\n",distance);
    return (100);
}

double Thales(double a,double b, double c)
{
    return ((c/a)*b);
}
