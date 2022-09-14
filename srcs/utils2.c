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
