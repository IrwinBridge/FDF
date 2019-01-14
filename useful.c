/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:57:37 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/14 20:00:36 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <time.h>

float		to_rad(float a)
{
	return (a * M_PI / 180);
}

float		normalize(float val, float min, float max)
{
	if (max - min != 0)
		return ((float)(val - min) / (float)(max - min));
	else
		return (0);
}
