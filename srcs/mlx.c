/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:24:33 by cumoncoq          #+#    #+#             */
/*   Updated: 2024/06/24 23:57:34 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mlx_init(t_data *d)
{
	// (void)d; //?
	d->mlx = mlx_init();
	if (!(d->mlx))
		return (1);
	d->win = mlx_new_window(d->mlx, WINX, WINY, "backrooms");
	if (!d->win)
		return (free(d->mlx), 1);
	return (0);
}

void	my_pixel_put(t_buff *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->l + x * (img->bpp / 8));
	if (*(int *)dst != color)				
		*(unsigned int *)dst = color;		//todo)) regler pb de reecriture inutile
}

int	ft_pixel_get(t_buff *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->l + x * (img->bpp / 8));
	return (*(unsigned int *)dst);
}

double	ft_shade_get(t_buff *img, int x, int y)
{
	char	*dst;
	int 	color;
	double	shade;

	dst = img->addr + (y * img->l + x * (img->bpp / 8));
	color = *(unsigned int *)dst;
	color = color & 0x000000FF;
	shade = ((255 - (double)color) / 128);
	if (shade > 1)
		shade *= shade;
	return (shade);
}
