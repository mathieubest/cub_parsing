/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbest <mbest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:33:52 by mbest             #+#    #+#             */
/*   Updated: 2024/09/23 19:46:19 by mbest            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mat.h"

void add_padding(int max_width, int height, char **map)
{
	int i;
	int j;
	char *new_line;

	i = 0;
	while (i < height)
	{
		if (ft_strlen_nl(map[i]) < max_width)
		{
			new_line = (char *)malloc(sizeof(char) * (max_width + 1));
			if (new_line == NULL)
			{
				printf("Malloc Error\n");
				exit(EXIT_FAILURE); //? CLEAN EXIT
			}
			ft_strlcpy(new_line, map[i], ft_strlen_nl(map[i]) + 2);
			j = ft_strlen_nl(map[i]);
			while (j < max_width)
			{
				new_line[j] = ' ';
				j++;
			}
			new_line[max_width] = '\n';
			new_line[max_width + 1] = '\0';
			free(map[i]);
			map[i] = new_line;
		}
		i++;
	}
}

int	ft_parsing(int ac, char *filename, t_data *d)
{
	if (ac != 2)
	{
		err_num_args();
	}
	ft_check_permission(filename);
	ft_check_extension(filename);
	ft_copy_file(filename, d); //! EXIT CLEANLY STARTING HERE + FREEING AT THE END OF PARSING
	// ft_check_valid_info(d);
	ft_check_valid_map(d);
	return (1);
}

int	main(int ac, char **av)
{
	t_data d;

	if (!ft_parsing(ac, av[1], &d))
		exit(EXIT_FAILURE);
	printf("Good Map Ser\n");
	exit(EXIT_SUCCESS);
}

/* Errors with explicit error msg */