/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbest <mbest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:23:23 by mbest             #+#    #+#             */
/*   Updated: 2024/09/23 14:39:16 by mbest            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mat.h"

int is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int map_character(char c)
{
	if (c == '1' || c == '0')
		return (1);
	else if (is_space(c))
		return (1);
	else if (c == 'N' || c == 'S')
		return (1);
	else if (c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

int is_start_map(char *line)
{
	int i;

	i = 0;
	while(line[i] != '\0')
	{
		if (line[0] == '\n')
			return (0);
		else if (map_character(line[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
