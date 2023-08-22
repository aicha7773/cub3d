/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:00:06 by aatki             #+#    #+#             */
/*   Updated: 2023/08/22 15:53:35 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_exit(void)
{
	exit(0);
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

void initialize(t_data *data)
{
	int i=0;
	int j=0;
	double	pi;

	pi = M_PI;
	data->pos=position(data->s);
	while (data->s[i])
	{
		j=0;
		while (data->s[i][j])
		{
			if (data->s[i][j] == 'N')
			{
				data->angle=3*pi;
				data->angle=data->angle / 2;
			}
			else if( data->s[i][j] == 'S')
				data->angle=pi / 2;
			else if( data->s[i][j] == 'E')
				data->angle = 0;
			else if( data->s[i][j] == 'W')
				data->angle=pi;
			j++;
		}
		i++;
	}
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
	"111111000S000111111",
	"111111100000111111111",
	"110000000000000011111",
	"100000000000000011111111",
	"111111111111111111111",NULL};
	data->s=allocateAndCopyStrings(s);
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, 1280, 720, "Hello world!");
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
								&data->endian);
	initialize(data);
	affiche(data);
	mlx_key_hook (data->window , new_position, data);
	mlx_hook(data->window, 17, 0, ft_exit, NULL);
	mlx_loop(data->mlx);
}

int	main(void)
{
	function();
	return (0);
}
