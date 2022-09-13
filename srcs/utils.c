/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:29:29 by gde-alme          #+#    #+#             */
/*   Updated: 2022/09/12 16:54:29 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	size(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = size(n);
	if (n < 0)
		i++;
	str = malloc((i + 1) * sizeof * str);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[i] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[--i] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

void	ft_putmvs(t_frame *frame)
{
	char	*mvs;
	int		i;
	int		unused;

	i = 0;
	frame->mvs++;
	mvs = ft_itoa(frame->mvs);
	while (mvs[i] != '\0')
	{
		unused = write(2, &(mvs[i]), 1);
		i++;
	}
	unused = write(2, "\n", 1);
	unused += 1;
	free(mvs);
}

int	count_colec(t_frame *frame)
{
	int	i;
	int	j;
	int	counter;

	counter = 0;
	i = 0;
	while (i < frame->win_h)
	{
		j = 0;
		while (j < frame->win_w)
		{
			if (frame->map[i][j] == 'C')
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

int	ft_count_lines(char *path_to_file)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(path_to_file, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		if (line[0] != '1')
			return (i);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (i);
}
