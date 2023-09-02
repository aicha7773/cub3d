/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:13:47 by aatki             #+#    #+#             */
/*   Updated: 2023/09/01 18:15:51 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_down(int key, t_data *data)
{
	if (key == 65307)
		exit(0);
	if (key == 119) //W
		data->keys.w = 1;
	if (key == 100) //d
		data->keys.d = 1;
	if (key == 115) //s
		data->keys.s = 1;
	if (key == 97) //a
		data->keys.a = 1;
	if (key == 65363) //right
		data->keys.right = 1;
	if (key == 65361) //left
		data->keys.left = 1;
	return (1);
}

int	key_up(int key, t_data *data)
{
	if (key == 119) //W
		data->keys.w = 0;
	if (key == 100) //d
		data->keys.d = 0;
	if (key == 115) //s
		data->keys.s = 0;
	if (key == 97) //a
		data->keys.a = 0;
	if (key == 65363) //right
		data->keys.right = 0;
	if (key == 65361) //left
		data->keys.left = 0;
	return (1);
}
