/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:42:56 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/11 22:30:39 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

int		max(int *a, int size)
{
	int max;
	int i;

	i = 0;
	while (i < size)
	{
		max = a[i] > max ? a[i] : max;
		i++;
	}
	return (max);
}

int		min(int *a, int size)
{
	int min;
	int i;

	i = 0;
	while (i < size)
	{
		min = a[i] < min ? a[i] : min;
		i++;
	}
	return (min);
}

void	read_map(int fd, t_map *map)
{
	char		*line;
	char		*map_str;
	char		*temp;
	int			i;
	int			numbers_count;

	numbers_count = 0;
	map_str = ft_strnew(0);
	map->height = 0;
	while (get_next_line(fd, &line))
	{
		temp = ft_strnew(ft_strlen(map_str) + 1);
		temp = ft_strdup(map_str);
		temp = ft_strjoin(temp, " ");
		ft_strdel(&map_str);
		map_str = ft_strnew(ft_strlen(temp) + ft_strlen(line) + 1);
		map_str = ft_strjoin(temp, line);
		ft_strdel(&temp);
		map->height++;

		i = 0;
		while (line[i])
		{
			if (ft_isdigit(line[i]))
			{
				numbers_count++;
				while (ft_isdigit(line[i]))
				{
					i++;
				}
			}
			else
				i++;
		}
	}
	map->width = numbers_count / map->height;
	char **zs = ft_strsplit(map_str, ' ');
	if (!(map->z = (int *)malloc(sizeof(int) * numbers_count + 1)))
		return ;
	i = 0;
	while (i < numbers_count)
	{
		map->z[i] = atoi(zs[i]);
		i++;
	}

	map->depth_max = max(map->z, numbers_count);
	map->depth_min = min(map->z, numbers_count);

	close(fd);
	free(map_str);
	free(line);
	free(temp);
}