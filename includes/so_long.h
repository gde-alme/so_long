/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:23:39 by gde-alme          #+#    #+#             */
/*   Updated: 2022/06/18 17:30:32 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define BUFFER_SIZE 10

typedef struct s_frame {
	void	*mlx;
	void	*win;
	int	mvs;
	int	pos_x;
	int	pos_y;
	char	**map;
	int	win_h;
	int	win_w;
}	t_frame;

typedef struct s_img {
	void	*img;
	int	img_w;
	int	img_h;
}	t_img;


void	parse_map(t_frame *frame, char **argv);
void	close_game(t_frame *frame);

char		*ft_nextline(char **save);
char		*ft_nl(int fd, char **save);
char		*ft_strchr(const char *s, int c);
char		*get_next_line(const int fd);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(char *s1);
size_t		ft_strlen(const char *s);

#endif
