/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:54:19 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/11 16:35:26 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

double		to_rad(double a)
{
	return (a * M_PI / 180);
}

t_vector	rotate(t_vector point, t_mlx *mlx)
{
	t_vector	rotated;
	double		x, y, z;
	double		rot_x;
	double		rot_y;
	double		rot_z;

	rot_x = to_rad(mlx->camera->x);
	rot_y = to_rad(mlx->camera->y);
	rot_z = to_rad(mlx->camera->z);

	x = point.x;
	y = point.y;
	z = point.z;

	// x rotation
	rotated.x = x;
	rotated.y = y * cos(rot_x) + z * sin(rot_x);
	rotated.z = -y * sin(rot_x) + z * cos(rot_x);

	x = rotated.x;
	y = rotated.y;
	z = rotated.z;

	// y rotation
	rotated.x = x * cos(rot_y) + z * sin(rot_y);
	rotated.y = y;
	rotated.z = -x * sin(rot_y) + z * cos(rot_y);

	x = rotated.x;
	y = rotated.y;
	z = rotated.z;

	// z rotation
	rotated.x = x * cos(rot_z) - y * sin(rot_z);
	rotated.y = x * sin(rot_z) + y * cos(rot_z);
	rotated.z = z;

	return (rotated);
}

t_vector	projection(t_vector point, t_mlx *mlx)
{
	t_vector projected;

	projected.x = point.x;
	projected.y = point.y;
	projected.z = point.z;

	// camera rotation
	projected = rotate(projected, mlx);

	// camera offset
	projected.x += mlx->camera->x_offset;
	projected.y -= mlx->camera->y_offset;

	// camera zoom
	projected.x *= mlx->camera->scale;
	projected.y *= mlx->camera->scale;
	projected.z *= mlx->camera->scale;

	// camera positionning to world center
	projected.x += WINDOW_WIDTH / 2 - (mlx->map->width * mlx->camera->scale / 2);
	projected.y += WINDOW_HEIGHT / 2 - (mlx->map->height * mlx->camera->scale / 2);

	projected.x = (int)projected.x;
	projected.y = (int)projected.y;
	projected.z = (int)projected.z;

	return (projected);
}
