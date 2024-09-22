/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:34:16 by cumoncoq          #+#    #+#             */
/*   Updated: 2024/06/25 02:47:28 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void data_to_zero(t_data *d)
{
	d->g.exit = 0;
	d->g.left = 0;
	d->g.finished = 0;
	d->k.move_fb = no_move_fb;
	d->k.move_lr = no_move_lr;
	d->k.turn = no_turn;
	d->monster_pos.x = 28.5;
	d->monster_pos.y = 3.5;
}

void ft_init_game_data(t_data *d)
{
	int x;
	int y;
	int longest_line;

	y = 0;
	longest_line = 0;
	while (d->map[y])
	{
		x = 0;
		while (d->map[y][x])
			x++;
		if (x > longest_line)
			longest_line = x;
		y++;
	}
	d->g.mapx = longest_line;
	d->g.mapy = y;
	data_to_zero(d);
}

int is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

double get_angle(char c)
{
	if (c == 'N')
		return (to_rad(270));
	if (c == 'S')
		return (to_rad(90));
	if (c == 'E')
		return (to_rad(0));
	if (c == 'W')
		return (to_rad(180));
	return (0);
}

void ft_init_player_data(t_data *d)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (d->map[i])
	{
		while (d->map[i][j])
		{
			if (is_player(d->map[i][j]))
			{
				d->p.x = j + 0.5;	//todo))		add 0.5 to center player in the square
				d->p.y = i + 0.5;	//todo))		add 0.5 to center player in the square
				d->p.fov = 60;
				d->p.health = HEALTH;
				d->p.body_angle = get_angle(d->map[i][j]);
				break ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}


void init_images_ptr( t_data *d )
{
	d->t.n.img = XPMLOAD(d->mlx, "textures/backroom.xpm", &d->t.n.w, &d->t.n.h);
	d->t.s.img = XPMLOAD(d->mlx, "textures/backroom.xpm", &d->t.s.w, &d->t.s.h);
	d->t.w.img = XPMLOAD(d->mlx, "textures/backroom2.xpm", &d->t.w.w, &d->t.w.h);
	d->t.e.img = XPMLOAD(d->mlx, "textures/backroom2.xpm", &d->t.e.w, &d->t.e.h);
	d->t.action.img = XPMLOAD(d->mlx, "textures/hand.xpm", &d->t.action.w, &d->t.action.h);
	d->t.door_ns.img = XPMLOAD(d->mlx, "textures/door_ns.xpm", &d->t.door_ns.w, &d->t.door_ns.h);
	d->t.door_ew.img = XPMLOAD(d->mlx, "textures/door_ew.xpm", &d->t.door_ew.w, &d->t.door_ew.h);
	d->t.monster[0].img = XPMLOAD(d->mlx, "textures/monster_0.xpm", &d->t.monster[0].w, &d->t.monster[0].h);
	d->t.monster[1].img = XPMLOAD(d->mlx, "textures/monster_1.xpm", &d->t.monster[1].w, &d->t.monster[1].h);
	d->t.monster[2].img = XPMLOAD(d->mlx, "textures/monster_2.xpm", &d->t.monster[2].w, &d->t.monster[2].h);
	d->t.swi[0][0].img = XPMLOAD(d->mlx, "textures/switch_0_light.xpm", &d->t.swi[0][0].w, &d->t.swi[0][0].h);
	d->t.swi[0][1].img = XPMLOAD(d->mlx, "textures/switch_1_light.xpm", &d->t.swi[0][1].w, &d->t.swi[0][1].h);
	d->t.swi[0][2].img = XPMLOAD(d->mlx, "textures/switch_2_light.xpm", &d->t.swi[0][2].w, &d->t.swi[0][2].h);
	d->t.swi[1][0].img = XPMLOAD(d->mlx, "textures/switch_0_dark.xpm", &d->t.swi[1][0].w, &d->t.swi[1][0].h);
	d->t.swi[1][1].img = XPMLOAD(d->mlx, "textures/switch_1_dark.xpm", &d->t.swi[1][1].w, &d->t.swi[1][1].h);
	d->t.swi[1][2].img = XPMLOAD(d->mlx, "textures/switch_2_dark.xpm", &d->t.swi[1][2].w, &d->t.swi[1][2].h);
}

void init_switch(t_data *d)
{
	int i;
	int j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 3)
		{
			d->t.swi[i][j].addr = mlx_get_data_addr(d->t.swi[i][j].img, &d->t.swi[i][j].bpp, &d->t.swi[i][j].l, &d->t.swi[i][j].e);
			j++;
		}
		i++;
	}
}

void init_imgs(t_data *d)
{
	//todo)) add to garbage collector to free
	// printf("map size x = %d, y = %d MINI %d\n", d->g.mapx, d->g.mapy, MSCALE);
	d->t.n.addr = mlx_get_data_addr(d->t.n.img, &d->t.n.bpp, &d->t.n.l, &d->t.n.e);
	d->t.s.addr = mlx_get_data_addr(d->t.s.img, &d->t.s.bpp, &d->t.s.l, &d->t.s.e);
	d->t.w.addr = mlx_get_data_addr(d->t.w.img, &d->t.w.bpp, &d->t.w.l, &d->t.w.e);
	d->t.e.addr = mlx_get_data_addr(d->t.e.img, &d->t.e.bpp, &d->t.e.l, &d->t.e.e);
	d->t.action.addr = mlx_get_data_addr(d->t.action.img, &d->t.action.bpp, &d->t.action.l, &d->t.action.e);
	if (d->t.door_ns.img)
		d->t.door_ns.addr = mlx_get_data_addr(d->t.door_ns.img, &d->t.door_ns.bpp, &d->t.door_ns.l, &d->t.door_ns.e);
	if (d->t.door_ew.img)
		d->t.door_ew.addr = mlx_get_data_addr(d->t.door_ew.img, &d->t.door_ew.bpp, &d->t.door_ew.l, &d->t.door_ew.e);
	if (d->t.monster[0].img)
		d->t.monster[0].addr = mlx_get_data_addr(d->t.monster[0].img, &d->t.monster[0].bpp, &d->t.monster[0].l, &d->t.monster[0].e);
	if (d->t.monster[1].img)
		d->t.monster[1].addr = mlx_get_data_addr(d->t.monster[1].img, &d->t.monster[1].bpp, &d->t.monster[1].l, &d->t.monster[1].e);
	if (d->t.monster[2].img)
		d->t.monster[2].addr = mlx_get_data_addr(d->t.monster[2].img, &d->t.monster[2].bpp, &d->t.monster[2].l, &d->t.monster[2].e);
	init_switch(d);
}

void init_buff(t_data *d)
{
	d->buff[0].img = mlx_new_image(d->mlx, WINX, WINY);
	d->buff[1].img = mlx_new_image(d->mlx, WINX, WINY);
	//todo)) add to garbage collector to free
	// printf("map size x = %d, y = %d MINI %d\n", d->g.mapx, d->g.mapy, MSCALE);
	d->buff[0].addr = mlx_get_data_addr(d->buff[0].img, &d->buff[0].bpp,
			&d->buff[0].l, &d->buff[0].e);
	d->buff[1].addr = mlx_get_data_addr(d->buff[1].img, &d->buff[1].bpp,
			&d->buff[1].l, &d->buff[1].e);
}
