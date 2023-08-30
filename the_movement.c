/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 08:19:44 by aatki             #+#    #+#             */
/*   Updated: 2023/08/30 19:06:10 by aatki            ###   ########.fr       */
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
                pos->y=i * 70;
                pos->x=j * 70;
			    return (pos);
            }
            j++;
        }
		i++;
	}
	return (NULL);
}

void	hook_in_pink(t_pos *new, t_data *data)
{
    if (data->s[(int)new->x][(int)new->y] != '1')
    {
        data->s[(int)data->pos->x][(int)data->pos->y]= '0';
        data->s[(int)new->x][(int)new->y]='S';
    }
   affiche(data);
}

void	translation(t_data *data,t_pos pos)
{
	if (data->s[(int)pos.y/70][(int)pos.x/70] != '1')
	{
		data->pos->x = pos.x;
		data->pos->y = pos.y;
		mlx_destroy_image(data->mlx,data->img);
		affiche(data);
	}
}

void	rotation(t_data *data)
{
	double	pi;

	pi = M_PI;
	if (data->keys.right == 1)//right
		data->angle+=pi/100;
	else if (data->keys.left == 1)//left
		data->angle-=pi/100;
	//
	if (data->angle > 2 *pi)
		data->angle-=2*pi;
	if (data->angle < 2 *pi)
		data->angle+=2*pi;
	mlx_destroy_image(data->mlx,data->img);
	affiche(data);
}

void	new_position(t_data *data)
{
	t_pos pos;

	if (data->keys.w)//w
    {
		pos.x = data->pos->x + cos(data->angle);
		pos.y = data->pos->y + sin(data->angle);
    } 
	else if (data->keys.s)//s
	{
		pos.x = data->pos->x - cos(data->angle);
		pos.y = data->pos->y - sin(data->angle);
    }
	if (data->keys.d)//d
    {
		pos.x = data->pos->x + sin(data->angle);
		pos.y = data->pos->y + cos(data->angle);
    }
	else if (data->keys.a)//a
	{
		pos.x =data->pos->x - sin(data->angle);
		pos.y = data->pos->y - cos(data->angle);
    }
	if (data->keys.w || data->keys.d || data->keys.a || data->keys.s)
		translation(data,pos);
	if (data->keys.left || data->keys.right)
		rotation(data);
}

int key_down(int key,t_data *data)
{
	if (key == 65307)
		exit(0);
	if (key == 119)//W
		data->keys.w = 1;
	if (key == 100)//d
		data->keys.d = 1;
	if (key == 115)//s
		data->keys.s = 1;
    if (key == 97)//a
		data->keys.a = 1;
	if (key == 65363)//right
		data->keys.right = 1;
	if (key == 65361)//left
		data->keys.left = 1;
	return 1;
}

int key_up(int key,t_data *data)
{
	if (key == 119)//W
		data->keys.w = 0;
	if (key == 100)//d
		data->keys.d = 0;
	if (key == 115)//s
		data->keys.s = 0;
    if (key == 97)//a
		data->keys.a = 0;
	if (key == 65363)//right
		data->keys.right = 0;
	if (key == 65361)//left
		data->keys.left = 0;
	return 1;
}

int check_key(t_data *data)
{
	static int frames = 0;

	if (frames % 500 == 0 || (data->keys.w || data->keys.d || data->keys.a || data->keys.s || data->keys.left || data->keys.right))
		new_position(data);
	frames++;
	return (1);
}
