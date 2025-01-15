/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbest <mbest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:03:35 by mbest             #+#    #+#             */
/*   Updated: 2025/01/15 14:53:49 by mbest            ###   ########.fr       */
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

int parse_number(char **ptr)
{
	int num;
	int digit_count;

	num = 0;
	digit_count = 0;
	while(**ptr && ft_isdigit(**ptr))
	{
		num = num * 10 + (**ptr - '0');
		(*ptr)++;
		digit_count++;
		if (digit_count > 3)
			return -1;
	}
	return num;
}

int validate_rgb(char *line)
{
	int r = -1; //! Put in a structure and init them
	int g = -1;
	int b = -1;
	char *ptr;
	
	printf("LINE IN QUESTION: %s\n\n", line);
	ptr = line;
	ptr += 2;
	if (ft_isdigit(*ptr))
		r = parse_number(&ptr);
	if (*ptr == ',')
		ptr++;
	else
		return (-1);
	if (ft_isdigit(*ptr))
		g = parse_number(&ptr);
	if (*ptr == ',')
		ptr++;
	else
		return (-1);
	if (ft_isdigit(*ptr))
		b = parse_number(&ptr);
	//! MAKE SURE IT IS NULL DIRECTLY AFTER no space, no digit, no commas etc NOTHING
	if (*ptr != '\n'){
		printf("There is something after the third digit\n");
		return (0);
	}
	if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255)
		return (1);
	return (0);
}

// void check_identifiers(char **i_map, int num_lines)
void check_identifiers(char **i_map)
{
	int i;
	int found_no = 0; //! Put this shit in a structure and have a function to init them all
	int found_so = 0;
	int found_we = 0;
	int found_ea = 0;
	int found_f = 0;
	int found_c = 0;


    // if (i_map == NULL) {
    //     printf("Error: i_map is NULL\n");
    //     exit(EXIT_FAILURE);
    // }

    // if (num_lines <= 0) {
    //     printf("Error: num_lines is invalid\n");
    //     exit(EXIT_FAILURE);
    // }

    // printf("num_lines: %d\n", num_lines);

    // for (i = 0; i < num_lines; i++) {
    //     if (i_map[i] == NULL) {
    //         printf("Error: i_map[%d] is NULL\n", i);
    //         exit(EXIT_FAILURE);
    //     }
    //     printf("i_map[%d]: %s\n", i, i_map[i]);
    // }

	i = 0;
	while (i_map[i] != NULL)
	{
		// printf("YOOOOOOOOOOOO");
		if (ft_strncmp(i_map[i], "NO ", 3) == 0){
			// printf("Found NO: %s\n", i_map[i]);
			found_no = 1;
		}
		else if (ft_strncmp(i_map[i], "SO ", 3) == 0)
			found_so = 1;
		else if (ft_strncmp(i_map[i], "WE ", 3) == 0)
			found_we = 1;
		else if (ft_strncmp(i_map[i], "EA ", 3) == 0)
			found_ea = 1;
		else if (ft_strncmp(i_map[i], "F ", 2) == 0)
			found_f = validate_rgb(i_map[i]);
		else if (ft_strncmp(i_map[i], "C ", 2) == 0)
			found_c = validate_rgb(i_map[i]);
		i++;
	}
	printf("no: %d\nso: %d\nwe: %d\nea: %d\nf: %d\nc: %d\n", found_no, found_so, found_we, found_ea, found_f, found_c);
	if (!found_no || !found_so || !found_we || !found_ea || !found_f || !found_c)
	{
		printf("Error: Missing or invalid identifier in the map info\n");
		exit(EXIT_FAILURE);
	}
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
	printing_map(d->i_map);
	// check_identifiers(d->i_map, div);
	check_identifiers(d->i_map);
	printf("-------------------------------------------------\n");
	ft_copy_map(num_lines, &div, filename, d);
	// printing_map(d->map);
	// exit(0);
	// close(fd);
}
