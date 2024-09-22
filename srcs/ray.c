/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 00:41:54 by cumoncoq          #+#    #+#             */
/*   Updated: 2024/06/25 18:01:20 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
get ray distance between player and first vertical side
*/
double vertical_wall_distance( t_data *d, t_vec cos_sin )
{
	// double	dist;
	double	dist_x;
	double	dist_y;
	if (cos_sin.x > EPSILON)
	{
		// printf("cos_sin.x > 0\n");	//?
		dist_x = upper_int(d->p.x) - d->p.x;
		dist_y = y_from_x(dist_x, cos_sin);
	}
	else if (cos_sin.x < -EPSILON)
	{
		// printf("cos_sin.x < 0\n");	//?
		dist_x = d->p.x - lower_int(d->p.x);
		dist_y = y_from_x(dist_x, cos_sin);
	}
	else
	{
		// printf("cos_sin.x = 0\n");	//?
		return (0);
	}
	return (sqrt(pow(dist_x, 2) + pow(dist_y, 2)));
	// return (dist);
}

/*
get ray distance between player and first horizontal side
*/
double horizontal_wall_distance( t_data *d, t_vec cos_sin)
{
	// double	dist;
	double	dist_x;
	double	dist_y;
	if (cos_sin.y > EPSILON)
	{
		dist_y = upper_int(d->p.y) - d->p.y;
		dist_x = x_from_y(dist_y, cos_sin);
	}
	else if (cos_sin.y < -EPSILON)
	{
		dist_y = d->p.y - lower_int(d->p.y);
		dist_x = x_from_y(dist_y, cos_sin);
	}
	else
	{
		return (0);
	}
	return (sqrt(pow(dist_x, 2) + pow(dist_y, 2)));
	// return (dist);
}

double get_y_coord( t_data *d, int x_count, t_vec cos_sin )
{
	double x_dist;
	double y_dist;
	if (cos_sin.x > 0)
	{
		x_dist = upper_int(d->p.x) - d->p.x + x_count;
	}
	else
	{
		x_dist = d->p.x - lower_int(d->p.x) + x_count;
	}
	y_dist = y_from_x(x_dist, cos_sin);
	if (cos_sin.y > 0 && y_dist < 0)
		y_dist *= -1;
	else if (cos_sin.y < 0 && y_dist > 0)
		y_dist *= -1;
	return (d->p.y + y_dist);
}

int is_wall_vertical( t_data *d, int x_count, t_wall *wall, t_vec cos_sin )
{
	// t_vec vec;
	t_tuple coords;
	// vec = get_vec(angle);
	if (cos_sin.x > 0)
	{
		coords.x = (int)d->p.x + x_count + 1;
	}
	else
	{
		coords.x = (int)d->p.x - x_count - 1;
	}
	coords.y = (int)get_y_coord(d, x_count, cos_sin);
	if (coords.x >= d->g.mapx || coords.y >= d->g.mapy)
		return (1);
	// printf("vertical n°%d map[%zu][%zu]\n", x_count, coords.x, coords.y);	//?
	//todo protect segfault with mapx and mapy
	if (char_is_wall(d->map[coords.y][coords.x]))
	{
		set_wall_type(wall, d->map[coords.y][coords.x]);
		return (1);
	}
	else
	{
		return (0);
	}
	return (1);
	// if (d->map[coords.y][coords.x] == '1' || d->map[coords.y][coords.x] == ' ')
	// {
	// 	wall->type = is_wall;
	// }
	// else if (d->map[coords.y][coords.x] == 'D')
	// {
	// 	wall->type = is_door;
	// }
	// else
	// {
	// 	return (0);
	// }
	// return (1);
}

double get_x_coord( t_data *d, int y_count, t_vec cos_sin )
{
	double y_dist;
	double x_dist;
	// printf(_RED "sin(%f) = %f\n" _RESET, to_deg(angle), cos_sin.y);	//?
	if (cos_sin.y > 0)
	{
		y_dist = upper_int(d->p.y) - d->p.y + y_count;
	}
	else
	{
		y_dist = d->p.y - lower_int(d->p.y) + y_count;
	}
	x_dist = x_from_y(y_dist, cos_sin);
	if (cos_sin.x > 0 && x_dist < 0)
		x_dist *= -1;
	else if (cos_sin.x < 0 && x_dist > 0)
		x_dist *= -1;
	// printf(_RED "y_dist = %f, x_dist = %f\n" _RESET, y_dist, x_dist);	//?
	return (d->p.x + x_dist);

}

