/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:28:44 by cumoncoq          #+#    #+#             */
/*   Updated: 2024/06/25 18:58:17 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_turn(t_data *d)
{
	if (d->k.turn == left)
		d->p.body_angle -= to_rad(3);
	if (d->k.turn == right)
		d->p.body_angle += to_rad(3);
}

void calculate_move( t_data *d, double *x, double *y )
{
	*x = d->p.x;
	*y = d->p.y;
	if (d->k.move_fb == forward)
	{
		*x += cos(d->p.angle) * 0.1;
		*y += sin(d->p.angle) * 0.1;
	}
	else if (d->k.move_fb == backward)
	{
		*x -= cos(d->p.angle) * 0.1;
		*y -= sin(d->p.angle) * 0.1;
	}
	if (d->k.move_lr == leftward)
	{
		*x += cos(d->p.angle - to_rad(90)) * 0.1;
		*y += sin(d->p.angle - to_rad(90)) * 0.1;
	}
	else if (d->k.move_lr == rightward)
	{
		*x += cos(d->p.angle + to_rad(90)) * 0.1;
		*y += sin(d->p.angle + to_rad(90)) * 0.1;
	}
}

int is_walkable(char c)
{
	if (c != '1' && c != 'D' && c != 'X' && c != 'x' && c != '+' && c != ' ')
		return (1);
	return (0);
}

void ft_move(t_data *d)
{
	double x;
	double y;

	x = d->p.x;
	y = d->p.y;
	calculate_move(d, &x, &y);
	if (d->map[(int)d->p.y][(int)d->p.x] == 'O')
	{
		printf("step on opened door\n");
		if (d->map[(int)y][(int)x] != 'O' && is_walkable(d->map[(int)y][(int)x]))
		{
			printf("closed door\n");
			d->map[(int)d->p.y][(int)d->p.x] = 'D';
		}
	}
	if (is_walkable(d->map[(int)y][(int)x]))
	{
		d->p.x = x;
		d->p.y = y;
	}
	else if (is_walkable(d->map[(int)y][(int)d->p.x]))
		d->p.y = y;
	else if (is_walkable(d->map[(int)d->p.y][(int)x]))
		d->p.x = x;
}

//todo)) systeme de rails longeant les 0.5 de chaque case
void move_monster(t_data *d)
{
	double x;
	double y;
	double dist_monster;

	if (!d->p.see_monster)
	{
		x = ((d->monster_pos.x * (100 - MONSTER_SPEED)) + d->p.x * MONSTER_SPEED) / 100;
		y = ((d->monster_pos.y * (100 - MONSTER_SPEED)) + d->p.y * MONSTER_SPEED) / 100;
		d->monster_pos.x = x;
		d->monster_pos.y = y;
	}
	if (!d->p.see_monster || d->k.move_fb || d->k.move_lr)
	{
		dist_monster = (sqrt(pow(d->p.x - d->monster_pos.x, 2) + pow(d->p.y - d->monster_pos.y, 2)));
		d->p.dmg_intensity = fmax(fmin((5 / dist_monster - 1) / 4, 1), 0);
		printf("dmg= %f\n", d->p.dmg_intensity);
	}
}

