/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:39:28 by lsadiq            #+#    #+#             */
/*   Updated: 2023/09/01 17:34:09 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*saver;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	saver = ft_read(fd, saver);
	if (!saver)
		return (NULL);
	line = get_the_line(saver);
	saver = the_rest(saver);
	return (line);
}

char	*ft_read(int fd, char *saver)
{
	char	*buff;
	int		reader;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	reader = 1;
	while (!ft_strchr(saver, '\n') && reader != 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
		{
			free(saver);
			free(buff);
			return (NULL);
		}
		buff[reader] = '\0';
		saver = ft_strjoin(saver, buff);
		if (!saver)
			return (NULL);
	}
	free(buff);
	return (saver);
}

char	*get_the_line(char *saver)
{
	int		i;
	char	*line;

	i = 0;
	if (!saver[0])
		return (NULL);
	while (saver[i] != '\n' && saver[i])
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (saver[i] != '\n' && saver[i])
	{
		line[i] = saver[i];
		i++;
	}
	if (saver[i] == '\n')
		line[i++] = '\0';
	line[i] = '\0';
	return (line);
}

char	*the_rest(char *saver)
{
	int i;
	char *tmp;

	i = 0;
	while (saver[i] != '\n' && saver[i])
		i++;
	if (!saver[i])
	{
		free(saver);
		return (NULL);
	}
	tmp = ft_substr(saver, i + 1, ft_strlen(saver) - i);
	free(saver);
	return (tmp);
}