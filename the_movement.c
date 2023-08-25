/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 08:19:44 by aatki             #+#    #+#             */
/*   Updated: 2023/08/25 19:30:56 by aatki            ###   ########.fr       */
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
            if (s[i][j] == 'S' ||s[i][j] == 'N' ||s[i][j] == 'E' ||s[i][j] == 'W')
            {
                pos->y=i*70;
                pos->x=j * 70;
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
	double	pi;
	double x,y;

	pi = M_PI;
	printf("%f\n",data->angle);
	if (key == 65307)
		exit(0);
	if (key == 65362)
    {
		x = data->pos->x + (cos(data->angle) * 1.3);
		y = data->pos->y + (sin(data->angle) * 1.3);
		if (data->s[(int)y/70][(int)x/70] != '1')
		{
			mlx_destroy_image(data->mlx,data->img);
			data->pos->x = x;
			data->pos->y = y;
			affiche(data);
		}
    }
	if (key == 65363)
    {
		x = data->pos->x + (sin(data->angle)* 1.3);
		y = data->pos->y + (cos(data->angle)* 1.3);
		if (data->s[(int)y/70][(int)x/70] != '1')
		{
			mlx_destroy_image(data->mlx,data->img);
			data->pos->x = x;
			data->pos->y = y;
			affiche(data);
		}
    }
    if (key == 65364)
	{
		x = data->pos->x - (cos(data->angle)* 1.3);
		y = data->pos->y - (sin(data->angle)* 1.3);
		if (data->s[(int)y/70][(int)x/70] != '1')
		{
			mlx_destroy_image(data->mlx,data->img);
			data->pos->x = x;
			data->pos->y = y;
			affiche(data);
		}
    }
	if (key == 65361)
	{
		x = data->pos->x - (sin(data->angle)* 1.3);
		y = data->pos->y - (cos(data->angle)* 1.3);
		if (data->s[(int)y/70][(int)x/70] != '1')
		{
			mlx_destroy_image(data->mlx,data->img);
			data->pos->x = x;
			data->pos->y = y;
			affiche(data);
		}
    }
	if (key == 119)//W
	{
		data->angle+=0.2;
		if (data->angle > 2 *pi)
			data->angle-=2*pi;
		affiche(data);
	}
	if (key == 115)//s
	{
		data->angle-=pi/8;
		if (data->angle < 2 *pi)
			data->angle+=2*pi;
		affiche(data);
	}
	// if (key == 100)//d
	// if (key == 97)//a
	return 1;
}
