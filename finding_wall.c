// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   finding_wall.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/08/22 14:58:31 by aatki             #+#    #+#             */
// /*   Updated: 2023/08/30 19:03:39 by aatki            ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "cub.h"

// double pythagore(t_pos *s, t_pos *d)
// {
//     return (sqrt(pow(s->x - (d->x), 2) + pow (s->y - (d->y), 2)));
// }

// double thales(double a,double b, double c)
// {
//     return ((c/a)*b);
// }

// void which_way(t_data *data,double angle,int i)
// {
//     double pi=M_PI;

//     if (angle >= (3 *pi)/2 && angle <= 2*pi)
//     {
//         data->rays[i].h.y = floor(data->pos->y/70) * 70;
//         data->rays[i].h.x = data->pos->x + (data->pos->y - data->rays[i].h.y)/tan(angle);
//         data->rays[i].v.x = floor(data->pos->x/70) * 70  + 70;
//         data->rays[i].v.y = data->pos->y - fabs((data->pos->x - data->rays[i].v.x)* tan(angle)); 
//         printf(" h %f, ngle%f\n",data->rays[i].v.x  ,tan(angle));
//         // exit(0);
        

//     }
//     // if (data->angle >= 0 && data->angle <= pi/2)
//     // {
//     //     data->rays[i].y = floor(data->pos->y/70) * 70;
//     //     data->rays[i].x = data->pos->x + (data->pos->y - data->rays[i].y)/tan(data->angle);
//     //     data->rays[i].x = floor(data->pos->x/70) * 70 - 70;
//     //     data->rays[i].y = data->pos->y + (data->pos->x - data->rays[i].x)*tan(data->angle);
//     // }
//     // if (data->angle >= 0 && data->angle <= pi/2)
//     // {
//     //     data->rays[i].y = floor(data->pos->y/70) * 70;
//     //     data->rays[i].x = data->pos->x + (data->pos->y - data->rays[i].y)/tan(data->angle);
//     //     data->rays[i].x = floor(data->pos->x/70) * 70 + 70;
//     //     data->rays[i].y = data->pos->y + (data->pos->x - data->rays[i].x)*tan(data->angle);
//     // }
//     // if (data->angle >= 0 && data->angle <= pi/2)
//     // {
//     //     data->rays[i].y = floor(data->pos->y/70) * 70;
//     //     data->rays[i].x = data->pos->x + (data->pos->y - data->rays[i].y)/tan(data->angle);
//     //     data->rays[i].x = floor(data->pos->x/70) * 70 + 70;
//     //     data->rays[i].y = data->pos->y + (data->pos->x - data->rays[i].x)*tan(data->angle);
//     // }
//     // if (pythagore(&data->rays[i].h,data->pos) > pythagore(data->pos,&data->rays[i].v))
//     // {
//     //     data->rays[i].cas = 1;
//     //     data->rays[i].dis=pythagore(&data->rays[i].v,data->pos);
//     // }
//     // else
//     // {
//     //     data->rays[i].cas = 0;
//         data->rays[i].dis=pythagore(&data->rays[i].v,data->pos);
//     // }
//    //
//     // note : rays-> or maybe // rays[i].
//     // put_ray(data,data->angle, data->rays->dis);
// }

// t_pos *find_wall(t_data *data,double angle)
// {
//     int x,y;
//     t_pos *ret=malloc(sizeof(t_data));
//     x=data->pos->x/70;
//     y=data->pos->y/70;
//     int h=1;
//     if (h)
//     {
//         x += tan(angle) * 35;
//         y++;
//         while ( x < 24 && y < 12 && x>=0 && y>=0 && data->s[y][x]!='1')
//         {
//             x += tan(angle)* 70;
//             // printf("angle %ftan %f\n", angle, tan(angle)*70);
//             y++;
//         }
//     }
//     else
//     {
//         while(data->s[x][y]!='1')
//         {
//             y += tan(angle) * x;
//         }
//     }
//     ret->x=x;
//     ret->y=y;
//     return ret;
// }

// double distance(t_data *data, double angle,int i)
// {
//     double distance;
//     // t_pos *pos=find_wall(data,angle);

