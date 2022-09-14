/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:29:29 by gde-alme          #+#    #+#             */
/*   Updated: 2022/09/12 16:53:02 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_frame *frame)
{
	int	i;

	i = 0;
	while (i <= frame->win_h)
	{
		free(frame->map[i]);
		i++;
	}
	free(frame->map);
}

void	free_frame(t_frame *frame, int error)
{
	if (error == 0)
	{
		mlx_destroy_window(frame->mlx, frame->win);
		mlx_destroy_image(frame->mlx, frame->w.img);
		mlx_destroy_image(frame->mlx, frame->f.img);
		mlx_destroy_image(frame->mlx, frame->c_o.img);
		mlx_destroy_image(frame->mlx, frame->c_c.img);
		mlx_destroy_image(frame->mlx, frame->l.img);
		mlx_destroy_image(frame->mlx, frame->e.img);
		mlx_destroy_image(frame->mlx, frame->p.img);
	}
	free(frame);
}

void	close_game(t_frame *frame, int error)
{
	free_map(frame);
	free_frame(frame, error);
	if (error > 0)
	{
		error = write(2, "Error\n", 6);
		error = write(2, "check map input\n", 16);
	}
	exit(-1);
}
