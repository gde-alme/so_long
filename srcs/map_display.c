/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:29:29 by gde-alme          #+#    #+#             */
/*   Updated: 2022/07/20 16:05:37 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_player(t_frame *frame, int i, int j)
{
	frame->pos_x = i;
	frame->pos_y = j;
	mlx_put_image_to_window \
	(frame->mlx, frame->win, frame->p.img, j * 32, i * 32);
}

void	element_display(t_frame *frame, int i, int j)
{
	if (frame->map[i][j] == '1')
	{
		mlx_put_image_to_window \
		(frame->mlx, frame->win, frame->w.img, j * 32, i * 32);
	}
	else if (frame->map[i][j] == 'E')
	{
		mlx_put_image_to_window \
		(frame->mlx, frame->win, frame->e.img, j * 32, i * 32);
	}
	else if (frame->map[i][j] == 'P')
		display_player(frame, i, j);
	else if (frame->map[i][j] == 'C')
	{
		mlx_put_image_to_window \
		(frame->mlx, frame->win, frame->c_c.img, j * 32, i * 32);
	}
	else if (frame->map[i][j] == 'c')
	{
		mlx_put_image_to_window \
		(frame->mlx, frame->win, frame->c_o.img, j * 32, i * 32);
	}
}

void	map_display(t_frame *frame)
{
	int	i;
	int	j;

	mlx_put_image_to_window(frame->mlx, frame->win, frame->f.img, 0, 0);
	i = 0;
	while (i < frame->win_h)
	{
		j = 0;
		while (j < frame->win_w)
		{
			element_display(frame, i, j);
			j++;
		}
		i++;
	}
}