//     which_way(data,angle,i);
//     // distance = pythagore(pos,data->pos);
//     // free(pos);
//     // printf("distance =%f\n",distance);
//     // distance=1;
//     return (data->rays[i].dis);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:58:31 by aatki             #+#    #+#             */
/*   Updated: 2023/08/30 20:23:09 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double pythagore(t_pos *s, t_pos *d)
{
    return (sqrt(pow(s->x - (d->x), 2) + pow (s->y - (d->y), 2)));
}

double thales(double a,double b, double c)
{
    return ((c/a)*b);
}

void which_way(t_data *data,double angle,int i)
{
    double pi=M_PI;
    int x,y;

    x=data->pos->x/70;
    y=data->pos->y/70;

    data->rays[i].h.x=data->pos->x;
    data->rays[i].h.y=data->pos->y;

    data->rays[i].v.x=data->pos->x;
    data->rays[i].v.y=data->pos->y;

    if (angle >= (3 *pi)/2 && angle <= 2*pi)
    {
        data->rays[i].h.y = floor(data->pos->y/70) * 70 + 70 - 0.1;
        while(x >= 0 && y >= 0  && y <= 11 && x <= 24 && data->s[y][x]!='1')
        {
            data->rays[i].h.y -= 70;
            data->rays[i].h.x = data->pos->x + fabs((data->pos->y - data->rays[i].h.y)/tan(angle));
            x=data->rays[i].h.x/70;
            y=data->rays[i].h.y/70;
        }
  x=data->pos->x/70;
    y=data->pos->y/70;
        data->rays[i].v.x = floor(data->pos->x/70) * 70;
        while(x >= 0 && y >= 0  && y <= 11 && x <= 24 && data->s[y][x]!='1')
        {
            printf("c = %c\n",data->s[y][x]);
            data->rays[i].v.x += 70;
            data->rays[i].v.y = data->pos->y - fabs((data->pos->x - data->rays[i].v.x)* tan(angle));
            x=data->rays[i].v.x/70;
            y=data->rays[i].v.y/70;
        }
    }

    if (pythagore(&data->rays[i].h,data->pos) > pythagore(data->pos,&data->rays[i].v))
    {
        data->rays[i].cas = 1;
        data->rays[i].dis=pythagore(&data->rays[i].v,data->pos);
    }
    else
    {
        data->rays[i].cas = 0;
        data->rays[i].dis=pythagore(&data->rays[i].h,data->pos);
    }

    // note : rays-> or maybe // rays[i]
}

t_pos *find_wall(t_data *data,double angle)
{
    int x,y;
    t_pos *ret=malloc(sizeof(t_data));
    x=data->pos->x/70;
    y=data->pos->y/70;
    int h=1;
    if (h)
    {
        x += tan(angle) * 35;
        y++;
        while ( x < 24 && y < 12 && x>=0 && y>=0 && data->s[y][x]!='1')
        {
            x += tan(angle)* 70;
            // printf("angle %ftan %f\n", angle, tan(angle)*70);
            y++;
        }
    }
    else
    {
        while(data->s[x][y]!='1')
        {
            y += tan(angle) * x;
        }
    }
    ret->x=x;
    ret->y=y;
    return ret;
}

double distance(t_data *data, double angle,int i)
{
    double distance;
    // t_pos *pos=find_wall(data,angle);

    which_way(data,angle,i);
    // distance = pythagore(pos,data->pos);
    // free(pos);
    // printf("distance =%f\n",distance);
    // distance=1;
    return (data->rays[i].dis);
}



    // if (angle >= (3 *pi)/2 && angle <= 2*pi)
    // {
    //     data->rays[i].h.y = floor(data->pos->y/70) * 70  - 0.00001;
    //     data->rays[i].h.x = data->pos->x + fabs((data->pos->y - data->rays[i].h.y)/tan(angle));
    //         x=data->rays[i].h.x/70;
    //         y=data->rays[i].h.y/70;
    //     while(x >= 0 && y >= 0 && y <= 11 && x <= 24 && data->s[y][x]!='1')
    //     {
    //        // printf("y = %d\n", tan(angle) );
    //         data->rays[i].h.y -= 70;
    //         data->rays[i].h.x +=  fabs(70/tan(angle));
    //         x=data->rays[i].h.x/70;
    //         y=data->rays[i].h.y/70;
    //     }
    //         // data->rays[i].v.x = floor(data->pos->x/70) * 70  + 70;
    //         // data->rays[i].v.y = data->pos->y - fabs((data->pos->x - data->rays[i].v.x)* tan(angle)); 
    // }