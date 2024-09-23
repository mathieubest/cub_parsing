/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbest <mbest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:36:07 by mbest             #+#    #+#             */
/*   Updated: 2024/07/04 16:35:52 by mbest            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mat.h"

// int ft_check_north(t_data *d, int i)
// {
// 	char *path;
	
// 	if (ft_strncmp(d->i_map[i], "NO ", 3))
// 	{
// 		path = d->i_map[i] + 3;
// 		d->t.n.img = XPMLOAD(d->mlx, path, &d->t.n.w, &d->t.n.h);
// 		if (d->t.n.img != NULL)
// 		{
// 			printf("North texture path: %s", path);
// 			return (1);
// 		}
// 		else
// 		{
// 			printf("Failed to load North texture...\n");
// 			return (0);
// 		}
// 	}
// }

// int ft_check_south(t_data *d, int i)
// {
// 	char *path;
	
// 	if (ft_strncmp(d->i_map[i], "SO ", 3))
// 	{
// 		path = d->i_map[i] + 3;
// 		d->t.s.img = XPMLOAD(d->mlx, path, &d->t.s.w, &d->t.s.h);
// 		if (d->t.s.img != NULL)
// 		{
// 			printf("South texture path: %s", path);
// 			return (1);
// 		}
// 		else
// 		{
// 			printf("Failed to load South texture...\n");
// 			return (0);
// 		}
// 	}
// }

// int ft_check_west(t_data *d, int i)
// {
// 	char *path;
	
// 	if (ft_strncmp(d->i_map[i], "WE ", 3))
// 	{
// 		path = d->i_map[i] + 3;
// 		d->t.w.img = XPMLOAD(d->mlx, path, &d->t.w.w, &d->t.w.h);
// 		if (d->t.w.img != NULL)
// 		{
// 			printf("West texture path: %s", path);
// 			return (1);
// 		}
// 		else
// 		{
// 			printf("Failed to load West texture...\n");
// 			return (0);
// 		}
// 	}
// }

// int ft_check_east(t_data *d, int i)
// {
// 	char *path;
	
// 	if (ft_strncmp(d->i_map[i], "EA ", 3))
// 	{
// 		path = d->i_map[i] + 3;
// 		d->t.e.img = XPMLOAD(d->mlx, path, &d->t.e.w, &d->t.e.h);
// 		if (d->t.e.img != NULL)
// 		{
// 			printf("East texture path: %s", path);
// 			return (1);
// 		}
// 		else
// 		{
// 			printf("Failed to load East texture...\n");
// 			return (0);
// 		}
// 	}
// }

// int ft_valid_textures(t_data *d, int i, int *flag)
// {
// 	char *path;
	
// 	if (*flag == 0)
// 		return (ft_check_north(d, i));
// 	else if (*flag == 1)
// 		return (ft_check_south(d, i));
// 	else if (*flag == 2)
// 		return (ft_check_west(d, i));
// 	else if (*flag == 3)
// 		return (ft_check_east(d, i));
// 	else if (*flag == 4)
// 		return (ft_check_floor(d, i));
// 	else if (*flag == 5)
// 		return (ft_check_ceiling(d, i));
// 	else
// 		return (0);
// }
