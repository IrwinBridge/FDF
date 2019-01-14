/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:57:37 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/14 22:53:04 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	to_rad(float a)
{
	return (a * M_PI / 180);
}

float	normalize(float val, float min, float max)
{
	if (max - min != 0)
		return ((float)(val - min) / (float)(max - min));
	else
		return (0);
}

int		get_hue(int r, int g, int b)
{
	float hue;
	float min;
    float max;

	hue = 0.0f;
	min = (float)min_val(min_val(r, g), b);
	max = (float)max_val(max_val(r, g), b);
	if (min == max) {
        return (0);
    }
	if (max == (float)r)
	{
        hue = (float)(g - b) / (max - min);
    }
	else if (max == (float)g)
	{
        hue = 2.0f + (float)(b - r) / (max - min);
    }
	else
	{
        hue = 4.0f + (float)(r - g) / (max - min);
    }
	hue *= 60.0f;
	if (hue < 0.0f)
		hue = 360.0f;
	if (hue > 360.0f)
		hue = 0.0f;
	return (round(hue));
}

int		get_new_color(int color, int direction)
{
	t_color	start;
	t_color	end;
	int		h;

	start.r = (color >> 16) & 0xFF;
	start.g = (color >> 8) & 0xFF;
	start.b = (color & 0xFF);

	h = get_hue(start.r, start.g, start.b);
	h += direction * 8;
	float u = cos(h * M_PI / 180);
  	float w = sin(h * M_PI / 180);

	end.r = (0.299f + 0.701f * u + 0.168f * w) * start.r
			+ (0.587f - 0.587f * u + 0.330f * w) * start.g
    		+ (0.114f - 0.114f * u - 0.497f * w) * start.b;
	end.g = (0.299f - 0.299f * u - 0.328f * w) * start.r
		    + (0.587f + 0.413f * u + 0.035f * w) * start.g
		    + (0.114f - 0.114f * u + 0.292f * w) * start.b;
	end.b = (0.299f - 0.3f * u + 1.25f * w) * start.r
		    + (0.587f - 0.588f * u - 1.05f * w) * start.g
		    + (0.114f + 0.886f * u - 0.203f * w) * start.b;

	return ((end.r << 16) | (end.g << 8) | end.b);
}

void	shift_color(t_mlx *mlx, int dir)
{
	if (dir == 0)
	{
		mlx->map->start_color = get_new_color(mlx->map->start_color, -1);
		mlx->map->end_color = get_new_color(mlx->map->end_color, -1);
	}
	else
	{
		mlx->map->start_color = get_new_color(mlx->map->start_color, 1);
		mlx->map->end_color = get_new_color(mlx->map->end_color, 1);
	}
}
