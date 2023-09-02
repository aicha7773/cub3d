/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:37:36 by aatki             #+#    #+#             */
/*   Updated: 2023/09/01 19:14:27 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	pythagore(t_pos *s, t_pos *d)
{
	return (sqrt(pow(s->x - (d->x), 2) + pow(s->y - (d->y), 2)));
}

double	thales(double a, double b, double c)
{
	return ((c / a) * b);
}
