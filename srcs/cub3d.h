/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbest <mbest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:20:13 by cumoncoq          #+#    #+#             */
/*   Updated: 2024/07/04 15:42:28 by mbest            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define _RED "\033[1;31m"
# define _GREEN "\033[1;32m"
# define _YELLOW "\033[1;33m"
# define _BLUE "\033[1;34m"
# define _RESET "\033[0m"

# define XPMLOAD mlx_xpm_file_to_image

# define EPSILON 0.000001
# define WINY 540
// # define WINY 820
// # define WINY 1080
# define WINX (WINY + (WINY / 2))
# define MSCALE 10	// scale of each tile in minimap
# define MSIZE 7	// number of tiles we see
# define FOV 65		// fov in degrees°
# define FPS 15
// # define SHADOW 20

# define HEALTH 100
# define DAMAGE 1
# define MONSTER_SPEED 1

# define SHADOW 1
# define BLUR 5

# define W_KEY 0x77
# define Z_KEY 0x7a
# define A_KEY 0x61
# define Q_KEY 0x71
# define S_KEY 0x73
# define D_KEY 0x64
# define P_KEY 0x70
# define LEFT_KEY 0xff51
# define RIGHT_KEY 0xff53
# define ESC_KEY 0xff1b
# define SPACE_KEY 0x20

# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"
# include <string.h>
# include <errno.h>
# include <fcntl.h>
// # include <X11/X.h>
// # include <X11/keysym.h>

enum e_dir_wall
{
	north,
	south,
	east,
	west
};

enum e_action_move_fb
{
	no_move_fb,
	forward,
	backward,
};

enum e_action_move_lr
{
	no_move_lr,
	leftward,
	rightward,
};

enum e_action_turn
{
	no_turn,
	left,
	right,
};

enum e_wall_type
{
	is_wall,
	is_door,
	is_switch_off,
	is_switch_mid,
	is_switch_on,
};

typedef struct s_vec
{
	double	x;
	double	y;
}				t_vec;

typedef struct s_tuple
{
	size_t	x;
	size_t	y;
}			t_tuple;

typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
}			t_color;

typedef struct s_wall
{
	double	dist;	// distance from player
	double	column;	// value between 0 and 1
	int		dir;	// north, south, east, west
	int 	type;
}			t_wall;

typedef struct s_buff
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l;
	int		e;
	int 	w;
	int 	h;
}				t_buff;

typedef struct s_texture
{
	t_buff n;
	t_buff s;
	t_buff e;
	t_buff w;
	t_buff door_ns;
	t_buff door_ew;
	t_buff action;
	t_buff monster[3];
	t_buff swi[2][3];
}			t_texture;

typedef struct s_game
{
	size_t	mapx;
	size_t	mapy;
	int	exit;
	int	left;
	int	finished;
}	t_game;

typedef struct s_player
{
	double	x;
	double	y;
	double	fov;
	double	body_angle;
	double	angle;
	double 	dmg_intensity;
	// t_vec	vec;
	double	rays[WINX];
	double	health;
	int		see_monster;
}	t_player;

typedef struct s_keys
{
	int	move_fb;
	int	move_lr;
	int	turn;
	int action;
	int pause;
}	t_keys;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map;
	char		**i_map;
	// int 		num_lines; //# MAYBE REMOVE
	t_game		g;
	t_player	p;
	t_keys 		k;
	t_texture	t;
	t_buff		minimap[2];
	t_buff		buff[2];
	t_vec		monster_pos;
	int			frame;
}	t_data;

// clean.c
int	ft_mlx_destroy(t_data *);
int ft_clean_exit(t_data *);
void ft_error_exit(t_data *);
void free_map(char **);

// color.c
int	ft_add_shade(int, int);
int	ft_add_shade2(int, int);
int	ft_div_shade(int, double);
int	ft_add_light(int, int);

//colors2.c
double lcg_rand(size_t);
void make_pixel_more_red(t_data *, int, int, double);
void add_overlay(t_data *, int, int);
void light_pixel(t_data *, int, int, int);
void shade_pixel(t_data *, int, int, double);

// display.c
int get_wall_color(t_wall, t_data *, double);
void update_column(int, double, t_data *);
void update_view(t_data *);

// gameplay.c
void switch_press(t_data *);
void switch_release(t_data *);
void check_health(t_data *, double);
void open_door(t_data *d);

// init.c
void ft_init_game_data(t_data *);
int is_player(char);
double get_angle(char);
void ft_init_player_data(t_data *);
void init_imgs(t_data *);
void init_buff(t_data *);

// mafs.c
double to_deg(double);
double to_rad(double);
int	upper_int(double);
int lower_int(double);
t_vec get_vec(double);
int ztoo(double x);
double x_from_y(double, t_vec);
double y_from_x(double, t_vec);
t_vec fill_t_vec(double, double);
t_tuple fill_t_tuple(int, int);

//! tmp.c
char **create_map(void);
char **create_map2(void);
void print_map(char **, t_data *);
void init_images_tmp( t_data * );

// support.c
int char_is_wall(char);
t_vec fill_t_vec(double, double);
t_tuple fill_t_tuple(int, int);

// minimap.c
int is_empty(char);
void light_pixel(t_data *, int, int, int);
void shade_pixel(t_data *, int, int, double);
void shade_minimap(t_data *);
void put_sprite(t_data *, double, double);
void update_minimap(t_data *, int, int);

//moves.c
void ft_turn(t_data *);
void calculate_move(t_data *, double *, double *);
int is_walkable(char);
void ft_move(t_data *);
void move_monster(t_data *);

// mlx.c
int	ft_mlx_init(t_data *);
void	my_pixel_put(t_buff *, int, int, int);
int	ft_pixel_get(t_buff *, int, int);
double	ft_shade_get(t_buff *img, int x, int y);

// keys_press.c
void press_move(int, t_data *);
void press_turn(int, t_data *);
int	ft_keypress(int, t_data *);
int ft_mouse_press(int, int, int, t_data *);
void handle_mouse(t_data *);

// keys_release.c
void release_move(int, t_data *);
void release_turn(int, t_data *);
int	ft_keyrelease(int, t_data *);
int ft_mouse_release(int, int, int, t_data *);

//ray.c
double vertical_wall_distance(t_data *, t_vec);
double horizontal_wall_distance(t_data *, t_vec);
double get_y_coord(t_data *, int, t_vec);
int is_wall_vertical(t_data *, int, t_wall *, t_vec);
double get_x_coord(t_data *, int, t_vec);
int is_wall_horizontal(t_data *, int, t_wall *, t_vec);
t_wall throw_ray(t_data *, double);
void set_wall_type( t_wall *wall, char c );









// map_checking.c
void get_height_and_width(int *height, int *width, char **map);
int invalid_character(char c, char *str, int num);
int ft_check_charactets(char **map, int height, int width);
void ft_check_valid_map(t_data *d);

// map_checking2.c
void ft_check_permission(char *filename);
void ft_check_extension(char *filename);
ft_copy_map(char *filename, t_data *d);

// parsing.c
void add_padding(int max_width, int height, char **map);
int ft_parsing(int ac, char *filename, t_data *d);

// support2.c
int ft_tab_len(char **tab);
int ft_isspace(int c);
int is_blank(const char *str);
size_t ft_Strlen_nl(const char *str);
int get_number_lines(char *filename, int *div);

// support3.c
int is_Start_map(char *line);

// textures_check.c
int ft_check_north(t_data *d, int i);
int ft_check_south(t_data *d, int i);
int ft_check_west(t_data *d, int i);
int ft_check_east(t_data *d, int i);
int ft_valid_textures(t_data *d, int i, int *flag);

// textures_check2.c
int ft_check_ceiling(t_data *d, int i);
int ft_check_floor(t_data *d, int i);
void ft_check_valid_info(t_data *d);

//! Delete this
// trash.c
void printing_map(char **map);

// wall_checker.c
int is_player_pos(char **map, int i, int j)
int ft_check_top_to_bottom(t_data *d, int height, int width);
int ft_check_left_to_right(t_data *d, int height, int width);
int ft_check_walls(t_data *d, int height, int width);

#endif
