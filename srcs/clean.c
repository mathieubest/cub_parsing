/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:25:12 by cumoncoq          #+#    #+#             */
/*   Updated: 2024/06/24 04:25:04 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mlx_destroy(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
	return (0);
}

void free_map(char **map)
{
	int i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void free_imgs(t_data *data)
{
	mlx_destroy_image(data->mlx, data->t.n.img);
	mlx_destroy_image(data->mlx, data->t.s.img);
	mlx_destroy_image(data->mlx, data->t.w.img);
	mlx_destroy_image(data->mlx, data->t.e.img);
	mlx_destroy_image(data->mlx, data->t.door_ns.img);
	mlx_destroy_image(data->mlx, data->t.door_ew.img);
	mlx_destroy_image(data->mlx, data->t.monster[0].img);
	mlx_destroy_image(data->mlx, data->t.monster[1].img);
	mlx_destroy_image(data->mlx, data->t.monster[2].img);
	mlx_destroy_image(data->mlx, data->t.swi[0][0].img);
	mlx_destroy_image(data->mlx, data->t.swi[0][1].img);
	mlx_destroy_image(data->mlx, data->t.swi[0][2].img);
	mlx_destroy_image(data->mlx, data->t.swi[1][0].img);
	mlx_destroy_image(data->mlx, data->t.swi[1][1].img);
	mlx_destroy_image(data->mlx, data->t.swi[1][2].img);
}

int ft_clean_exit(t_data *data)
{
	free_imgs(data);
	free_map(data->map);
	ft_mlx_destroy(data);
	exit(0);
	return (0);
}

void ft_error_exit(t_data *data)
{
	free_map(data->map);
	ft_mlx_destroy(data);
	free(data->minimap[0].img);
	free(data->minimap[1].img);
	exit(1);
}
