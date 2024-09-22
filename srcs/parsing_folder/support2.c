/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbest <mbest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:39:39 by mbest             #+#    #+#             */
/*   Updated: 2024/07/04 18:55:11 by mbest            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mat.h"

int ft_tab_len(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		i++;
	}
	return i;
}

int ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int is_blank(const char *str)
{
	while (*str)
	{
		if (!ft_isspace((int)*str))
			return (0);
		str++;
	}
	return (1);
}

int	ft_strlen_nl(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	get_number_lines(char *filename, int *div)
{
	int		fd;
	int		lines;
	char	*line;

    lines = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		exit(EXIT_FAILURE);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		if (!is_start_map(line))
			(*div)++;
		free(line);
		lines++;
	}
	close(fd);
    return(lines);
}
