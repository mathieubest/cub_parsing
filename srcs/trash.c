/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:41:39 by mbest             #+#    #+#             */
/*   Updated: 2024/09/22 18:38:09 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! DELETE THIS FILE


#include "cub3d_mat.h"

void printing_map(char **map)
{
    while(*map != NULL)
    {
        printf("%s", *map);
        map++;
    }
    // printf("Printing map ok\n");
}