int is_wall_horizontal( t_data *d, int y_count, t_wall *wall, t_vec cos_sin )
{
	// t_vec vec;
	t_tuple coords;
	// vec = get_vec(angle);
	// printf("horizontal n°%d\n", y_count);	//?
	if (cos_sin.y > 0)
	{
		coords.y = (int)d->p.y + y_count + 1;
	}
	else
	{
		coords.y = (int)d->p.y - y_count - 1;
	}
	coords.x = (int)get_x_coord(d, y_count, cos_sin);
	// printf("horizontal n°%d map[%zu][%zu]\n", y_count, coords.x, coords.y);	//?
	if (coords.x >= d->g.mapx || coords.y >= d->g.mapy)
		return (1);
	//todo protect segfault with mapx and mapy
	// if (d->map[coords.y][coords.x] == '1' || d->map[coords.y][coords.x] == ' ')
	// {
	// 	wall->type = is_wall;
	// }
	// else if (d->map[coords.y][coords.x] == 'D')
	// {
	// 	wall->type = is_door;
	// }
	if (char_is_wall(d->map[coords.y][coords.x]))
	{
		set_wall_type(wall, d->map[coords.y][coords.x]);
		return (1);
	}
	else
	{
		return (0);
	}
	return (1);
}

void set_wall_type( t_wall *wall, char c )
{
	if (c == '1')
		wall->type = is_wall;
	else if (c == 'D')
		wall->type = is_door;
	else if (c == 'X')
		wall->type = is_switch_off;
	else if (c == 'x')
		wall->type = is_switch_mid;
	else if (c == '+')
		wall->type = is_switch_on;
	else
		wall->type = is_wall;
}

double horizontal_ray( t_data *d, t_tuple *coords, t_wall *wall, t_vec cos_sin )
{
	double dist;

	coords->x = (int)d->p.x;
	coords->y = (int)d->p.y;
	if (cos_sin.x >= EPSILON)
	{
		dist = upper_int(d->p.x) - d->p.x;
		wall->dir = east;
	}
	else if (cos_sin.x <= -EPSILON)
	{
		dist = d->p.x - lower_int(d->p.x);
		wall->dir = west;
	}
	while (1)
	{
		if (cos_sin.x >= EPSILON)
			coords->x++;
		else if (cos_sin.x <= -EPSILON)
			coords->x--;
		if (char_is_wall(d->map[coords->y][coords->x]))
			return (set_wall_type(wall, d->map[coords->y][coords->x]), dist);
		// if (d->map[coords->y][coords->x] == 'D')
		// 	return (set_wall_type(wall, d->map[coords->y][coords->x]), dist);	//todo)) create a set wall type function for norm
		dist += 1;
	}
	return (0);
}

double vertical_ray( t_data *d, t_tuple *coords, t_wall *wall, t_vec cos_sin )
{
	double dist;

	coords->x = (int)d->p.x;
	coords->y = (int)d->p.y;
	if (cos_sin.y >= EPSILON)
	{
		dist = upper_int(d->p.y) - d->p.y;
		wall->dir = south;
	}
	else if (cos_sin.y <= -EPSILON)
	{
		dist = d->p.y - lower_int(d->p.y);
		wall->dir = north;
	}
	while (1)
	{
		if (cos_sin.y >= EPSILON)
			coords->y++;
		else if (cos_sin.y <= -EPSILON)
			coords->y--;
		if (char_is_wall(d->map[coords->y][coords->x]))
			return (set_wall_type(wall, d->map[coords->y][coords->x]), dist);
		// if (d->map[coords->y][coords->x] == 'D')
		// 	return (set_wall_type(wall, d->map[coords->y][coords->x]), dist);
		dist += 1;
	}
	return (0);
}

