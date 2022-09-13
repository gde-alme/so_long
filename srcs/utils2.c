#include "../includes/so_long.h"

int	test_pathname(char *pathname)
{
	int	fd;

	if ((fd = open(pathname, O_RDONLY)) < 0)
		return (0);
	return (1);
}
