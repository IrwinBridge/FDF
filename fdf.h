/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:57:35 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/09 20:45:12 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_WIDTH	1280
# define WINDOW_HEIGHT	720

# include "minilibx/mlx.h"
# include "libft/libft.h"

typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
	int			color;
}				t_vector;

typedef struct	s_line
{
	t_vector	start;
	t_vector	end;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			err2;
}				t_line;

typedef struct	s_map
{
	int			width;
	int			height;
	int			depth_min;
	int			depth_max;
	t_vector	**coords;
}				t_map;

typedef struct	s_mouse
{
	char		is_down;
	int			x;
	int			y;
	int			prev_x;
	int			prev_y;
}				t_mouse;

typedef struct	s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
}				t_image;

typedef struct	s_mlx
{
	void		*mlx;
	void		*window;
	t_image		*image;
	t_map		*map;
	t_mouse		*mouse;
	float		**zbuf;
}				t_mlx;

t_mlx			*init(char *title);

void			render(t_mlx *mlx);

t_image			*create_image(t_mlx *mlx);
void			clear_image(t_image *image);
void			image_set_pixel(t_image *image, int x, int y, int color);
t_image			*delete_image(t_mlx *mlx, t_image *img);

int				key_release(int keycode, t_mlx *mlx);
int				close_window(t_mlx *mlx);

#endif
