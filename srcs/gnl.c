/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:29:29 by gde-alme          #+#    #+#             */
/*   Updated: 2022/07/20 14:03:05 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_nextline(char **save)
{
	int		i;
	char	*tmp;
	char	*nl;

	i = 0;
	while ((*save)[i] != '\n' && (*save)[i] != '\0')
		i++;
	if ((*save)[i] == '\n' && (*save)[i + 1] != '\0')
	{
		nl = ft_substr(*save, 0, i + 1);
		tmp = ft_strdup(&((*save)[i + 1]));
		free(*save);
		*save = tmp;
	}
	else
	{
		nl = ft_strdup(*save);
		free(*save);
		*save = NULL;
	}
	return (nl);
}

char	*ft_nl(int fd, char **save)
{
	int		r;
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;

	r = read(fd, buff, BUFFER_SIZE);
	while (r > 0)
	{
		buff[r] = '\0';
		if (save[fd] == NULL)
			save[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(save[fd], buff);
			free(save[fd]);
			save[fd] = tmp;
		}
		if (ft_strchr(save[fd], '\n'))
			return (ft_nextline(&save[fd]));
		r = read(fd, buff, BUFFER_SIZE);
	}
	if (r <= 0 && save[fd] == NULL)
		return (NULL);
	return (ft_nextline(&save[fd]));
}

char	*get_next_line(int fd)
{
	static char	*save[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	return (ft_nl(fd, save));
}
