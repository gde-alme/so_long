#include "../includes/so_long.h"

int	test_pathname(char *pathname)
{
	int	fd;

	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		return (0);
	return (1);
	close(fd);
}

int	check_bad_input(t_frame *frame)
{
	int	i;
	int	j;
	char	check;
	int	errors;

	i = 0;
	errors = 0;
	while (i < frame->win_h)
	{
		j = 0;
		while (j < frame->win_w)
		{
			check = frame->map[i][j];
			if (check != 'E' && check != 'P' && check != '0'
					&& check != '1' && check != 'C')
				errors++;
			j++;
		}
		i++;
	}
	return (errors);
}
