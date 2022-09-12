/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:29:29 by gde-alme          #+#    #+#             */
/*   Updated: 2022/09/12 16:53:38 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_w(t_frame *frame)
{
	char	**map;
	int		pos_x;
	int		pos_y;

	map = frame->map;
	pos_x = frame->pos_x;
	pos_y = frame->pos_y;
	if (map[pos_x - 1][pos_y] == 'E' && count_colec(frame) == 0)
		close_game(frame, 0);
	else if (map[pos_x - 1][pos_y] == '0')
	{
		frame->pos_x -= 1;
		mlx_clear_window(frame->mlx, frame->win);
		map[pos_x - 1][pos_y] = 'P';
		map[pos_x][pos_y] = '0';
		map_display(frame);
		ft_putmvs(frame);
	}
	else if (map[pos_x -1][pos_y] == 'C')
	{
		mlx_clear_window(frame->mlx, frame->win);
		map[pos_x - 1][pos_y] = 'c';
		map_display(frame);
		ft_putmvs(frame);
	}
}

void	move_s(t_frame *frame)
{
	char	**map;
	int		pos_x;
	int		pos_y;

	map = frame->map;
	pos_x = frame->pos_x;
	pos_y = frame->pos_y;
	if (map[pos_x + 1][pos_y] == 'E' && count_colec(frame) == 0)
		close_game(frame, 0);
	else if (map[pos_x + 1][pos_y] == '0')
	{
		frame->pos_x += 1;
		mlx_clear_window(frame->mlx, frame->win);
		map[pos_x + 1][pos_y] = 'P';
		map[pos_x][pos_y] = '0';
		map_display(frame);
		ft_putmvs(frame);
	}
	else if (map[pos_x + 1][pos_y] == 'C')
	{
		mlx_clear_window(frame->mlx, frame->win);
		map[pos_x + 1][pos_y] = 'c';
		map_display(frame);
		ft_putmvs(frame);
	}
}

void	move_a(t_frame *frame)
{
	char	**map;
	int		pos_x;
	int		pos_y;

	map = frame->map;
	pos_x = frame->pos_x;
	pos_y = frame->pos_y;
	if (map[pos_x][pos_y - 1] == 'E' && count_colec(frame) == 0)
		close_game(frame, 0);
	else if (map[pos_x][pos_y - 1] == '0')
	{
		frame->pos_y -= 1;
		mlx_clear_window(frame->mlx, frame->win);
		map[pos_x][pos_y - 1] = 'P';
		map[pos_x][pos_y] = '0';
		map_display(frame);
		ft_putmvs(frame);
	}
	else if (map[pos_x][pos_y - 1] == 'C')
	{
		mlx_clear_window(frame->mlx, frame->win);
		map[pos_x][pos_y - 1] = 'c';
		map_display(frame);
		ft_putmvs(frame);
	}
}

void	move_d(t_frame *frame)
{
	char	**map;
	int		pos_x;
	int		pos_y;

	map = frame->map;
	pos_x = frame->pos_x;
	pos_y = frame->pos_y;
	if (map[pos_x][pos_y + 1] == 'E' && count_colec(frame) == 0)
		close_game(frame, 0);
	else if (map[pos_x][pos_y + 1] == '0')
	{
		frame->pos_y += 1;
		mlx_clear_window(frame->mlx, frame->win);
		map[pos_x][pos_y + 1] = 'P';
		map[pos_x][pos_y] = '0';
		map_display(frame);
		ft_putmvs(frame);
	}
	else if (map[pos_x][pos_y + 1] == 'C')
	{
		mlx_clear_window(frame->mlx, frame->win);
		map[pos_x][pos_y + 1] = 'c';
		map_display(frame);
		ft_putmvs(frame);
	}
}

int	kboard_input(int keycode, t_frame *frame)
{
	if (keycode == 65307)
		close_game(frame, 0);
	else if (keycode == KEY_W)
		move_w(frame);
	else if (keycode == KEY_A)
		move_a(frame);
	else if (keycode == KEY_S)
		move_s(frame);
	else if (keycode == KEY_D)
		move_d(frame);
	return (0);
}
