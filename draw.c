/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:45:27 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/09 21:36:19 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdio.h>

int		line_process_point(t_mlx *mlx, t_line *l, t_vector *p1, t_vector *p2)
{
	if (p1->x < 0 || p1->x >= WINDOW_WIDTH
		|| p1->y < 0 || p1->y >= WINDOW_HEIGHT
		|| p2->x < 0 || p2->x >= WINDOW_WIDTH
		|| p2->y < 0 || p2->y >= WINDOW_HEIGHT)
		return (1);
	image_set_pixel(mlx->image, p1->x, p1->y, 0xFF00FF);
	l->err2 = l->err;
	if (l->err2 > -l->dx)
	{
		l->err -= l->dy;
		p1->x += l->sx;
	}
	if (l->err2 < l->dy)
	{
		l->err += l->dx;
		p1->y += l->sy;
	}
	return (0);
}

void	draw_line(t_mlx *mlx, t_vector p1, t_vector p2)
{
	t_line line;

	line.start = p1;
	line.end = p2;
	line.dx = ft_abs(p2.x - p1.x);
	line.sx = p1.x < p2.x ? 1 : -1;
	line.dy = ft_abs(p2.y - p1.y);
	line.sy = p1.y < p2.y ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	while (p1.x != p2.x || p1.y != p2.y)
		line_process_point(mlx, &line, &p1, &p2);
}

void	render(t_mlx *mlx)
{
	clear_image(mlx->image);

	t_vector p1;
	t_vector p2;

	p1.x = WINDOW_WIDTH / 2;
	p1.y = WINDOW_HEIGHT / 2;
	p2.x = p1.x;
	p2.y = p1.y - 100;
	int i = 0;
	float pi = 3.14159;
	int angle = 0;
	int radius = 100;
	while (i < 5)
	{
		draw_line(mlx, p1, p2);
		//printf("[x1: %f, y1: %f][x2: %f, y2: %f]", p1.x, p1.y, p2.x, p2.y);
		p2.x = (radius * cos(angle * pi / 180.0f)) + p1.x;
		p2.y = (radius * sin(angle * pi / 180.0f)) + p1.y;
		angle++;
		i++;
	}

	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
}
