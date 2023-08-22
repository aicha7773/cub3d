/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 22:46:20 by aatki             #+#    #+#             */
/*   Updated: 2023/08/22 11:04:39 by aatki            ###   ########.fr       */
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

void	put_rayon(t_data *data,int x, int y)
{
	int dis=0;
	while(dis < 70)
	{
		x+=cos(data->angle);
		y+=sin(data->angle);
		my_mlx_pixel_put(data, x, y, 0x00FF0000);
		dis++;
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
    put_rayon(data,centerX,centerY);
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
			printf("%c",data->s[i][j]);
			if (data->s[i][j] == 'N' || data->s[i][j] == 'S' || data->s[i][j] == 'E' || data->s[i][j] == 'W')
				circle(data,y+35,x+35,35);
			if (data->s[i][j] == '1')
				carre(data,x,y);
			y+=70;
			j++;
		}
		printf("\n");
		i++;
		x+=70;
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
}
