/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:13:46 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/13 00:04:17 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	key_release(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
	{
		mlx_free(mlx);
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_LEFT)
	{
		mlx->camera->x_offset--;
		render(mlx);
	}
	if (keycode == KEY_UP)
	{
		mlx->camera->y_offset++;
		render(mlx);
	}
	if (keycode == KEY_RIGHT)
	{
		mlx->camera->x_offset++;
		render(mlx);
	}
	if (keycode == KEY_DOWN)
	{
		mlx->camera->y_offset--;
		render(mlx);
	}
	if (keycode == KEY_PLUS)
	{
		mlx->camera->scale = (mlx->camera->scale + mlx->map->scale_factor < 100.0f) ?
								mlx->camera->scale + mlx->map->scale_factor : 100.0f;
		render(mlx);
	}
	if (keycode == KEY_MINUS)
	{
		mlx->camera->scale = (mlx->camera->scale - mlx->map->scale_factor > 0.0f) ?
								mlx->camera->scale - mlx->map->scale_factor : 1.0f;
		render(mlx);
	}
	if (keycode == KEY_Q)
	{
		mlx->camera->z -= mlx->map->scale_factor;
		render(mlx);
	}
	if (keycode == KEY_E)
	{
		mlx->camera->z += mlx->map->scale_factor;
		render(mlx);
	}
	if (keycode == KEY_NUM8)
	{
		mlx->camera->x -= mlx->map->scale_factor;
		render(mlx);
	}
	if (keycode == KEY_NUM2)
	{
		mlx->camera->x += mlx->map->scale_factor;
		render(mlx);
	}
	if (keycode == KEY_NUM4)
	{
		mlx->camera->y -= mlx->map->scale_factor;
		render(mlx);
	}
	if (keycode == KEY_NUM6)
	{
		mlx->camera->y += mlx->map->scale_factor;
		render(mlx);
	}
	if (keycode == KEY_NUM5)
	{
		mlx->camera->proj = (mlx->camera->proj == ISO) ? PARALLEL : ISO;
		render(mlx);
	}
	return (0);
}

int	close_window(t_mlx *mlx)
{
	mlx_free(mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
