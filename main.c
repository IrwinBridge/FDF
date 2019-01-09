/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:58:13 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/09 18:45:20 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	mlx_hook(mlx->window, 3, 0, key_release, mlx);
	mlx_hook(mlx->window, 17, 0, close_window, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
