/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:21:01 by aatki             #+#    #+#             */
/*   Updated: 2023/09/02 15:32:17 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

int	main(void)
{
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
	char **str = allocateAndCopyStrings(s);
	transmitter(str,24,11);
	return (0);
}
