/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:45:27 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/09 20:05:36 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render(t_mlx *mlx)
{
	//mlx_string_put(mlx->mlx, mlx->window, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 0xFF00FF, "CENTER");
	clear_image(mlx->image);
	// DRAW
	int line_width = 100;
	int start = WINDOW_WIDTH / 2 - line_width / 2;
	int end = start + line_width;
	for (int x = start; x < end; x++)
		image_set_pixel(mlx->image, x, WINDOW_HEIGHT / 2, 0xFF00FF);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
}
