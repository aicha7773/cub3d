/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 08:19:44 by aatki             #+#    #+#             */
/*   Updated: 2023/08/22 18:06:33 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_pos *position(char **s)
{
	int i;

	i=0;
    int j;
    t_pos *pos=malloc(sizeof(t_pos));
	if (!s)
		return (0);
	while (s[i])
	{
        j=0;
        while(s[i][j])
        {
            if (s[i][j] == 'S')
            {
                pos->x=i;
                pos->y=j;
			    return (pos);
            }
            j++;
        }
		i++;
	}
	return (NULL);
}

void	carree(t_data *data,int k,int d)
{
	int harf = 70;
	int i=0;
	int j;

	while(i < harf)
	{
		j=0;
		while (j < harf)
		{
			mlx_pixel_put(data->mlx,data->window,d+i,k+j,0xFFF33F);
			j++;
		}
		i++;
	}
}

void	hook_in_pink(t_pos *new, t_data *data)
{
    if (data->s[(int)new->x][(int)new->y] != '1')
    {
		// printf("jjjjj\njjj\njjj\n");
        data->s[(int)data->pos->x][(int)data->pos->y]= '0';
        data->s[(int)new->x][(int)new->y]='S';
    }
   affiche(data);
}

int	new_position(int key, t_data *data)
{
    t_pos *new;
	new=malloc(sizeof(t_pos));
	data->pos=position(data->s);
	new->x=data->pos->x;
	new->y=data->pos->y;
	if (key == 65307)
		exit(0);
	if (key == 65362)
    {
        // new->x=data->pos->x-1;
        // new->y=data->pos->y;
		new->x -= cos(data->angle);
		new->y -= sin(data->angle);
		printf("fx=%f  fy=%f x=%f y=%f angle =%f\n\n" ,data->pos->x,data->pos->y, new->x , new->y,data->angle );
		hook_in_pink(new,data);
    }
	if (key == 65363)
    {
		mlx_clear_window(data->mlx,data->window);
        new->x -= cos(data->angle);
		new->y += sin(data->angle);
		hook_in_pink(new,data);
    }
    if (key == 65364)
	{
		mlx_clear_window(data->mlx,data->window);
		new->x += cos(data->angle);
		new->y += sin(data->angle);
		hook_in_pink(new,data);
    }
	if (key == 65361)
	{
		mlx_clear_window(data->mlx,data->window);
       	new->x += cos(data->angle);
		new->y -= sin(data->angle);
		hook_in_pink(new,data);
    }
	if (key == 119)//W
	{
		data->angle+=2;
		hook_in_pink(new,data);
	}
	if (key == 115)//s
	{
		data->angle-=2;
		hook_in_pink(new,data);
	}
	// if (key == 100)//d
	// if (key == 97)//a
	return 1;
}
