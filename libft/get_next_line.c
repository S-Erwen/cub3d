/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 22:11:41 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 04:03:34 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		after_endl(char **save, char **line)
{
	int		size;
	char	*temp;

	if (!ft_strchr_gnl(*save, '\n'))
	{
		*line = ft_strdup_gnl(*save);
		free(*save);
		*save = NULL;
		return (0);
	}
	size = (int)(ft_strchr_gnl(*save, '\n') - *save);
	*line = ft_substr_gnl(*save, 0, size);
	temp = ft_strdup_gnl(*save + size + 1);
	if (*save)
		free(*save);
	*save = ft_strdup_gnl(temp);
	if (temp)
		free(temp);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*save;
	char		*temp;
	char		buffer[BUFFER_SIZE + 1];
	int			readed;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
		return (-1);
	if (!save)
		save = ft_strdup_gnl("");
	while (!ft_strchr_gnl(save, '\n')
		&& (readed = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[readed] = '\0';
		temp = ft_strjoin_gnl(save, buffer);
		free(save);
		save = ft_strdup_gnl(temp);
		free(temp);
	}
	return (after_endl(&save, line));
}
