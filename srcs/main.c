/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:29:29 by gde-alme          #+#    #+#             */
/*   Updated: 2022/06/18 17:44:59 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_frame {
	void	*mlx;
	void	*win;
	int	mvs;
	int	pos_x;
	int	pos_y;
}	t_frame;

typedef struct s_img {
	void	*img;
	int	img_w;
	int	img_h;
}	t_img;

void	close_game(t_frame *frame)
{
	//mlx_destroy_window(frame->mlx, frame->win);
	exit(-1);
}

int	mouse_input(int button, int x, int y, t_frame *frame)
{
	close_game(frame);
	return (0);
}

int	kboard_input(int keycode, t_frame *frame)
{
	if (keycode == 65307)
		close_game(frame);
	else if (keycode == KEY_W)
		frame->pos_y += 1;
	else if (keycode == KEY_A)
		frame->pos_x -= 1;
	else if (keycode == KEY_S)
		frame->pos_y -= 1;
	else if (keycode == KEY_D)
		frame->pos_x += 1;
	return (0);
}

t_frame	*create_frame(t_frame *frame)
{
	frame = (t_frame *)malloc(sizeof(t_frame));
	frame->mlx = mlx_init();
	frame->win = mlx_new_window(frame->mlx, 100, 50, "sigasiga");
	frame->mvs = 0;
	frame->pos_x = 0;
	frame->pos_y = 0;
	return (frame);
}

int	main(void)
{
	t_frame	*frame;
	//t_img	land;
	t_img	wall;
	t_img	chest_c;

	frame = NULL;
	frame = create_frame(frame);

	mlx_hook(frame->win, 2, 1L<<0, kboard_input, frame); //key_input
	mlx_hook(frame->win, 17, 0, mouse_input, frame); //mouse_input
	
	//land.img = mlx_xpm_file_to_image(frame->mlx, "./images/grass.xpm", &land.img_w, &land.img_h);
	//mlx_put_image_to_window(frame->mlx, frame->win, land.img, 0 , 0);

	chest_c.img = mlx_xpm_file_to_image(frame->mlx, "./images/chest_closed.xpm", &chest_c.img_w, &chest_c.img_h);
	mlx_put_image_to_window(frame->mlx, frame->win, chest_c.img, frame->pos_x + 35, frame->pos_y);

	wall.img = mlx_xpm_file_to_image(frame->mlx, "./images/wall.xpm", &wall.img_w, &wall.img_h);
	mlx_put_image_to_window(frame->mlx, frame->win, wall.img, frame->pos_x, frame->pos_y);

	mlx_loop(frame->mlx);

	return (0);
}
