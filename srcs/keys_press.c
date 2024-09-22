/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_press.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:01:03 by cumoncoq          #+#    #+#             */
/*   Updated: 2024/06/24 22:58:24 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void press_move(int keysym, t_data *d)
{
	if (keysym == Z_KEY || keysym == W_KEY)
	{
		d->k.move_fb += forward;
	}
	else if (keysym == S_KEY)
	{
		d->k.move_fb += backward;
	}
	else if (keysym == A_KEY || keysym == Q_KEY)
	{
		d->k.move_lr += leftward;
	}
	else if (keysym == D_KEY)
	{
		d->k.move_lr += rightward;
	}
}

void press_turn(int keysym, t_data *d)
{
	if (keysym == LEFT_KEY)
	{
		d->k.turn += left;
	}
	else if (keysym == RIGHT_KEY)
	{
		d->k.turn += right;
	}
}

int	ft_keypress(int keysym, t_data *d)
{
	if (keysym == ESC_KEY)
		ft_clean_exit(d);
	else if (keysym == W_KEY || keysym == A_KEY || keysym == S_KEY
			|| keysym == D_KEY || keysym == Z_KEY || keysym == Q_KEY)
		press_move(keysym, d);
	else if (keysym == LEFT_KEY || keysym == RIGHT_KEY)
		press_turn(keysym, d);
	else if (keysym == SPACE_KEY)
	{
		d->k.action = 1;
		switch_press(d);
	}
	else if (keysym == P_KEY)
	{
		d->k.pause = 1;
	}
	return (0);
}

int ft_mouse_press( int button, int x, int y, t_data *d)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		d->k.action = 1;
		switch_press(d);
	}
	return (0);
}

void handle_mouse( t_data *d )
{
	int x;
	int y;
	double p;

	mlx_mouse_get_pos(d->mlx, d->win, &x, &y);
	p = (double)(x - (WINX / 2)) / (WINX / 2);
	// d->p.angle = d->p.body_angle + to_rad(10) * p;
	d->p.angle = d->p.body_angle + to_rad(180) * p;
	if (x > WINX)
	{
		printf("mouse moved right %f\n", p);
		mlx_mouse_move(d->mlx, d->win, 0, WINY / 2);
	}
	else if (x < 0)
	{
		printf("mouse moved left %f\n", p);
		mlx_mouse_move(d->mlx, d->win, WINX, WINY / 2);
	}
}
