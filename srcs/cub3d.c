/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:09:49 by cumoncoq          #+#    #+#             */
/*   Updated: 2024/06/23 06:51:03umoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void put_img_alpha( t_data *d, double alpha )
{
	int di;
	int dj;

	di = -1;	
	(void)alpha;
	double shade;
	while (++di < MSIZE * MSCALE)
	{
		dj = -1;
		while (++dj < MSIZE * MSCALE)
		{
			if (dj == 0 || dj == MSIZE * MSCALE - 1 || di == 0 || di == MSIZE * MSCALE - 1)
				shade_pixel(d, WINX - (MSCALE * (MSIZE + 1)) + dj, WINY - (1 + MSCALE * (MSIZE + 1)) + di, ((3 - 1) * alpha) + 1);
			else
			{
				shade = ft_shade_get(&d->t.action, ((double)dj / (MSIZE * MSCALE)) * (d->t.action.w), ((double)di / (MSIZE * MSCALE)) * (d->t.action.h));
				shade = ((shade - 1) * alpha) + ((1 - alpha) / 3) + 1;
				shade_pixel(d, WINX - (MSCALE * (MSIZE + 1)) + dj, WINY - (1 + MSCALE * (MSIZE + 1)) + di, shade);
			}
		}
	}
}

void	action_button( t_data *d )
{
	t_wall wall;

	wall = throw_ray(d, d->p.angle);
	if (wall.type == is_door && wall.dist < 1.5 && d->k.action == 0)
		put_img_alpha(d, 1);
	else if (wall.type == is_door && wall.dist < 1.5 && d->k.action == 1)
		put_img_alpha(d, 0.1);
	else if (wall.type == is_switch_off && wall.dist < 1.5)
		put_img_alpha(d, 1);
	else if (wall.type == is_switch_mid && wall.dist < 1.5)
		put_img_alpha(d, 0.1);
	// else
		// put_img_alpha(d, 0.1);
}

void show_controls(t_data *d)
{
	int y;

	y = -80;
	mlx_string_put(d->mlx, d->win, WINX / 2 - 50, WINY / 2 + y, 0x00FFFFFF, "    CONTROLS");
	y += 40;
	mlx_string_put(d->mlx, d->win, WINX / 2 - 50, WINY / 2 + y, 0x00FFFFFF, "  W");
	y += 7;
	mlx_string_put(d->mlx, d->win, WINX / 2 - 50, WINY / 2 + y, 0x00FFFFFF, "          move");
	y += 7;
	mlx_string_put(d->mlx, d->win, WINX / 2 - 50, WINY / 2 + y, 0x00FFFFFF, "A S D");
	y += 30;
	mlx_string_put(d->mlx, d->win, WINX / 2 - 50, WINY / 2 + y, 0x00FFFFFF, "<- ->     turn");
	y += 30;
	mlx_string_put(d->mlx, d->win, WINX / 2 - 50, WINY / 2 + y, 0x00FFFFFF, "SPACE     action");
	y += 30;
	mlx_string_put(d->mlx, d->win, WINX / 2 - 50, WINY / 2 + y, 0x00FFFFFF, "P         pause");
	y += 30;
	mlx_string_put(d->mlx, d->win, WINX / 2 - 50, WINY / 2 + y, 0x00FF0000, "ESC       exit");
}

void pause_game(t_data *d)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (d->k.pause == 1)
	{
		while (i < WINX)
		{
			while (j < WINY)
			{
				shade_pixel(d, i, j, 1.03);
				j++;
			}
			j = 0;
			i++;
		}
	}
	show_controls(d);
}

int potential_switch_neighbour(int x, int y, t_data *d)
{
	if (x < 0 || x >= (int)d->g.mapx || y < 0 || y >= (int)d->g.mapy)
		return (0);
	if (is_walkable(d->map[y][x]))
		return (1);
	return (0);
}

int potential_switch(int x, int y, t_data *d)
{
	int i;

	i = 0;
	if (potential_switch_neighbour(x - 1, y, d))
		i++;
	if (potential_switch_neighbour(x + 1, y, d))
		i++;
	if (potential_switch_neighbour(x, y - 1, d))
		i++;
	if (potential_switch_neighbour(x, y + 1, d))
		i++;
	return (i == 1);
}

// void put_switches_on_map( t_data *d )
// {
// 	int i;
// 	int j;
// 	int s;

// 	i = 0;
// 	j = 0;
// 	while (d->map[i])
// 	{
// 		j = 0;
// 		while (d->map[i][j])
// 		{
// 			if (d->map[i][j] == '1' && potential_switch(j, i, d))
// 			{
// 				if (s % 10 == 0)
// 				{
// 					d->map[i][j] = 'X';
// 					d->g.left++;
// 				}
// 				s++;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

int ft_framerate(t_data *d)
{
	// else
	if (d->k.pause == 0)
	{
		d->frame++;
		if (d->frame >= FPS)
			d->frame = 0;
		ft_turn(d);
		ft_move(d);
		handle_mouse(d);
		pause_game(d);
		update_view(d); //! trop lent pour les macs 42
		shade_minimap(d);
		update_minimap(d, -1, -1);
		action_button(d);
		move_monster(d);
		add_overlay(d, -1, -1);	//! trop lent pour les macs 42
		put_sprite(d, (int)d->monster_pos.x + 0.5, (int)d->monster_pos.y + 0.5);	//todo))
	}
	mlx_clear_window(d->mlx, d->win);
	mlx_put_image_to_window(d->mlx, d->win, d->buff[d->frame % 2].img, 0, 0);
	if (d->k.pause == 1)
		pause_game(d);
		// show_controls(d);
	usleep(10000);//? delete 
	return (0);
}

// int	main( void )
// {
// 	t_data d;

// // create a playable map, replace this with map parsing
// 	d.map = create_map();
// // initialize structs data
// 	ft_init_game_data(&d);
// 	ft_init_player_data(&d);
// // initialize mlx
// 	if (ft_mlx_init(&d))
// 		ft_error_exit(&d);
// 	init_images_tmp(&d);
// 	init_imgs(&d);
// 	init_buff(&d);
// 	put_switches_on_map(&d);
// 	print_map(d.map, &d);
// 	printf("window x = %ld, y = %ld\n", d.g.mapx, d.g.mapy);
// 	printf("-39.414946393618152 = %f\n", to_deg(-39.414946393618152));

// 	mlx_hook(d.win, KeyPress, KeyPressMask, ft_keypress, &d);
// 	mlx_hook(d.win, KeyRelease, KeyReleaseMask, ft_keyrelease, &d);
// 	mlx_hook(d.win, ButtonPress, ButtonPressMask, ft_mouse_press, &d);
// 	mlx_hook(d.win, ButtonRelease, ButtonReleaseMask, ft_mouse_release, &d);
// 	mlx_hook(d.win, DestroyNotify, StructureNotifyMask, ft_clean_exit, &d);
// 	mlx_loop_hook(d.mlx, ft_framerate, &d);
// 	// mlx_mouse_hook(d.win, ft_mouse, &d);
// 	mlx_loop(d.mlx);
// 	ft_clean_exit(&d);
// 	return (0);
// }
