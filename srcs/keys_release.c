/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_release.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:01:03 by cumoncoq          #+#    #+#             */
/*   Updated: 2024/06/24 19:19:50 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void release_move(int keysym, t_data *d)
{	
	if (keysym == Z_KEY || keysym == W_KEY)
	{
		d->k.move_fb -= forward;
	}
	else if (keysym == S_KEY)
	{
		d->k.move_fb -= backward;
	}
	else if (keysym == A_KEY || keysym == Q_KEY)
	{
		d->k.move_lr -= leftward;
	}
	else if (keysym == D_KEY)
	{
		d->k.move_lr -= rightward;
	}
}

void release_turn(int keysym, t_data *d)
{
	if (keysym == LEFT_KEY)
	{
		d->k.turn -= left;
	}
	else if (keysym == RIGHT_KEY)
	{
		d->k.turn -= right;
	}
}

int	ft_keyrelease(int keysym, t_data *d)
{
	if (keysym == W_KEY || keysym == A_KEY || keysym == S_KEY
			|| keysym == D_KEY || keysym == Z_KEY || keysym == Q_KEY)
		release_move(keysym, d);
	else if (keysym == LEFT_KEY || keysym == RIGHT_KEY)
		release_turn(keysym, d);
	else if (keysym == SPACE_KEY)
	{
		d->k.action = 0;
		switch_release(d);
		open_door(d);
	}
	else if (keysym == P_KEY)
	{
		d->k.pause = 0;
	}
	return (0);
}

int ft_mouse_release( int button, int x, int y, t_data *d)
{
	(void)x;
	(void)y;
	printf("button = %d\n", button);
	if (button == 1)
	{
		d->k.action = 0;
		switch_release(d);
		open_door(d);
	}
	return (0);
}
