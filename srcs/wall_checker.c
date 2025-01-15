/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbest <mbest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:56:20 by mbest             #+#    #+#             */
/*   Updated: 2025/01/15 14:50:30 by mbest            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mat.h"

int is_player_pos(char **map, int i, int j)
{
	if (map[i][j] == 'N')
	{
		return (1);
	}
	if (map[i][j] == 'S')
	{
		return (1);
	}
	if (map[i][j] == 'E')
	{
		return (1);
	}
	if (map[i][j] == 'W')
	{
		return (1);
	}
	return (0);
}

int ft_check_top_to_bottom(t_data *d, int height, int width)
{
	int i;
	int j;
	int zero_flag;
	int wall_flag;
	int wall_found_after_tile;

	j = 0;
	while (j < width)
	{
		i = 0;
		wall_found_after_tile = -1;
		zero_flag = 0;
		wall_flag = 0;
		while(i < height)
		{
			if (d->map[i][j] == ' ' || is_player_pos(d->map, i, j))
			{
				if (d->map[i][j] == ' ')
					wall_flag = 0;
				if (d->map[i][j] == ' ' && wall_flag != 0 && wall_found_after_tile != 1)
				{
					printf("PROBLEME FOUND");
					exit(EXIT_FAILURE);
				}
				if (is_player_pos(d->map, i, j))
				{
					if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
						return (0);
				}
				i++;
			}
			else if (d->map[i][j] == '0' && wall_flag == 1)
			{
				zero_flag = 1;
				wall_found_after_tile = 0;
				i++;
			}
			else if (d->map[i][j] == '1')
			{
				if (zero_flag == 1)
					wall_found_after_tile = 1;
				wall_flag = 1;
				i++;
			}
			else
			{
				return (0); //? CLEAN EXIT
			}
		}
		if (wall_found_after_tile == 0)
			return (0);
		j++;
	}
	return (1);
}

int ft_check_left_to_right(t_data *d, int height, int width)
{
	int i;
	int j;
	int zero_flag;
	int wall_flag;
	int wall_found_after_tile;

	i = 0;
	while (i < height)
	{
		j = 0;
		wall_found_after_tile = -1;
		zero_flag = 0;
		wall_flag = 0;
		while (j < width)
		{
			if (d->map[i][j] == ' ' || is_player_pos(d->map, i, j))
			{
				if (d->map[i][j] == ' ')
					wall_flag = 0;
				if (is_player_pos(d->map, i, j))
				{
					if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
						return (0);
				}
				j++;
			}
			else if (d->map[i][j] == '0' && wall_flag == 1)
			{
				zero_flag = 1;
				wall_found_after_tile = 0;
				j++;
			}
			else if (d->map[i][j] == '1')
			{
				if (zero_flag == 1)
					wall_found_after_tile = 1;
				wall_flag = 1;
				j++;
			}
			else
				return (0);
		}
		if (wall_found_after_tile == 0)
			return (0);
		i++;
	}

	return (1);
}

int ft_check_walls(t_data *d, int height, int width)
{
	// printf("FT_CHECK_WALLS\n");
	if (!ft_check_top_to_bottom(d, height, width))
		return (0);
	if (!ft_check_left_to_right(d, height, width))
		return (0);
	return (1);
}
