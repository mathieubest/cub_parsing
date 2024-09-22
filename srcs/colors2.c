/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:25:20 by cumoncoq          #+#    #+#             */
/*   Updated: 2024/06/25 17:11:53 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double lcg_rand( size_t seed )
{
	size_t a;
	size_t c;
	size_t m;
	a = 1664525;
	c = 1013904223;
	m = 4294967296;
	seed = (a * seed + c) % m;
	return (seed / (double)m);
}

void make_pixel_more_red( t_data *d, int x, int y, double intensity )
{
	int color;
	int r;
	int g;
	int b;
	(void)intensity;

	color = ft_pixel_get(&d->buff[d->frame % 2], x, y);
	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = color & 0xFF;
	// r = r + ((255 - r) * intensity);
	g = g * (1 - intensity);
	b = b * (1 - intensity);
	color = (r << 16) + (g << 8) + b;
	my_pixel_put(&d->buff[d->frame % 2], x, y, color);
}

void add_overlay( t_data *d, int i, int j )
{
	double dist_monster;
	double intensity;
	double centered;

	dist_monster = (sqrt(pow(d->p.x - d->monster_pos.x, 2) + pow(d->p.y - d->monster_pos.y, 2)));
	intensity = fmax(fmin((5 / dist_monster - 1) / 4, 1), 0);
	if (intensity > 0)
		check_health(d, intensity);
	// if (intensity == 0)
	return ;
	while (++i < WINY)
	{
		j = -1;
		while (++j < WINX)
		{
			centered = pow(sqrt(pow((i - WINY / 2) * 1.5, 2) + pow(j - WINX / 2, 2)) / WINY, 2);
			if (centered > 1)
				centered = 1;
			// if (i < WINY / 2 && j < WINX / 2)
			// 	shade_pixel(d, j, i, 1 - ((lcg_rand(d->frame / 3 * i * j)) * intensity * centered));
			// else if (i < WINY / 2 && j >= WINX / 2)
			// 	shade_pixel(d, j, i, 1 - ((lcg_rand(d->frame / 3 * i * (WINX - j))) * intensity * centered));
			// else if (i >= WINY / 2 && j < WINX / 2)
			// 	shade_pixel(d, j, i, 1 - ((lcg_rand(d->frame / 3 * (WINY - i) * j)) * intensity * centered));
			// else if (i >= WINY / 2 && j >= WINX / 2)
			// 	shade_pixel(d, j, i, 1 - ((lcg_rand(d->frame / 3 * (WINY - i) * (WINX - j))) * intensity * centered));
			make_pixel_more_red(d, j, i, intensity * centered);
		}
	}
}

void light_pixel(t_data *d, int x, int y, int shade)
{
	my_pixel_put(
		&d->buff[d->frame % 2], x, y, ft_add_shade(
			ft_pixel_get(&d->buff[d->frame % 2], x, y), shade));
}

void shade_pixel(t_data *d, int x, int y, double shade)
{
	if (shade == 1)
		return ;
	my_pixel_put(
		&d->buff[d->frame % 2], x, y, ft_div_shade(
			ft_pixel_get(&d->buff[d->frame % 2], x, y), shade));
}
