/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:58:48 by mbest             #+#    #+#             */
/*   Updated: 2024/09/22 19:17:58 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mat.h"

void	ft_check_permission(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
        err_permission();
	}
	close(fd);
}

void	ft_check_extension(char *filename)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension)
    {
        err_extension();
    }
	if (ft_strncmp(extension, ".cub", 5) != 0)
	{
        err_extension();
	}
}
