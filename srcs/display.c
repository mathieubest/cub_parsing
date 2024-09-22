/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:28:58 by cumoncoq          #+#    #+#             */
/*   Updated: 2024/06/25 19:00:54 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void put_sprite(t_data *d, double x, double y)
{
	double s_x;
	double s_y;
	double size;
	int i;
	int j;
	s_x = (y - d->p.y) * cos(-d->p.angle) + (x - d->p.x) * sin(-d->p.angle);
	s_y = (x - d->p.x) * cos(-d->p.angle) - (y - d->p.y) * sin(-d->p.angle);
	size = WINX / sqrt(pow(s_x, 2) + pow(s_y, 2));
	// if (size < 0.2)//?
	// 	size = 0.2;	//?
	x = ((to_deg(atan2(s_x, s_y)) + (FOV / 2)) / FOV) * WINX - size / 2;
	i = fmax(0, -x) - 1;
	y = WINY / 2 - size / 2;
	d->p.see_monster = ztoo((to_deg(atan2(s_x, s_y)) + (FOV / 2)) / FOV);
	while(++i < size && i + x < WINX)
	{
		j = fmax(0, -y) - 1;
		while (++j < size && j + y < WINY)
		{
			if (WINX / size < d->p.rays[i + (int)x])
				d->p.see_monster = 1;
			if (WINX / size < d->p.rays[i + (int)x])
				shade_pixel(d, i + x, j + y, ft_shade_get(&d->t.monster[
					d->frame / (FPS / 3)], d->t.monster->w * i / size,
						d->t.monster->h * j / size ));
		}
	}
}

void get_switch_color( t_wall wall, t_data *d, double y, int *color )
{
	if ((wall.dir == north || wall.dir == south) && wall.type == is_switch_off)
		*color = ft_pixel_get(&d->t.swi[0][0], (int)(d->t.swi[0][0].w * wall.column), (int)(d->t.swi[0][0].h * y));
	else if ((wall.dir == north || wall.dir == south) && wall.type == is_switch_mid)
		*color = ft_pixel_get(&d->t.swi[0][1], (int)(d->t.swi[0][1].w * wall.column), (int)(d->t.swi[0][1].h * y));
	else if ((wall.dir == north || wall.dir == south) && wall.type == is_switch_on)
		*color = ft_pixel_get(&d->t.swi[0][2], (int)(d->t.swi[0][2].w * wall.column), (int)(d->t.swi[0][2].h * y));

	else if ((wall.dir == west || wall.dir == east) && wall.type == is_switch_off)
		*color = ft_pixel_get(&d->t.swi[1][0], (int)(d->t.swi[1][0].w * wall.column), (int)(d->t.swi[1][0].h * y));
	else if ((wall.dir == west || wall.dir == east) && wall.type == is_switch_mid)
		*color = ft_pixel_get(&d->t.swi[1][1], (int)(d->t.swi[1][1].w * wall.column), (int)(d->t.swi[1][1].h * y));
	else if ((wall.dir == west || wall.dir == east) && wall.type == is_switch_on)
		*color = ft_pixel_get(&d->t.swi[1][2], (int)(d->t.swi[1][2].w * wall.column), (int)(d->t.swi[1][2].h * y));
	if (*color & 0xff000000)
	{
		if (wall.dir == north)
			*color = ft_pixel_get(&d->t.n, (int)(d->t.n.w * (1 - wall.column)), (int)(d->t.n.h * y));
		else if (wall.dir == south)
			*color = ft_pixel_get(&d->t.s, (int)(d->t.s.w * (1 - wall.column)), (int)(d->t.s.h * y));
		else if (wall.dir == east)
			*color = ft_pixel_get(&d->t.e, (int)(d->t.e.w * wall.column), (int)(d->t.e.h * y));
		else if (wall.dir == west)
			*color = ft_pixel_get(&d->t.w, (int)(d->t.w.w * wall.column), (int)(d->t.w.h * y));
	}
}

int get_wall_color(t_wall wall, t_data *d, double y )
{
	int color;

	if (y == 1)
		y -= EPSILON;
	if (wall.dir == north && wall.type == is_wall)
		color = ft_pixel_get(&d->t.n, (int)(d->t.n.w * (1 - wall.column)), (int)(d->t.n.h * y));
	else if (wall.dir == south && wall.type == is_wall)
		color = ft_pixel_get(&d->t.s, (int)(d->t.s.w * (1 - wall.column)), (int)(d->t.s.h * y));
	else if (wall.dir == east && wall.type == is_wall)
		color = ft_pixel_get(&d->t.e, (int)(d->t.e.w * wall.column), (int)(d->t.e.h * y));
	else if (wall.dir == west && wall.type == is_wall)
		color = ft_pixel_get(&d->t.w, (int)(d->t.w.w * wall.column), (int)(d->t.w.h * y));
	if ((wall.dir == north || wall.dir == south) && wall.type == is_door)
		color = ft_pixel_get(&d->t.door_ns, (int)(d->t.door_ns.w * (1 - wall.column)), (int)(d->t.door_ns.h * y));
	else if ((wall.dir == east || wall.dir == west) && wall.type == is_door)
		color = ft_pixel_get(&d->t.door_ew, (int)(d->t.door_ew.w * wall.column), (int)(d->t.door_ew.h * y));
	if (wall.type == is_switch_off || wall.type == is_switch_on || wall.type == is_switch_mid)
	{
		get_switch_color(wall, d, y, &color);
	}

	return (ft_div_shade(color, (wall.dist / SHADOW + 1)));
}

int more_red( int color, double intensity )
{
	int r;
	int g;
	int b;
	(void)intensity;

	// color = ft_pixel_get(&d->buff[d->frame % 2], x, y);
	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = color & 0xFF;
	// r = r + ((255 - r) * intensity);
	g = g * (1 - intensity);
	b = b * (1 - intensity);
	color = (r << 16) + (g << 8) + b;
	// my_pixel_put(&d->buff[d->frame % 2], x, y, color);
	return (color);
}

//todo)) x will be used for fish eye correction (maybe not because I just found out that I can use argcos to determine dangles)
void update_column( int x, double angle, t_data *d )
{
	int i = 0;
	int top;
	int bot;
	int h;
	double c;
	(void)c;
	t_wall wall;

	wall = throw_ray(d, angle);	//$ bring back
	// //?
	// wall.column = 0.5;
	// wall.dir = north;
	// wall.dist = 5.0;
	// wall.type = is_wall;
	// return; 
	// //?
	wall.dist *= cos(d->p.angle - angle);
	d->p.rays[x] = wall.dist;
	h = WINY / wall.dist + 1;
	top = (WINY - h) / 2;
	bot = WINY - top;
	printf("dmg * c = %f\n", d->p.dmg_intensity * 1);
	while (i < WINY)
	{
		c = fmin(pow(sqrt(pow((i - WINY / 2) * 1.5, 2) + pow(x - WINX / 2, 2)) / WINY, 2), 1); //$
		// c = 1;	//? 
		//$
		if (i < top)
			my_pixel_put(&d->buff[d->frame % 2], x, i, more_red(ft_add_shade2(
				0x00888888, (double)(i) / (WINY / 520.0) + 1), c * d->p.dmg_intensity));
		else if (i < bot)
			my_pixel_put(&d->buff[d->frame % 2], x, i, more_red(get_wall_color(
				wall, d, (double)(i - top) / h), c * d->p.dmg_intensity)); //! cette ligne est lente sur mac42
		else
			my_pixel_put(&d->buff[d->frame % 2], x, i, more_red(ft_add_shade2(
				0x007f692a, (double)(WINY - i) / (WINY / 520.0) + 1), c * d->p.dmg_intensity));
		//$
		//?
		if (i < top)
			my_pixel_put(&d->buff[d->frame % 2], x, i, ft_add_shade2(
				0x00888888, (double)(i) / (WINY / 520.0) + 1));
		else if (i < bot)
			my_pixel_put(&d->buff[d->frame % 2], x, i, get_wall_color(
				wall, d, (double)(i - top) / h)); //! cette ligne est lente sur mac42
		else
			my_pixel_put(&d->buff[d->frame % 2], x, i, ft_add_shade2(
				0x007f692a, (double)(WINY - i) / (WINY / 520.0) + 1));
		//?
		i++;
	}
}

void update_view( t_data *d )
{
	int x;
	double angle;
	double dangle;

	x = 0;
	angle = d->p.angle - to_rad(FOV / 2);
	dangle = to_rad(FOV) / WINX;
	while (x < WINX)
	{
		update_column(x, angle + (dangle * x), d);
		x++;
	}
}
