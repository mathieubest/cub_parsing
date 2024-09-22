/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:28:04 by cumoncoq          #+#    #+#             */
/*   Updated: 2024/06/25 01:42:00 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char **create_map( void ) {
	char **map;
	map = malloc(sizeof(char *) * 15);
	map[0] =  ft_strdup("        1111111111111111111111111");
	map[1] =  ft_strdup("        1000000000110000000000001");
	map[2] =  ft_strdup("        1011000001110000000000001");
	map[3] =  ft_strdup("        1001000000D00000000000001");
	map[4] =  ft_strdup("111111111011000001110000000000001");
	map[5] =  ft_strdup("10000000001100000111011111D111111");
	map[6] =  ft_strdup("11110111111111011100000010001    ");
	map[7] =  ft_strdup("11110111111111011101010010001    ");
	map[8] =  ft_strdup("11000000110101011100000010001    ");
	map[9] =  ft_strdup("10000000000000001100N000D0001    ");
	map[10] = ft_strdup("10000000000000000D01010010001    ");
	map[11] = ft_strdup("1100000111010101111101111000111  ");
	map[12] = ft_strdup("11110111 1110101 1000110D0001    ");
	map[13] = ft_strdup("11111111 1111111 111111111111    ");
	map[14] = NULL;
	return (map);
}

char **create_map2( void ) {
	char **map;
	map = malloc(sizeof(char *) * 6);
	map[0] =  ft_strdup("1111111");
	map[1] =  ft_strdup("1000001");
	map[2] =  ft_strdup("10N0001");
	map[3] =  ft_strdup("1000001");
	map[4] =  ft_strdup("1111111");
	map[5] = NULL;
	return (map);
}

void init_images_tmp( t_data *d )
{
	d->t.n.img = XPMLOAD(d->mlx, "textures/backroom.xpm", &d->t.n.w, &d->t.n.h);
	d->t.s.img = XPMLOAD(d->mlx, "textures/backroom.xpm", &d->t.s.w, &d->t.s.h);
	d->t.w.img = XPMLOAD(d->mlx, "textures/backroom2.xpm", &d->t.w.w, &d->t.w.h);
	d->t.e.img = XPMLOAD(d->mlx, "textures/backroom2.xpm", &d->t.e.w, &d->t.e.h);
	d->t.action.img = XPMLOAD(d->mlx, "textures/hand.xpm", &d->t.action.w, &d->t.action.h);
	d->t.door_ns.img = XPMLOAD(d->mlx, "textures/door_ns.xpm", &d->t.door_ns.w, &d->t.door_ns.h);
	d->t.door_ew.img = XPMLOAD(d->mlx, "textures/door_ew.xpm", &d->t.door_ew.w, &d->t.door_ew.h);
	d->t.monster[0].img = XPMLOAD(d->mlx, "textures/monster_0.xpm", &d->t.monster[0].w, &d->t.monster[0].h);
	d->t.monster[1].img = XPMLOAD(d->mlx, "textures/monster_1.xpm", &d->t.monster[1].w, &d->t.monster[1].h);
	d->t.monster[2].img = XPMLOAD(d->mlx, "textures/monster_2.xpm", &d->t.monster[2].w, &d->t.monster[2].h);
	d->t.swi[0][0].img = XPMLOAD(d->mlx, "textures/switch_0_light.xpm", &d->t.swi[0][0].w, &d->t.swi[0][0].h);
	d->t.swi[0][1].img = XPMLOAD(d->mlx, "textures/switch_1_light.xpm", &d->t.swi[0][1].w, &d->t.swi[0][1].h);
	d->t.swi[0][2].img = XPMLOAD(d->mlx, "textures/switch_2_light.xpm", &d->t.swi[0][2].w, &d->t.swi[0][2].h);
	d->t.swi[1][0].img = XPMLOAD(d->mlx, "textures/switch_0_dark.xpm", &d->t.swi[1][0].w, &d->t.swi[1][0].h);
	d->t.swi[1][1].img = XPMLOAD(d->mlx, "textures/switch_1_dark.xpm", &d->t.swi[1][1].w, &d->t.swi[1][1].h);
	d->t.swi[1][2].img = XPMLOAD(d->mlx, "textures/switch_2_dark.xpm", &d->t.swi[1][2].w, &d->t.swi[1][2].h);
}

int dec_eq_int( double d, int i )
{
	if (d >= i && d < i + 1)
		return (1);
	return (0);
}


void	print_map( char **map, t_data *d ) {
	for (int i = 0; map[i] != NULL; i++) {
		for (int j = 0; map[i][j]; j++) {
			if (dec_eq_int(d->p.y, i) && dec_eq_int(d->p.x, j)) {
				printf(_RED "+"_RESET);
			} else if (map[i][j] == '1') {
				printf(_YELLOW"1"_RESET);
			} else if (map[i][j] == 'X') {
				printf(_BLUE"X"_RESET);
			} else if (map[i][j] == 'D') {
				printf(_RED"D"_RESET);
			} else {
				printf("%c", map[i][j]);
			}
		}
		printf("\n");
	}
}
