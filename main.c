/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:58:13 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/13 11:33:04 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <X11/X.h>
#include <stdio.h>

void	exit_with_message(char *msg)
{
	ft_putendl(msg);
	exit(EXIT_FAILURE);
}

void	setting(t_mlx *mlx)
{
	mlx->map->scale_factor = 5.0f;
	if (mlx->map->width > mlx->map->height)
		mlx->camera->scale = (double)((WINDOW_WIDTH - 50) / mlx->map->width);
	else
		mlx->camera->scale = (double)((WINDOW_HEIGHT - 50) / mlx->map->height);
	mlx->camera->z_scale = (double)(ft_abs(mlx->map->depth_min)
									+ ft_abs(mlx->map->depth_max)) / 10.0f;
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	int		fd;

	if (argc < 2)
		exit_with_message("Usage: ./fdf <filename>");
	fd = open(argv[1], O_RDONLY);
	if (!(mlx = init("FDF")))
		exit_with_message("error: mlx wasn't be able to init!");
	read_map(fd, mlx->map);
	setting(mlx);
	render(mlx);
	mlx_hook(mlx->window, 3, KeyReleaseMask, key_release, mlx);
	mlx_hook(mlx->window, 17, StructureNotifyMask, close_window, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
