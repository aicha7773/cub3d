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

void	function(void)
{
	char	*s[] = {"1111", "1001", "1101", "1111",NULL};
	int		i;
	void	*mlx;
	void	*window;
	int		count;
	int		j;
	void	*img;

	j = 0;
	i = 0;
	mlx = mlx_init();
	count = 200;
	img = mlx_xpm_file_to_image(mlx, "jinx.xpm", &count,
			&count);
	window = mlx_new_window(mlx, 800, 600, "Hello world!");
	while (s[i])
	{
		while (s[i][j])
		{
			if (s[i][j] == '1')
			{
            	printf("kkkkkkkk%c\n",s[i][j]);
				mlx_pixel_put(mlx,window,i,j,0xFF5FFF);
				// mlx_put_image_to_window(mlx, window, img, i+200, j+200);
			}
			j++;
		}
		i++;
	}
	mlx_hook(window, 17, 0, ft_exit, NULL);
	mlx_loop(mlx);
}

int	main(void)
{
	function();
	return (0);
}
