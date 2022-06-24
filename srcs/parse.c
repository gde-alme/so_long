#include "../includes/so_long.h"

char	*rmv_newline(char *str)
{
	char	*nl;
	int	len;

	len = ft_strlen(str) - 1;
	nl = ft_substr(str, 0, len);
	free(str);
	return (nl);
}

char	**parse_map(t_frame *frame, char **argv)
{
	char	**map;
	char	*str;
	int	fd;
	int	i;

	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	frame->win_w = ft_strlen(str) - 1;
	map = (char **)malloc(sizeof(char) * (frame->win_w + 1));
	map[frame->win_w] = 0;
	i = 0;
	while (str != NULL)
	{
		map[i] = rmv_newline(str);
		i++;
		str = get_next_line(fd);
	}
	//map_checker(map)
	return (map);
}
