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
	printf("cl_gm\n");
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
	t_img	player;

	if (argc != 2)
		return (0);

	frame = NULL;
	frame = create_frame(frame);

	parse_map(frame, argv);
	/*frame->mlx = mlx_init();
	frame->win = mlx_new_window(frame->mlx, 145, 75, "sigasiga");

	mlx_hook(frame->win, 2, 1L<<0, kboard_input, frame); //key_input
	mlx_hook(frame->win, 17, 0, mouse_input, frame); //mouse_input
	
	player.img = mlx_xpm_file_to_image(frame->mlx, "./images/player.xpm", &player.img_w, &player.img_h);
	mlx_put_image_to_window(frame->mlx, frame->win, player.img, 105, 35);

	mlx_loop(frame->mlx);
	*/
	return (0);
}
