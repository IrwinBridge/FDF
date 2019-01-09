/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:13:46 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/09 18:33:33 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_release(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int	close_window(t_mlx *mlx)
{
	(void)mlx;
	exit(EXIT_SUCCESS);
	return (0);
}
