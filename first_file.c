/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:00:06 by aatki             #+#    #+#             */
/*   Updated: 2023/08/14 00:18:48 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_exit(void)
{
	exit(0);
}

void	carre(void *mlx , void *window,int k,int d)
{

	int harf = 70;
	int i=0;
	int j;
	while(i < harf)
	{
		j=0;
		while (j < harf)
		{
			mlx_pixel_put(mlx,window,d+i,k+j,0xFF5FFF);
			j++;
		}
		i++;
	}
}

void	circle(void *mlx , void *window,int k,int d)
{

	int harf = 70;
	int i=0;
	int j;
	int c=35;
	carre(mlx,window,k,d);
	while(i < harf)
	{
		j=c;
		while (j < i+1)
		{
			mlx_pixel_put(mlx,window,d+i,k+j,0xFFFFFF);
			j++;
		}
		i++;
	}
}

void	function(void)
{
	char	*s[] = {"111111111111111111111", "11001110000000000011",
	"1100011000000001111", "1100011000001110000111","11111100000S0001111",
	"111110000000001111111", "111111000N000111111","111111100000111111111",
	"110000000000000011111","100000000000000011111111","111111111111111111111",NULL};
	int		i;
	void	*mlx;
	void	*window;
	int		count;
	int		j;
	void	*img;
	int x = 0;
	int y = 0;

	i = 0;
	double pa;
	double pi = M_PI;
	mlx = mlx_init();
	count = 200;
	// img = mlx_xpm_file_to_image(mlx, "jinx.xpm", &count,
	// 		&count);
	// mlx_put_image_to_window(mlx, window, img, i+200, j+200);
	window = mlx_new_window(mlx, 1280, 720, "Hello world!");
	//  carre(mlx,window,0,0);
	while (s[i])
	{
		y = 0;
		j=0;
		while (s[i][j])
		{
			printf("%c",s[i][j]);
			if (s[i][j] == 'N')
			{
				pa=pi/2;
				circle(mlx,window,x,y);
			}
			else if( s[i][j] == 'S')
			{
				pa=3*pi;
				pa=pa/2;
				circle(mlx,window,x,y);
			}
			else if( s[i][j] == 'E')
			{
				pa=0;
				circle(mlx,window,x,y);
			}
			else if( s[i][j] == 'W')
			{
				pa=pi;
				circle(mlx,window,x,y);
			}
			if (s[i][j] == '1')
			{
				carre(mlx,window,x,y);
				//  mlx_pixel_put(mlx,window,i,j,0xFFFFFF);
				// 	printf("j\n");
			}
			y+=70;
			j++;
		}
		printf("\n");
		i++;
		x+=70;
	}
	mlx_hook(window, 17, 0, ft_exit, NULL);
	mlx_loop(mlx);
}

int	main(void)
{
	function();
	return (0);
}

