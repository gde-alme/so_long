/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:23:39 by gde-alme          #+#    #+#             */
/*   Updated: 2022/09/12 17:01:55 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define BUFFER_SIZE 42

typedef struct s_img {
	void	*img;
	int		img_w;
	int		img_h;
}	t_img;

typedef struct s_frame {
	struct s_img	w;
	struct s_img	f;
	struct s_img	c_o;
	struct s_img	c_c;
	struct s_img	p;
	struct s_img	e;
	struct s_img	l;
	void			*mlx;
	void			*win;
	int				mvs;
	int				pos_x;
	int				pos_y;
	char			**map;
	int				win_h;
	int				win_w;
}	t_frame;

void	read_map(t_frame *frame, char *pathname);
int		ft_count_lines(char *path_to_file);
void	map_display(t_frame *frame);
int		kboard_input(int keykode, t_frame *frame);
int		count_colec(t_frame *frame);
void	close_game(t_frame *frame, int error);
void	ft_putmvs(t_frame *frame);
int	test_pathname(char *pathname);
int     check_bad_input(t_frame *frame);

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char *s1);
int	ft_strlen(const char *s);

#endif