t_wall	resolve_90_ray( t_data *d, t_vec cos_sin)
{
	t_wall wall;
	double dist;
	t_tuple coords;

	dist = 0;
	// //?
	// wall.column = 0.5;
	// wall.dir = north;
	// wall.dist = 10.0;
	// wall.type = is_door;
	// return (wall);
	// //?
	if (fabs(cos_sin.x) >= EPSILON)
		dist = horizontal_ray(d, &coords, &wall, cos_sin);
	else if (fabs(cos_sin.y) >= EPSILON)
		dist = vertical_ray(d, &coords, &wall, cos_sin);
	if (cos_sin.x >= EPSILON)
		wall.column = d->p.y - (int)d->p.y;
	else if (cos_sin.x <= -EPSILON)
		wall.column = (int)d->p.y + 1 - d->p.y;
	else if (cos_sin.y >= EPSILON)
		wall.column = d->p.x - (int)d->p.x;
	else if (cos_sin.y <= -EPSILON)
		wall.column = (int)d->p.x + 1 - d->p.x;

	wall.dist = dist;
	return (wall);
}

// void check_vertical( t_data *d, double angle, t_wall *wall, t_tuple  count )
// {
// 	double dist;

// 	dist = vertical_ray(d, angle, coords, wall);
// 	if (dist < wall->dist)
// 	{
// 		wall->dist = dist;
// 		wall->column = (d->p.y + y_from_x(angle, dist)) - (int)(d->p.y + y_from_x(angle, dist));
// 		if (cos_sin.x >= EPSILON)
// 			wall->dir = east;
// 		else if (cos_sin.x <= -EPSILON)
// 			wall->dir = west;
// 	}
// }

// todo)) make fisheye correction with x
// todo)) fix 90° angle bug
t_wall throw_ray( t_data *d, double angle)
{
	t_wall wall;
	t_vec dist;
	t_vec step;
	t_tuple count;
	t_vec cos_sin;

	cos_sin = get_vec(angle);
	if (fabs(cos_sin.x) < EPSILON || fabs(cos_sin.y) < EPSILON)
		return(resolve_90_ray(d, cos_sin));
	dist = fill_t_vec(vertical_wall_distance(d, cos_sin), horizontal_wall_distance(d, cos_sin));
	step = fill_t_vec(sqrt(pow(y_from_x(1, cos_sin), 2) + 1), sqrt(pow(x_from_y(1, cos_sin), 2) + 1));
	count = fill_t_tuple(0, 0);
	// printf(_RED "angle = %f | cos = %f | sin = %f\n" _RESET, to_deg(angle), cos_sin.x, cos_sin.y);
	// printf(_GREEN "distv = %f\n" _RESET, dist.x);
	// printf(_RED "disth = %f\n" _RESET, dist.y);
	// printf(_GREEN "stepv = %f\n" _RESET, step.x);
	// printf(_RED "steph = %f\n" _RESET, step.y);
	while (1)
	{
		// printf(_GREEN "---------------------\n" _RESET);
		// printf("dist.x = %f | dist.y = %f\n", dist.x, dist.y);
		if (dist.x < dist.y)
		{
			if (is_wall_vertical(d, count.x, &wall, cos_sin))
			{
				// printf(_GREEN "\nvertical wall found\n" _RESET);
				wall.dist = dist.x;
				wall.column = get_y_coord( d, count.x, cos_sin) - (int)get_y_coord( d, count.x, cos_sin);
				if (cos_sin.x < 0)
				{
					wall.column = 1 - wall.column;
					wall.dir = west;
				}
				else
					wall.dir = east;				
				return (wall);
			}
			dist.x += step.x;
			count.x++;
		}
		else
		{
			if (is_wall_horizontal(d, count.y, &wall, cos_sin))
			{
				// printf(_GREEN "\nhorizontal wall found\n" _RESET);
				wall.dist = dist.y;
				wall.column = get_x_coord( d, count.y, cos_sin) - (int)get_x_coord( d, count.y, cos_sin);
				if (cos_sin.y < 0)
				{
					wall.column = 1 - wall.column;
					wall.dir = north;
				}
				else
					wall.dir = south;
				return (wall);
			}
			dist.y += step.y;
			count.y++;
		}
	}
	
	return (wall);
}
