/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:00:06 by aatki             #+#    #+#             */
/*   Updated: 2023/09/01 19:08:57 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	initialize(t_data *data)
{
	data->pos = position(data->s);
	data->rays = malloc(sizeof(t_rays) * 1280);
	data->keys.w = 0;
	data->keys.d = 0;
	data->keys.s = 0;
	data->keys.a = 0;
	data->keys.left = 0;
	data->keys.right = 0;
	data->pi = M_PI;
	initialize_angle(data);
}

char	**allocateAndCopyStrings(char *s[])
{
	int		numStrings;
	char	**allocatedStrings;

	numStrings = 11;
	allocatedStrings = (char **)malloc((numStrings + 1) * sizeof(char *));
	if (allocatedStrings == NULL)
	{
		perror("Memory allocation failed");
		exit(1);
	}
	for (int i = 0; i < numStrings; i++)
	{
		allocatedStrings[i] = strdup(s[i]);
		if (allocatedStrings[i] == NULL)
		{
			perror("String duplication failed");
			exit(1);
		}
	}
	allocatedStrings[numStrings] = NULL;
	return (allocatedStrings);
}

void	main_function(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	char *s[] = {
		"111111111111111111111   ",
		"11001110000000000011    ",
		"11000110000000001111    ",
		"1100011000001110000111  ",
		"1111110000000001111     ",
		"111110000N00001111111   ",
		"111111000000111111      ",
		"111111100000111111111   ",
		"110000000000000011111   ",
		"10000000000000011111111 ",
		"111111111111111111111   ",
		NULL};
	data->s = allocateAndCopyStrings(s);
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, 1280, 720, "Hello world!");
	data->img = mlx_new_image(data->mlx, 1280, 720);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	initialize(data);
	affiche(data);
	mlx_hook(data->window, 03, 1L << 1, key_up, data);
	mlx_hook(data->window, 02, 1L << 0, key_down, data);
	mlx_hook(data->window, 17, 0, ft_exit, NULL);
	mlx_loop_hook(data->mlx, check_key, data);
	mlx_loop(data->mlx);
}

int	main(void)
{
	main_function();
	return (0);
}
