/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:13:46 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/14 19:35:39 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shift_handler(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_LEFT)
		mlx->camera->x_offset--;
	if (keycode == KEY_UP)
		mlx->camera->y_offset++;
	if (keycode == KEY_RIGHT)
		mlx->camera->x_offset++;
	if (keycode == KEY_DOWN)
		mlx->camera->y_offset--;
}

void	rotation_handler(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_Q)
		mlx->camera->z -= mlx->map->scale_factor;
	if (keycode == KEY_E)
		mlx->camera->z += mlx->map->scale_factor;
	if (keycode == KEY_NUM8)
		mlx->camera->x -= mlx->map->scale_factor;
	if (keycode == KEY_NUM2)
		mlx->camera->x += mlx->map->scale_factor;
	if (keycode == KEY_NUM4)
		mlx->camera->y -= mlx->map->scale_factor;
	if (keycode == KEY_NUM6)
		mlx->camera->y += mlx->map->scale_factor;
}

void	keys_handler(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_PLUS)
		mlx->camera->scale = (mlx->camera->scale +
						mlx->map->scale_factor < 100.0f) ?
						mlx->camera->scale + mlx->map->scale_factor : 100.0f;
	if (keycode == KEY_MINUS)
		mlx->camera->scale = (mlx->camera->scale -
						mlx->map->scale_factor > 0.0f) ?
						mlx->camera->scale - mlx->map->scale_factor : 1.0f;
	if (keycode == KEY_NUM5)
		mlx->camera->proj = (mlx->camera->proj == ISO) ? PARALLEL : ISO;
	if (keycode == KEY_PGUP)
		mlx->camera->z_scale += 1.0f;
	if (keycode == KEY_PGDOWN)
		mlx->camera->z_scale -= 1.0f;
}

int	key_release(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
	{
		mlx_free(mlx);
		exit(EXIT_SUCCESS);
	}
	shift_handler(keycode, mlx);
	rotation_handler(keycode, mlx);
	keys_handler(keycode, mlx);
	if (keycode == KEY_NUM0)
	{
		if (mlx->map->width > mlx->map->height)
			mlx->camera->scale = (float)((WINDOW_WIDTH - 50) / mlx->map->width);
		else
			mlx->camera->scale = (float)((WINDOW_HEIGHT - 50) / mlx->map->height);
		mlx->camera->z_scale = (float)(ft_abs(mlx->map->depth_min)
										+ ft_abs(mlx->map->depth_max)) / 10.0f;
		mlx->camera->x = 0.0f;
		mlx->camera->y = 0.0f;
		mlx->camera->z = 0.0f;
		mlx->camera->x_offset = 0.0f;
		mlx->camera->y_offset = 0.0f;
	}
	return (0);
}

int	close_window(t_mlx *mlx)
{
	mlx_free(mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
