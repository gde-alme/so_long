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

void	close_game(t_frame *frame)
{
	//int	j;
	char	**map;

	//mlx_destroy_window(frame->mlx, frame->win);
	map = frame->map;
	//printf("%s", map[1]);
	/*j = frame->win_w;
	while (j-- > 0)
		free(map[j]);
	free(map);*/
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
	frame->win = mlx_new_window(frame->mlx, 145, 75, "sigasiga");
	frame->mvs = 0;
	frame->pos_x = 0;
	frame->pos_y = 0;
	frame->map = NULL;
	frame->win_h = 0;
	return (frame);
}

int	main(int argc, char **argv)
{
	t_frame	*frame;
	t_img	land;
	t_img	wall;
	t_img	chest_c;
	t_img	chest_o;
	t_img	end;
	t_img	player;

	if (argc != 2)
		return (0);

	frame = NULL;
	frame = create_frame(frame);

	mlx_hook(frame->win, 2, 1L<<0, kboard_input, frame); //key_input
	mlx_hook(frame->win, 17, 0, mouse_input, frame); //mouse_input
	
	land.img = mlx_xpm_file_to_image(frame->mlx, "./images/land.xpm", &land.img_w, &land.img_h);
	mlx_put_image_to_window(frame->mlx, frame->win, land.img, 0, 35);

	chest_c.img = mlx_xpm_file_to_image(frame->mlx, "./images/chest_closed.xpm", &chest_c.img_w, &chest_c.img_h);
	mlx_put_image_to_window(frame->mlx, frame->win, chest_c.img, 35, 0);

	chest_o.img = mlx_xpm_file_to_image(frame->mlx, "./images/chest_open.xpm", &chest_o.img_w, &chest_o.img_h);
	mlx_put_image_to_window(frame->mlx, frame->win, chest_o.img, 70, 0);

	wall.img = mlx_xpm_file_to_image(frame->mlx, "./images/wall.xpm", &wall.img_w, &wall.img_h);
	mlx_put_image_to_window(frame->mlx, frame->win, wall.img, 0 , 0);

	end.img = mlx_xpm_file_to_image(frame->mlx, "./images/end.xpm", &end.img_w, &end.img_h);
	mlx_put_image_to_window(frame->mlx, frame->win, end.img, 105, 0);

	player.img = mlx_xpm_file_to_image(frame->mlx, "./images/player.xpm", &player.img_w, &player.img_h);
	mlx_put_image_to_window(frame->mlx, frame->win, player.img, 105, 35);

	frame->map = parse_map(frame, argv);
	printf("%s", frame->map[1]);
	mlx_loop(frame->mlx);

	return (0);
}
