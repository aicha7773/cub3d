/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:00:06 by aatki             #+#    #+#             */
/*   Updated: 2023/08/17 19:31:40 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_exit(void)
{
	exit(0);
}

void	carre(t_data *data,int k,int d)
{
	int harf = 70;
	int i=0;
	int j;

	while(i < harf)
	{
		j=0;
		while (j < harf)
		{
			mlx_pixel_put(data->mlx,data->window,d+i,k+j,0xFF5FFF);
			j++;
		}
		i++;
	}
}

void draw_pixel(t_data *data, int x, int y)
{
    mlx_pixel_put(data->mlx, data->window, x, y, 0xFFFFFF);
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
                draw_pixel(data, x, y);
            }
        }
    }
}

void affiche(t_data *data)
{
	int i=0;
	int j=0;
	int x=0;
	int y=0;

	double pa;
	double pi = M_PI;
	while (data->s[i])
	{
		y = 0;
		j=0;
		while (data->s[i][j])
		{
			printf("%c",data->s[i][j]);
			if (data->s[i][j] == 'N')
			{
				pa=pi/2;
				circle(data,x+35,y+35,35);
			}
			else if( data->s[i][j] == 'S')
			{
				pa=3*pi;
				pa=pa/2;
				circle(data,x+35,y+35,35);
			}
			else if( data->s[i][j] == 'E')
			{
				pa=0;
				circle(data,x+35,y+35,35);
			}
			else if( data->s[i][j] == 'W')
			{
				pa=pi;
				circle(data,x+35,y+35,35);
			}
			if (data->s[i][j] == '1')
			{
				carre(data,x,y);
			}
			y+=70;
			j++;
		}
		printf("\n");
		i++;
		x+=70;
	}
}

char **allocateAndCopyStrings(char *s[]) {
    int numStrings = 11;
    char **allocatedStrings = (char **)malloc((numStrings + 1) * sizeof(char *));
    if (allocatedStrings == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    for (int i = 0; i < numStrings; i++) {
        allocatedStrings[i] = strdup(s[i]);
        if (allocatedStrings[i] == NULL) {
            perror("String duplication failed");
            exit(1);
        }
    }
    allocatedStrings[numStrings] = NULL;
    return allocatedStrings;
}

void	function(void)
{
	t_data *data=malloc(sizeof(t_data));
	char	*s[] = {
	"111111111111111111111",
	"11001110000000000011",
	"1100011000000001111",
	"1100011000001110000111",
	"1111110000000001111",
	"111110000000001111111",
	"111111000N000111111",
	"111111100000111111111",
	"110000000000000011111",
	"100000000000000011111111",
	"111111111111111111111",NULL};
	data->s=allocateAndCopyStrings(s);
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, 1280, 720, "Hello world!");
	affiche(data);
	mlx_key_hook (data->window , new_position, data->s);
	mlx_hook(data->window, 17, 0, ft_exit, NULL);
	mlx_loop(data->mlx);
}

int	main(void)
{
	function();
	return (0);
}
