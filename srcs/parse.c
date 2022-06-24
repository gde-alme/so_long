#include "../includes/so_long.h"

char	*rmv_newline(char *str)
{
	char	*nl;
	int	len;

	len = ft_strlen(str) - 1;
	if (ft_strlen(str) < 2)
		{printf("ivl map 'rmv_nl'\n");exit(-1);} //error free
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

void	map_allnbrs(t_frame *frame, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < frame->win_h)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] > 49 || map[i][j] < 48)
				exit(-1); //handle erroe and free
			j++;
		}
		i++;
	}
}

void	map_valid(t_frame *frame, char **map)
{
	map_allnbrs(frame, map);
	//sort walls
	//sort nbr of players
}

char	**parse_map(t_frame *frame, char **argv)
{
	char	**map;
	char	*str;
	int	fd;
	int	i;

	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	frame->win_w = ft_strlen(str);
	frame->win_h = ft_count_lines(argv[1]);
	map = (char **)malloc(sizeof(char) * (frame->win_h + 1));
	map[ft_count_lines(argv[1])] = 0;
	while (str != NULL)
	{
		map[i] = rmv_newline(str);
		i++;
		str = get_next_line(fd);
	}
	map_valid(frame, map);
	return (map);
}
