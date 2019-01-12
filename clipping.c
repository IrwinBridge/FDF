/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 23:27:44 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/12 23:54:17 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Returns 0 only if two points are completely outside of window
*/

int	clipping(t_vector p1, t_vector p2)
{
	int allow;

	allow = 1;

	// treat different scenario when point is left, top, right or bottom off the screen
	// if two of them not in the screen - return (0)

	if ((p1.x > 0 && p1.x < WINDOW_WIDTH) &&
		(p1.y > 0 && p1.y < WINDOW_HEIGHT) &&
		(p2.x > 0 && p2.x < WINDOW_WIDTH) &&
		(p2.y > 0 && p2.y < WINDOW_HEIGHT))
		allow = 1;
	return (allow);
}
