#include "../includes/so_long.h"

char	*rmv_newline(char *str)
{
	char	*nl;
	int	len;

	len = ft_strlen(str) - 1;
	if (ft_strlen(str) < 2)
		return (str);
	nl = ft_substr(str, 0, len);
	free(str);
	return (nl);
}

int	ft_count_lines(char *path)
{
	int	fd;
	char	*tmp;
	int	i;

	fd = open(path, O_RDONLY);
	tmp = get_next_line(fd);
	i = 0;
	while (tmp != NULL)
	{
		i++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	return (i);
}

void	map_allnbrs(t_frame *frame)
{
	int	i;
	int	j;
	char	**map;

	map = frame->map;
	i = 0;
	while (i < frame->win_h)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] > 49 || map[i][j] < 48)
				close_game(frame);
			j++;
		}
		i++;
	}
}

void	map_lateral(t_frame *frame)
{
	int	i;
	char	**map;

	map = frame->map;
	i = 0;
	while (i < frame->win_h)
	{
		if (map[i][0] != 49)
			close_game(frame);
		i++;
	}
	i = 0;
	while (i < frame->win_h)
	{
		if (map[i][ft_strlen(map[i]) - 1] != 49)
			close_game(frame);
		i++;
	}
}

void	map_walls(t_frame *frame)
{
	int	i;
	char	**map;

	map = frame->map;
	i = 0;
	while(map[0][i] != '\0')
	{
		if (map[0][i] != '1')
			close_game(frame);
		i++;
	}
	i = 0;
	while (map[frame->win_h - 1][i] != '\0')
	{
		if (map[frame->win_h - 1][i] != 49)
			close_game(frame);
		i++;
	}
	map_lateral(frame);	
}

void	map_lines(t_frame *frame)
{
	
}

	//sort nbr of players

void	parse_map(t_frame *frame, char **argv)
{
	char	**map;
	char	*str;
	int	fd;
	int	i;

	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	frame->win_w = ft_strlen(str) - 1;
	frame->win_h = ft_count_lines(argv[1]);
	map = (char **)malloc(sizeof(char) * (frame->win_h + 1));
	map[ft_count_lines(argv[1])] = 0;
	frame->map = map;
	while (str != NULL)
	{
		map[i] = rmv_newline(str);
		i++;
		str = get_next_line(fd);
	}
	printf("%s\n", map[0]);
	printf("%s\n", map[1]);
	printf("%s\n", map[2]);
	map_lines(frame);
	map_allnbrs(frame);
	map_walls(frame);
}
