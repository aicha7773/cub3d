/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 22:46:20 by aatki             #+#    #+#             */
/*   Updated: 2023/08/26 23:35:46 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	carre(t_data *data,int k,int d)
{
	int harf = 70;
	int i = 0;
	int j;

	while(i < harf)
	{
		j=0;
		while (j < harf)
		{
			my_mlx_pixel_put(data, d+i,k+j,0xFF5FFF);
			// mlx_pixel_put(data->mlx,data->window,d+i,k+j,0xFF5FFF);
			j++;
		}
		i++;
	}
}

void	put_ray(t_data *data,double angle,double dis)
{
	double x,y;
	x=data->pos->x;
	y=data->pos->y;
	while(dis > 0)
	{
		x+=cos(angle);
		y+=sin(angle);
		my_mlx_pixel_put(data, x, y, 0x00FF0000);
		dis--;
	}
}

void raycasting(t_data *data)
{
	int nbr=0;
	double angle=data->angle;
	int i=0;

	data->rays=malloc(sizeof(double) * 1280);
	put_ray(data,angle, distance(data,angle));
	while(nbr<640)
	{
		angle += 0.001;
		data->rays[i] = distance(data,angle);
    	put_ray(data,angle, data->rays[i]);
		nbr++;
		i++;
	}
	nbr=0;
	angle=data->angle;
	while(nbr<640)
	{
		angle -= 0.001;
		data->rays[i] = distance(data,angle);
    	put_ray(data,angle, data->rays[i]);
		nbr++;
		i++;
	}
}

void circle(t_data *data, int centerX, int centerY, int radius)
{
    int x, y;

    for (y = centerY - radius; y <= centerY + radius; y++)
    {
        for (x = centerX - radius; x <= centerX + radius; x++)
        {
            int dx = x - centerX;
            int dy = y - centerY;
            if (dx * dx + dy * dy <= radius * radius)
            {
				my_mlx_pixel_put(data, x, y, 0x00FF0000);
            }
        }
    }
	// put_ray(data,data->angle, distance(data,data->angle));
	raycasting(data);
}

void affiche(t_data *data)
{
	int i=0;
	int j=0;
	int x=0;
	int y=0;

	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
								&data->endian);
	while (data->s[i])
	{
		y = 0;
		j=0;
		while (data->s[i][j])
		{
			// printf("%c",data->s[i][j]);
			if (data->s[i][j] == '1')
				carre(data,x,y);
			y+=70;
			j++;
		}
		// printf("\n");
		i++;
		x+=70;
	}
	circle(data,data->pos->x,data->pos->y,10);
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
}
