/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:49:42 by mbest             #+#    #+#             */
/*   Updated: 2024/09/22 18:53:30 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mat.h"

void get_height_and_width(int *height, int *width, char **map)
{
	int max_length;
	
	while (map[*height] != NULL)
	{
		max_length = ft_strlen_nl(map[*height]);
		if (max_length > *width)
		{
			*width = max_length;
		}
		(*height)++;
	}
	// printf("\nMap height: %d\nMap width: %d\n", *height, *width);
	add_padding(*width, *height, map); //! Do this it the end end just before returning the map for playing
	// printing_map(map);
}

int invalid_character(char c, char *str, int num)
{
	int i;

	i = 0;
	while(i < num)
	{
		if (c != str[i])
			i++;
		else
			return (0);	
	}
	return (1);
}

int ft_check_characters(char **map, int height, int width)
{
	int i;
	int j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (invalid_character(map[i][j], "01NSEW ", 7))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void ft_check_valid_map(t_data *d)
{
	int height;
	int width;
	
	height = 0;
	width = 0;
	get_height_and_width(&height, &width, d->map);
	if (!ft_check_characters(d->map, height, width))
	{
		printf("The map must be composed of only 6 possible characters:\n \
		0 for an empty space\n \
		1 for a wall\n \
		N,S,E or W for the player's start position and spawning orientation.\n");
	}
	if (!ft_check_walls(d, height, width))
	{
		printf("Error: Maps should be surrounded by walls\n");
		exit(EXIT_FAILURE); 
	}
}
