/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:00:06 by aatki             #+#    #+#             */
/*   Updated: 2023/08/12 01:43:22 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_exit()
{
	exit(0);
}

void function()
{
    char    *s="1111100111011111";
    int     i=0;
    void    *mlx;
	void	*window;
    int     count;
	void	*imgh;

    mlx=mlx_init();
    count = 0;
    window = mlx_new_window(mlx, 800, 600, "Hello world!");
    while(s[i])
    {
        if(s[i] == '1')
        {
            count++;
	        mlx_pixel_put(mlx, window, 400 * count, 300, 0xFF5FFF);
        }
        i++;
    }
    mlx_hook(window, 17, 0, ft_exit, NULL);
    mlx_loop(mlx);
}

int main()
{
    function();
    return 0;
}
