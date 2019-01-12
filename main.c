/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:58:13 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/12 13:36:01 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <X11/X.h>
#include <stdio.h>

int	exit_with_message(char *msg)
{
	ft_putendl(msg);
	return (1);
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;
	int		fd;

	if (argc < 2)
	{
		exit_with_message("Usage: ./fdf <filename>");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (!(mlx = init("FDF")))
		return (exit_with_message("error: mlx wasn't be able to init!"));
	read_map(fd, mlx->map);
	mlx->camera->scale = (double)((WINDOW_WIDTH - 50) / mlx->map->width);
	mlx->map->scale_factor = 5.0f;
	render(mlx);
	mlx_hook(mlx->window, 3, KeyReleaseMask, key_release, mlx);
	mlx_hook(mlx->window, 17, StructureNotifyMask, close_window, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
