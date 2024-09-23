/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_check2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:40:43 by mbest             #+#    #+#             */
/*   Updated: 2024/09/22 18:51:57 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mat.h"

// int ft_check_floor(t_data *d, int i)
// {
// 	int r;
// 	int g;
// 	int b;
// 	char **rgb;
	
// 	if (ft_strncmp(d->i_map[i], "F ", 2) == 0)
// 	{
// 		rgb = ft_split(d->i_map[i] + 2, ',');
// 		if (rgb == NULL || ft_tab_len(rgb) != 3)
// 		{
// 			printf("Invalid floor color format...\n"); //? Clean rgb if split worked but len != 3
// 			return (0);
// 		}
// 		r = ft_atoi(rgb[0]);
// 		g = ft_atoi(rgb[1]);
// 		b = ft_atoi(rgb[2]);
// 		if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
// 		{
// 			printf("Invalid floor color values...\n");
// 			return (0);
// 		}
// 		return (1);
// 	}
// 	return (0);
// }

// int ft_check_ceiling(t_data *d, int i)
// {
// 	int r;
// 	int g;
// 	int b;
// 	char **rgb;
	
// 	if (ft_strncmp(d->i_map[i], "C ", 2) == 0)
// 	{
// 		rgb = ft_split(d->i_map[i] + 2, ',');
// 		if (rgb == NULL || ft_tab_len(rgb) != 3)
// 		{
// 			printf("Invalid ceiling color format...\n"); //? Clean rgb if split worked but len != 3
// 			return (0);
// 		}
// 		r = ft_atoi(rgb[0]);
// 		g = ft_atoi(rgb[1]);
// 		b = ft_atoi(rgb[2]);
// 		if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
// 		{
// 			printf("Invalid ceiling color values...\n");
// 			return (0);
// 		}
// 		return (1);
// 	}
// 	return (0);
// }

// void ft_check_valid_info(t_data *d)
// {
// 	int i;
// 	int flag; // helper for the orientation NO, SO ...
// 	char *path;

// 	i = 0;
// 	flag = 0;
// 	printf("Checking map info...\n");
// 	while (d->i_map[i] && flag < 6)
// 	{
// 		if (is_blank(d->i_map[i]))
// 			i++;
// 		else if(ft_valid_textures(d, i, &flag))
// 		{
// 			i++;
// 			flag ++;
// 		}
// 		else
// 		{
// 			printf("Error in the map info...\n");
// 			exit(EXIT_FAILURE); //! CLEAN EXIT
// 		}
// 	}
// }
