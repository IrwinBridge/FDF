/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:07:45 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/11 13:10:23 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

t_matrix4x4	matrix4x4_mul(t_matrix4x4 m1, t_matrix4x4 m2)
{
	t_matrix4x4 res;

	res.x[0] = m1.x[0]*m2.x[0] + m1.y[0]*m2.x[1] + m1.z[0]*m2.x[2] + m1.w[0]*m2.x[3];
	res.y[0] = m1.x[0]*m2.y[0] + m1.y[0]*m2.y[1] + m1.z[0]*m2.y[2] + m1.w[0]*m2.y[3];
	res.z[0] = m1.x[0]*m2.z[0] + m1.y[0]*m2.z[1] + m1.z[0]*m2.z[2] + m1.w[0]*m2.z[3];
	res.w[0] = m1.x[0]*m2.w[0] + m1.y[0]*m2.w[1] + m1.z[0]*m2.w[2] + m1.w[0]*m2.w[3];

	res.x[1] = m1.x[1]*m2.x[0] + m1.y[1]*m2.x[1] + m1.z[1]*m2.x[2] + m1.w[1]*m2.x[3];
	res.y[1] = m1.x[1]*m2.y[0] + m1.y[1]*m2.y[1] + m1.z[1]*m2.y[2] + m1.w[1]*m2.y[3];
	res.z[1] = m1.x[1]*m2.z[0] + m1.y[1]*m2.z[1] + m1.z[1]*m2.z[2] + m1.w[1]*m2.z[3];
	res.w[1] = m1.x[1]*m2.w[0] + m1.y[1]*m2.w[1] + m1.z[1]*m2.w[2] + m1.w[1]*m2.w[3];

	res.x[2] = m1.x[2]*m2.x[0] + m1.y[2]*m2.x[1] + m1.z[2]*m2.x[2] + m1.w[2]*m2.x[3];
	res.y[2] = m1.x[2]*m2.y[0] + m1.y[2]*m2.y[1] + m1.z[2]*m2.y[2] + m1.w[2]*m2.y[3];
	res.z[2] = m1.x[2]*m2.z[0] + m1.y[2]*m2.z[1] + m1.z[2]*m2.z[2] + m1.w[2]*m2.z[3];
	res.w[2] = m1.x[2]*m2.w[0] + m1.y[2]*m2.w[1] + m1.z[2]*m2.w[2] + m1.w[2]*m2.w[3];

	res.x[3] = m1.x[3]*m2.x[0] + m1.y[3]*m2.x[1] + m1.z[3]*m2.x[2] + m1.w[3]*m2.x[3];
	res.y[3] = m1.x[3]*m2.y[0] + m1.y[3]*m2.y[1] + m1.z[3]*m2.y[2] + m1.w[3]*m2.y[3];
	res.z[3] = m1.x[3]*m2.z[0] + m1.y[3]*m2.z[1] + m1.z[3]*m2.z[2] + m1.w[3]*m2.z[3];
	res.w[3] = m1.x[3]*m2.w[0] + m1.y[3]*m2.w[1] + m1.z[3]*m2.w[2] + m1.w[3]*m2.w[3];

	return (res);
}

void		print_matrix(t_matrix4x4 mat)
{
	int i = 0;

	while (i < 4)
	{
		printf("%d %d %d %d\n", mat.x[i], mat.y[i], mat.z[i], mat.w[i]);
		i++;
	}
	printf("\n");
}
