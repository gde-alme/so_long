/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:29:29 by gde-alme          #+#    #+#             */
/*   Updated: 2022/09/12 16:59:11 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_window(t_frame *frame)
{
	close_game(frame, 0);
	return (0);
}

t_frame	*create_frame(t_frame *frame)
{
	frame = (t_frame *)malloc(sizeof(t_frame));
	frame->mvs = 0;
	frame->pos_x = 0;
	frame->pos_y = 0;
	frame->win_h = 0;
	frame->win_w = 0;
	frame->map = NULL;
	return (frame);
}

void	set_imgs(t_frame *frame)
{
	frame->f.img = mlx_xpm_file_to_image \
	(frame->mlx, "./img/f.xpm", &frame->f.img_w, &frame->f.img_h);
	frame->w.img = mlx_xpm_file_to_image \
	(frame->mlx, "./img/w.xpm", &frame->w.img_w, &frame->w.img_h);
	frame->c_o.img = mlx_xpm_file_to_image \
	(frame->mlx, "./img/c_o.xpm", &frame->c_o.img_w, &frame->c_o.img_h);
	frame->c_c.img = mlx_xpm_file_to_image \
	(frame->mlx, "./img/c_c.xpm", &frame->c_c.img_w, &frame->c_c.img_h);
	frame->p.img = mlx_xpm_file_to_image \
	(frame->mlx, "./img/p.xpm", &frame->p.img_w, &frame->p.img_h);
	frame->e.img = mlx_xpm_file_to_image \
	(frame->mlx, "./img/e.xpm", &frame->e.img_w, &frame->e.img_h);
	frame->l.img = mlx_xpm_file_to_image \
	(frame->mlx, "./img/l.xpm", &frame->l.img_w, &frame->l.img_h);
}

int	main(int argc, char **argv)
{
	t_frame	*frame;

	if (argc != 2 || test_pathname(argv[1]) != 1)
		return (write(1, "Error:\n<NO SUCH FILE>\n", 22));
	frame = NULL;
	frame = create_frame(frame);
	read_map(frame, argv[1]);
	count_colec(frame);
	frame->mlx = mlx_init();
	frame->win = mlx_new_window \
	(frame->mlx, frame->win_w * 32, frame->win_h * 32, "so_long");
	set_imgs(frame);
	mlx_key_hook(frame->win, kboard_input, frame);
	mlx_hook(frame->win, 17, 0, destroy_window, frame);
	map_display(frame);
	mlx_loop(frame->mlx);
	return (0);
}
