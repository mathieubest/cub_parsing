/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mafs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 00:47:38 by cumoncoq          #+#    #+#             */
/*   Updated: 2024/06/24 23:26:42 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double to_deg(double rad)
{
	return (rad * 180 / M_PI);
}

double to_rad(double deg)
{
	return (deg * M_PI / 180);
}

int	upper_int( double d )
{
	return ((int)d + 1);
}

int lower_int( double d )
{
	return ((int)d);
}

int d_eq( double d1, double d2 )
{
	if (d1 >= d2 - EPSILON && d1 <= d2 + EPSILON)
		return (1);
	return (0);
}

t_vec get_vec( double angle )
{
	t_vec vec;

	vec.x = cos(angle);
	vec.y = sin(angle);
	return (vec);
}

int ztoo(double x)
{
	if (x >= 0 && x <= 1)
		return (1);
	return (0);
}


double x_from_y( double y, t_vec cos_sin)
{
	if (cos_sin.y < EPSILON && cos_sin.y > -EPSILON)
	{
		return (0);
	}
	return ((y / cos_sin.y) * cos_sin.x);
}

double y_from_x( double x, t_vec cos_sin)
{
	if (cos_sin.x < EPSILON && cos_sin.x > -EPSILON)
	{
		return (0);
	}
	return ((x / cos_sin.x) * cos_sin.y);
}

// int dec_eq_int( double d, int i )
// {
// 	if (d >= i && d < i + 1)
// 		return (1);
// 	return (0);
// }






