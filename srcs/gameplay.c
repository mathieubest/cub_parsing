/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 02:11:06 by cumoncoq          #+#    #+#             */
/*   Updated: 2024/06/25 03:38:24 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void open_door(t_data *d)
{
	t_wall wall;
	t_vec coords;

	coords.x = d->p.x;
	coords.y = d->p.y;
	wall = throw_ray(d, d->p.angle);
	printf("wall type %d, dist %f\n", wall.type, wall.dist);
	if (wall.type == is_door && wall.dist < 1.5)
	{
		coords.x += cos(d->p.angle) * wall.dist;
		coords.y += sin(d->p.angle) * wall.dist;
		if (wall.dir == north)
			coords.y -= 0.5;
		else if (wall.dir == south)
			coords.y += 0.5;
		else if (wall.dir == east)
			coords.x += 0.5;
		else if (wall.dir == west)
			coords.x -= 0.5;
		d->map[(int)coords.y][(int)coords.x] = 'O';
	}
}

void switch_press(t_data *d)
{
	t_wall wall;
	t_vec coords;

	coords.x = d->p.x;
	coords.y = d->p.y;
	wall = throw_ray(d, d->p.angle);
	if (wall.type == is_switch_off && wall.dist < 1.5)
	{
		coords.x += cos(d->p.angle) * wall.dist;
		coords.y += sin(d->p.angle) * wall.dist;
		if (wall.dir == north)
			coords.y -= 0.5;
		else if (wall.dir == south)
			coords.y += 0.5;
		else if (wall.dir == east)
			coords.x += 0.5;
		else if (wall.dir == west)
			coords.x -= 0.5;
		d->map[(int)coords.y][(int)coords.x] = 'x';
	}
}

void switch_release(t_data *d)
{
	t_wall wall;
	t_vec coords;

	coords.x = d->p.x;
	coords.y = d->p.y;
	wall = throw_ray(d, d->p.angle);
	if (wall.type == is_switch_mid && wall.dist < 1.5)
	{
		coords.x += cos(d->p.angle) * wall.dist;
		coords.y += sin(d->p.angle) * wall.dist;
		if (wall.dir == north)
			coords.y -= 0.5;
		else if (wall.dir == south)
			coords.y += 0.5;
		else if (wall.dir == east)
			coords.x += 0.5;
		else if (wall.dir == west)
			coords.x -= 0.5;
		d->map[(int)coords.y][(int)coords.x] = '+';
		d->g.left--;
	}
}

void check_health( t_data *d, double i )
{
	d->p.health -= fmax(i * i, 0) * DAMAGE;
	// printf("Health: %f - %f\n", d->p.health, fmax(i * i, 0));
	if (d->p.health <= 0)
	{
		// while (++e < 200)
		// {
		// 	mlx_string_put(d->mlx, d->win, WINX / 2 - 50, WINY / 2, 0x00FFFFFF, "You died");
		// 	usleep(10000);
		// }
		ft_clean_exit(d);
	}
}
