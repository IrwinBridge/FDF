/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:57:35 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/12 13:27:51 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_WIDTH	1280
# define WINDOW_HEIGHT	720

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include "get_next_line.h"
# include <math.h>

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_vector;

typedef struct	s_matrix4x4
{
	int			x[4];
	int			y[4];
	int			z[4];
	int			w[4];
}				t_matrix4x4;

typedef struct	s_line
{
	int			dx;
	int			dy;
	int			dirx;
	int			diry;
	int			err;
	int			err2;
}				t_line;

typedef struct	s_map
{
	int			width;
	int			height;
	int			depth_min;
	int			depth_max;
	double		scale_factor;
	int			*z;
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

typedef struct	s_camera
{
	double		x_offset;
	double		y_offset;
	double		x;
	double		y;
	double		z;
	double		scale;
}				t_camera;

typedef struct	s_mlx
{
	void		*mlx;
	void		*window;
	t_image		*image;
	t_map		*map;
	t_mouse		*mouse;
	t_camera	*camera;
	float		**zbuf;
}				t_mlx;

t_mlx			*init(char *title);

void			render(t_mlx *mlx);
t_vector		projection(t_vector point, t_mlx *mlx);

t_image			*create_image(t_mlx *mlx);
void			clear_image(t_image *image);
void			image_set_pixel(t_image *image, int x, int y, int color);
t_image			*delete_image(t_mlx *mlx, t_image *img);

int				key_release(int keycode, t_mlx *mlx);
int				close_window(t_mlx *mlx);
t_mlx			*mlx_free(t_mlx *mlx);

void			read_map(int fd, t_map *map);

t_matrix4x4	matrix4x4_mul(t_matrix4x4 m1, t_matrix4x4 m2);
t_matrix4x4	matrix4x4_mul_v2(t_matrix4x4 m1, t_matrix4x4 m2);
void		print_matrix(t_matrix4x4 mat);

#endif
