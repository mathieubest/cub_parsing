/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 21:23:14 by cumoncoq          #+#    #+#             */
/*   Updated: 2024/06/24 05:14:33 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int char_is_wall( char c )
{
	if (c == '1' || c == 'D' || c == 'X' || c == 'x' || c == '+')
		return (1);
	return (0);
}

t_vec fill_t_vec( double x, double y )
{
	t_vec vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}

t_tuple fill_t_tuple( int x, int y )
{
	t_tuple t;

	t.x = x;
	t.y = y;
	return (t);
}
