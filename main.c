/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:58:13 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/11 13:10:34 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <X11/X.h>
#include <stdio.h>

int	exit_with_message(char *msg)
{
	ft_putendl(msg);
	return (1);
}

int	main(void)
{
	t_mlx	*mlx;

	if (!(mlx = init("FDF")))
		return (exit_with_message("error: mlx wasn't be able to init!"));
	render(mlx);
	mlx_hook(mlx->window, 3, KeyReleaseMask, key_release, mlx);
	mlx_hook(mlx->window, 17, StructureNotifyMask, close_window, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
