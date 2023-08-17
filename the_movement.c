/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 08:19:44 by aatki             #+#    #+#             */
/*   Updated: 2023/08/17 19:37:22 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int *position(char **s)
{
	int i;

	i=0;
    int j;
    int *tab=malloc(2);
	if (!s)
		return 0;
	while (s[i])
	{
        j=0;
        while(s[i][j])
        {
            if (s[i][j] == 'N')
            {
                tab[0]=i;
                tab[1]=j;
			    return (NULL);
            }
            j++;
        }
		i++;
	}
	return (NULL);
}

void	carree(t_data *data,int k,int d)
{
	int harf = 70;
	int i=0;
	int j;

	while(i < harf)
	{
		j=0;
		while (j < harf)
		{
			mlx_pixel_put(data->mlx,data->window,d+i,k+j,0xFFFFFF);
			j++;
		}
		i++;
	}
}

void	hook_in_pink(int *tab,int *tab2,t_data *data)
{
    carree(data,0, 0);
    // if (data->s[tab2[0]][tab2[1]] == '0')
    // {
        // data->s[0][0]= '1';
        // data->s[tab2[0]][tab2[1]]='N';
    // }
//    affiche(data);
}

int	new_position(int key, t_data *data)
{
	int *tab;
    //  = position(data->s);
    int *tab2=malloc(2);
	if (key == 53)
		exit(0);
	if (key == 65362)
    {
        tab2[0]=tab[0]-1;
        tab2[1]=tab[1];
		hook_in_pink(tab, tab2,data);
    }
	if (key == 65363)
    {
        tab2[0]=tab[0];
        tab2[1]=tab[1]+1;
		hook_in_pink(tab, tab2,data);
    }
    if (key == 65364)
	{
        tab2[0]=tab[0]+1;
        tab2[1]=tab[1];
		hook_in_pink(tab, tab2,data);
    }
	if (key == 65361)
	{
        tab2[0]=tab[0];
        tab2[1]=tab[1]-1;
		hook_in_pink(tab, tab2,data);
    }
	return 1;
}
