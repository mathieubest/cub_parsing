/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 00:59:30 by cumoncoq          #+#    #+#             */
/*   Updated: 2024/06/24 00:09:31 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_add_shade(int trgb, int shade)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = (((unsigned char *)&trgb)[3]) - shade;
	r = (((unsigned char *)&trgb)[2]) - shade;
	g = (((unsigned char *)&trgb)[1]) - shade;
	b = (((unsigned char *)&trgb)[0]) - shade;
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

int	ft_add_shade2(int trgb, int shade)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = (((unsigned char *)&trgb)[3]) - (shade * ((double)((unsigned char *)&trgb)[3] / 255));
	r = (((unsigned char *)&trgb)[2]) - (shade * ((double)((unsigned char *)&trgb)[2] / 255));
	g = (((unsigned char *)&trgb)[1]) - (shade * ((double)((unsigned char *)&trgb)[1] / 255));
	b = (((unsigned char *)&trgb)[0]) - (shade * ((double)((unsigned char *)&trgb)[0] / 255));
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

int	ft_div_shade(int trgb, double shade)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = (((unsigned char *)&trgb)[3]) / shade;
	r = (((unsigned char *)&trgb)[2]) / shade;
	g = (((unsigned char *)&trgb)[1]) / shade;
	b = (((unsigned char *)&trgb)[0]) / shade;
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return (*(int *)(unsigned char [4]){b, g, r, t});
}


int	ft_add_light(int trgb, int shade)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = (((unsigned char *)&trgb)[3]) + shade;
	r = (((unsigned char *)&trgb)[2]) + shade;
	g = (((unsigned char *)&trgb)[1]) + shade;
	b = (((unsigned char *)&trgb)[0]) + shade;
	if (t > 255)
		t = 255;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return (*(int *)(unsigned char [4]){b, g, r, t});
}
