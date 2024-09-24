/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbest <mbest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:03:35 by mbest             #+#    #+#             */
/*   Updated: 2024/09/24 22:45:00 by mbest            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mat.h"

void ft_malloc_maps(int *div, int *num_lines, char *filename, t_data *d)
{
	*num_lines = get_number_lines(filename, div);
	printf("Number of lines in the file: %d\n", *num_lines);
	printf("Div = %d\n", *div);
	d->i_map = (char **)malloc(sizeof(char *) * (*div + 1)); //? Add to free list
	if (d->i_map == NULL)
	{
		exit(EXIT_FAILURE);
	}
    d->map = (char **)malloc(sizeof(char *) * (*num_lines  - *div + 1)); //? Add to free list
    if (d->map == NULL)
	{
        exit(EXIT_FAILURE); //! Clean Exit
	}

}

void ft_copy_map_info(int *div, char *filename, t_data *d)
{
	int i;
	int fd;
	char *line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		exit(EXIT_FAILURE); //! Clean Exit
	}
	while (i < *div && (line = get_next_line(fd)) != NULL)
	{
		d->i_map[i] = ft_strdup(line); //? Add to free list
		if (d->i_map[i] == NULL)
		{
			exit(EXIT_FAILURE); //! Clean Exit
		}
		i++;
	}
	*div = i + 1;
	d->i_map[i] = NULL;
}

void ft_copy_map(int num_lines, int *div, char *filename, t_data *d)
{
	int i;
	int j;
	int fd;
	char *line;

	i = 0;
	j = 0;
	// i = *div;
	// printf("i = %d\n", i);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		exit(EXIT_FAILURE); //! Clean Exit
	}
	while (i < num_lines && (line = get_next_line(fd)) != NULL)
	{
		if (i < *div - 1)
			i++;
		else
		{
			d->map[j] = ft_strdup(line); //? Add to free list
			if (d->map[j] == NULL)
			{
				err_blank_line();
				exit(EXIT_FAILURE); //! Clean Exit
			}
			// if (is_blank(d->map[j]))
			// if (d->map[j] == NULL)
			// {
			// 	exit(EXIT_FAILURE); //! Clean Exit
			// }
			i++;
			j++;
		}
	}
	d->map[j] = NULL;
	close(fd);
}

void	ft_copy_file(char *filename, t_data *d)
{
	// int fd;
	int div; //! End of map info
	int		num_lines;

	div = 0;
	num_lines = 0;
	ft_malloc_maps(&div, &num_lines, filename, d);
    // fd = open(filename, O_RDONLY);
    // if (fd == -1)
	// {
    //     exit(EXIT_FAILURE);
	// }
	
	ft_copy_map_info(&div, filename, d);
	// printing_map(d->i_map);
	printf("-------------------------------------------------\n");
	ft_copy_map(num_lines, &div, filename, d);
	// printing_map(d->map);
	// exit(0);
	// close(fd);
}
