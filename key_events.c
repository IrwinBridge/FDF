/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:13:46 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/12 15:04:38 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	key_release(int keycode, t_mlx *mlx)
{
	if (keycode == 0xFF1B)
	{
		mlx_free(mlx);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 0xFF51) // left
	{
		mlx->camera->x_offset--;
		render(mlx);
	}
	if (keycode == 0xFF52) // up
	{
		mlx->camera->y_offset++;
		render(mlx);
	}
	if (keycode == 0xFF53) // right
	{
		mlx->camera->x_offset++;
		render(mlx);
	}
	if (keycode == 0xFF54) // down
	{
		mlx->camera->y_offset--;
		render(mlx);
	}

	if (keycode == 0xFFAB) // zoom in
	{
		mlx->camera->scale = (mlx->camera->scale + mlx->map->scale_factor < 100.0f) ?
								mlx->camera->scale + mlx->map->scale_factor : 100.0f;
		render(mlx);
	}
	if (keycode == 0xFFAD) // zoom out
	{
		mlx->camera->scale = (mlx->camera->scale - mlx->map->scale_factor > 0.0f) ?
								mlx->camera->scale - mlx->map->scale_factor : 1.0f;
		render(mlx);
	}

	if (keycode == 0x71) // z-rotation <- q
	{
		mlx->camera->z -= mlx->map->scale_factor;
		render(mlx);
	}
	if (keycode == 0x65) // z-rotation -> e
	{
		mlx->camera->z += mlx->map->scale_factor;
		render(mlx);
	}

	if (keycode == 0xFF97) // x-rotation <- num8
	{
		mlx->camera->x -= mlx->map->scale_factor;
		render(mlx);
	}
	if (keycode == 0xFF99) // x-rotation -> num2
	{
		mlx->camera->x += mlx->map->scale_factor;
		render(mlx);
	}

	if (keycode == 0xFF96) // y-rotation <- num4
	{
		mlx->camera->y -= mlx->map->scale_factor;
		render(mlx);
	}
	if (keycode == 0xFF98) // y-rotation -> num6
	{
		mlx->camera->y += mlx->map->scale_factor;
		render(mlx);
	}

	// change projection
	if (keycode == 0xFF9D)
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
