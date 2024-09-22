/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:38:33 by cumoncoq          #+#    #+#             */
/*   Updated: 2024/06/18 14:41:31umoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_empty(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == '0')
		return (1);
	return (0);
}

void shade_minimap(t_data *d)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (i < 2 * MSIZE * MSCALE)
	{
		j = 0;
		while (j < 2 * MSIZE * MSCALE)
		{
			shade_pixel(d, j + MSCALE, i + MSCALE, 1.5);
			j++;
		}
		i++;
	}
	while (i < 2 * MSIZE * MSCALE + (1 * MSCALE))
	{
		j = 0;
		while (j < 2 * MSIZE * MSCALE)
		{
			shade_pixel(d, j + MSCALE, i + (2 * MSCALE), 1.5);
			j++;
		}
		i++;
	}
}

int is_seen(t_data *d, double x, double y)
{
	double s_x;
	double s_y;
	int seen;
	s_x = (y - d->p.y) * cos(-d->p.angle) + (x - d->p.x) * sin(-d->p.angle);
	s_y = (x - d->p.x) * cos(-d->p.angle) - (y - d->p.y) * sin(-d->p.angle);
	// size = WINX / sqrt(pow(s_x, 2) + pow(s_y, 2));
	// x = ((to_deg(atan2(s_x, s_y)) + (FOV / 2)) / FOV) * WINX - size / 2;
	// i = fmax(0, -x) - 1;
	// y = WINY / 2 - size / 2;
	seen = ztoo((to_deg(atan2(s_x, s_y)) + (FOV / 2)) / FOV);
	return (seen);
}

double monster_dist(t_data *d, double x, double y)
{
	double s_x;
	double s_y;
	double dist;
	s_x = y - d->monster_pos.y;
	s_y = x - d->monster_pos.x;
	dist = sqrt(pow(s_x, 2) + pow(s_y, 2));
	// x = ((to_deg(atan2(s_x, s_y)) + (FOV / 2)) / FOV) * WINX - size / 2;
	// i = fmax(0, -x) - 1;
	// y = WINY / 2 - size / 2;
	return (dist);
}

void put_cross(t_data *d)
{
	int middle;

	middle = (MSIZE + 1) * MSCALE;
	my_pixel_put(&d->buff[d->frame % 2], middle, middle, 0x00FF0000);
	my_pixel_put(&d->buff[d->frame % 2], middle + 1, middle, 0x00FF0000);
	my_pixel_put(&d->buff[d->frame % 2], middle - 1, middle, 0x00FF0000);
	my_pixel_put(&d->buff[d->frame % 2], middle, middle + 1, 0x00FF0000);
	my_pixel_put(&d->buff[d->frame % 2], middle, middle - 1, 0x00FF0000);
	my_pixel_put(&d->buff[d->frame % 2], middle + 2, middle, 0x00FF0000);
	my_pixel_put(&d->buff[d->frame % 2], middle - 2, middle, 0x00FF0000);
	my_pixel_put(&d->buff[d->frame % 2], middle, middle + 2, 0x00FF0000);
	my_pixel_put(&d->buff[d->frame % 2], middle, middle - 2, 0x00FF0000);

}

void make_pixel_checkered(t_data *d, int x, int y, double dist)
{

	dist /= 4;
	if (d->frame / (FPS / 2))
	{
		if (((x / 2) + (y / 2)) % 2)
			shade_pixel(d, x, y, fmax(fmin(dist, 1), 0));
	}
	else
	{
		if (!(((x / 2) + (y / 2)) % 2))
			shade_pixel(d, x, y, fmax(fmin(dist, 1), 0));
	}
}

void update_minimap_body(t_data *d, int di, int dj)
{
	int i;
	int j;

	i = d->p.y * MSCALE - MSIZE * MSCALE;
	j = d->p.x * MSCALE - MSIZE * MSCALE;

	if (!di || !dj || di == 2 * MSIZE * MSCALE - 1 || dj == 2 * MSIZE * MSCALE - 1)
		shade_pixel(d, dj + MSCALE, di + MSCALE, 2);
	else if (i + di < 0 || j + dj < 0 || i + di >= ((int)d->g.mapy) * MSCALE
			|| j + dj >= ((int)d->g.mapx) * MSCALE)
		shade_pixel(d, dj + MSCALE, di + MSCALE, 2);
	else if (d->map[(i + di) / MSCALE][(j + dj) / MSCALE] == ' ')
		shade_pixel(d, dj + MSCALE, di + MSCALE, 2);
	else if ((d->map[(i + di) / MSCALE][(j + dj) / MSCALE] == 'X')
			&& !((i + di) % MSCALE == 0 || (j + dj) % MSCALE == 0))
	{
		light_pixel(d, dj + MSCALE, di + MSCALE, -100);
		make_pixel_more_red(d, MSCALE + dj, MSCALE + di, 1);
	}
	else if ((d->map[(i + di) / MSCALE][(j + dj) / MSCALE] == 'D')
			&& !((i + di) % MSCALE == 0 || (j + dj) % MSCALE == 0))
		light_pixel(d, dj + MSCALE, di + MSCALE, -50);
	else if (!is_walkable(d->map[(i + di) / MSCALE][(j + dj) / MSCALE])
			&& !((i + di) % MSCALE == 0 || (j + dj) % MSCALE == 0))
		light_pixel(d, dj + MSCALE, di + MSCALE, -100);
}


void update_minimap_body2(t_data *d, int di, int dj)
{
	int i;
	int j;

	i = d->p.y * MSCALE - MSIZE * MSCALE;
	j = d->p.x * MSCALE - MSIZE * MSCALE;
	if (is_seen(d, (double)(j + dj) / MSCALE, (double)(i + di) / MSCALE))
		make_pixel_more_red(d, MSCALE + dj, MSCALE + di, 0.5);
	make_pixel_checkered(d, MSCALE + dj, MSCALE + di, monster_dist(
		d, (double)(j + dj) / MSCALE, (double)(i + di) / MSCALE));
}

void update_minimap( t_data *d, int di, int dj )
{
	while (++di < 2 * MSIZE * MSCALE)
	{
		dj = -1;
		while (++dj < 2 * MSIZE * MSCALE)
		{
			update_minimap_body(d, di, dj);
			update_minimap_body2(d, di, dj);
		}
	}
	while (di < 2 * MSIZE * MSCALE + MSCALE)
	{
		dj = -1;
		while (++dj < 2 * MSIZE * MSCALE)
		{
			if (di == 2 * MSIZE * MSCALE || !dj || di == 2 * MSIZE * MSCALE + MSCALE - 1 || dj == 2 * MSIZE * MSCALE - 1)
				shade_pixel(d, dj + MSCALE, di + (2 * MSCALE), 2);
			else if (dj * HEALTH / (2 * MSIZE * MSCALE) < d->p.health)
			{
				shade_pixel(d, dj + MSCALE, di + (2 * MSCALE), 0);
				make_pixel_more_red(d, dj + MSCALE, di + (2 * MSCALE), 0.8);
			}
		}
		di++;
	}
	put_cross(d);
}
