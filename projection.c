/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:54:19 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/14 17:19:50 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		iso(t_vector *p)
{
    float x;
    float y;

    x = p->x;
    y = p->y;
    p->x = (x - y) * cos(0.523599);
    p->y = -p->z + (x + y) * sin(0.523599);
}

void		dimetric(t_vector *p)
{
	float x;
	float y;

	x = p->x;
	y = p->y;
	p->x = x * cos(0.122173f) + (y * cos(0.733038f) * 0.5f);
	p->y = -p->z + (y * sin(0.733038f) * 0.5f) - x * sin(0.122173f);
}

void		perspective(t_vector *p)
{
	float x;
	float y;
	float z;

	x = p->x;
	y = p->y;
	z = p->z;
	p->x = x / (-0.005f * z + 1.0f);
	p->y = y / (-0.005f * z + 1.0f);
	p->z = z / (-0.005f * z + 1.0f);
}

t_vector	rotate(t_vector point, t_mlx *mlx)
{
	t_vector	rotated;
	float		x, y, z;
	float		rot_x;
	float		rot_y;
	float		rot_z;

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
	t_vector	projected;
	double		z_percentage;

	// pivot point
	projected.x = point.x - mlx->map->width / 2;
	projected.y = point.y - mlx->map->height / 2;
	projected.z = normalize(point.z, mlx->map->depth_min,
									mlx->map->depth_max) * mlx->camera->z_scale;

	// camera rotation
	projected = rotate(projected, mlx);

	// camera projection
	if (mlx->camera->proj == ISO)
		iso(&projected);
	else if (mlx->camera->proj == PARALLEL)
		perspective(&projected);

	// camera offset
	projected.x -= mlx->camera->x_offset;
	projected.y += mlx->camera->y_offset;

	// camera zoom
	projected.x *= mlx->camera->scale;
	projected.y *= mlx->camera->scale;

	// camera positioning to world center
	projected.x += WINDOW_WIDTH / 2;
	projected.y += WINDOW_HEIGHT / 2;

	projected.x = (int)projected.x;
	projected.y = (int)projected.y;
	projected.z = (int)projected.z;

	// setting color according to z
	z_percentage = percent(mlx->map->depth_min,
									mlx->map->depth_max,
									point.z);
	projected.color = get_gradient_at(z_percentage, START_COLOR, END_COLOR);

	return (projected);
}
