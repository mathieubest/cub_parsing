/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbest <mbest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:51:13 by mbest             #+#    #+#             */
/*   Updated: 2024/07/04 18:49:43 by mbest            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mat.h"

void	err_num_args(void)
{
    ft_putstr_fd("\n", 2);
	ft_putstr_fd(" ------------------------------------- \n", 2);
	ft_putstr_fd("| Error: Invalid number of arguments. |\n", 2);
	ft_putstr_fd(" ------------------------------------- \n", 2);
	ft_putstr_fd("|     Expected: ./cub3d  file.cub     |\n", 2);
	ft_putstr_fd(" ------------------------------------- \n", 2);
    ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void err_permission(void)
{

    ft_putstr_fd("\n", 2);
    ft_putstr_fd(" -------------------------------- \n", 2);
    ft_putstr_fd("| Error: Could not open the file |\n", 2);
    ft_putstr_fd(" -------------------------------- \n", 2);
    ft_putstr_fd("\n", 2);
    exit(EXIT_FAILURE);
}

void err_extension(void)
{
    ft_putstr_fd("\n", 2);
    ft_putstr_fd(" ----------------------------- \n", 2);
    ft_putstr_fd("| Error: Invalid file format. |\n", 2);
    ft_putstr_fd(" ----------------------------- \n", 2);
    ft_putstr_fd("|     Expected:  file.cub     |\n", 2);
    ft_putstr_fd(" ----------------------------- \n", 2);
    ft_putstr_fd("\n", 2);
    exit(EXIT_FAILURE);
}

void err_blank_line(void)
{
	printf("There should be no blank lines in the map.\n");
}
