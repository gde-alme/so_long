/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:29:29 by gde-alme          #+#    #+#             */
/*   Updated: 2022/09/12 17:02:20 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	border_map(t_frame *frame)
{
	char	**map;
	int		i;

	map = frame->map;
	i = 0;
	while (map[0][i] != '\0')
	{
		if (map[0][i] != '1')
			close_game(frame, 1);
		i++;
	}
	i = 0;
	while (map[frame->win_h - 1][i] != '\0')
	{
		if (map[frame->win_h - 1][i] != '1')
			close_game(frame, 1);
		i++;
	}
	i = 0;
	while (i < frame->win_h)
	{
		if (map[i][0] != '1' || map[i][frame->win_w - 1] != '1')
			close_game(frame, 1);
		i++;
	}
}

void	lines_map(t_frame *frame)
{
	int	i;

	i = 0;
	while (i < frame->win_h)
	{
		if (ft_strlen(frame->map[i]) != frame->win_w)
			close_game(frame, 1);
		i++;
	}
}

int	compo_map(t_frame *frame, char compo)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (i < frame->win_h)
	{
		j = 0;
		while (j < frame->win_w)
		{
			if (frame->map[i][j] == compo)
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

void	parse_map(t_frame *frame)
{
	frame->win_w = ft_strlen(frame->map[0]);
	lines_map(frame);
	border_map(frame);
	if (frame->win_w <= frame->win_h)
		close_game(frame, 1);
	if (compo_map(frame, 'E') != 1 || compo_map(frame, 'C') < 1
		|| compo_map(frame, 'P') != 1 || check_bad_input(frame) != 0)
	{
		close_game(frame, 1);
	}
}

void	read_map(t_frame *frame, char *pathname)
{
	char	*line;
	char	**map;
	int		fd;
	int		i;

	fd = open(pathname, O_RDONLY);
	frame->win_h = ft_count_lines(pathname);
	line = get_next_line(fd);
	map = (char **)malloc(sizeof(char *) * (frame->win_h + 1));
	i = 0;
	while (i < frame->win_h)
	{
		map[i] = ft_substr(line, 0, ft_strlen(line) - 1);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = 0;
	close(fd);
	frame->map = map;
	parse_map(frame);
}
