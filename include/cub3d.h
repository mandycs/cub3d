/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:54:19 by ribana-b          #+#    #+#             */
/*   Updated: 2025/05/18 17:06:51 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* @------------------------------------------------------------------------@ */
/* |                            Define Section                              | */
/* @------------------------------------------------------------------------@ */

# define INITIAL_CAPACITY 16
# define WALL '1'
# define FILL '.'
# define PIXEL_SIZE 160
// PI / 180, but norminette doesn't allow to do M_PI / 180
# define DEG2RAD 0.017453292519943295

/* @------------------------------------------------------------------------@ */
/* |                            Include Section                             | */
/* @------------------------------------------------------------------------@ */

# include "BFL.h"
# include "MLX42.h"
# include "screen.h"
# include "utils.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>

/* @------------------------------------------------------------------------@ */
/* |                            Typedef Section                             | */
/* @------------------------------------------------------------------------@ */

typedef struct s_cub	t_cub;
typedef struct s_player	t_player;
typedef struct s_ray	t_ray;
typedef struct s_wall	t_wall;
typedef struct s_map	t_map;
typedef struct s_info	t_info;

/* @------------------------------------------------------------------------@ */
/* |                             Enum Section                               | */
/* @------------------------------------------------------------------------@ */

enum					e_exit_status_cub
{
	CUB_OK = 0,
	CUB_LKO,
	CUB_RIP_MALLOC,
	CUB_RIP_READ,
	CUB_NO_TEXT,
	CUB_NO_PATH,
	CUB_ERROR_PERMISSION_A,
	CUB_ERROR_PERMISSION_B,
	CUB_ERROR_PERMISSION_C,
	CUB_ERROR_PERMISSION_D,
	CUB_ERROR_PATH,
	CUB_ERROR_COLOR,
	CUB_ERROR_MAP,
	CUB_ERROR_MAP_NOT_CLOSED,
	END_GAME
};

/* @------------------------------------------------------------------------@ */
/* |                            Struct Section                              | */
/* @------------------------------------------------------------------------@ */

struct					s_cub
{
	int					fd;
	int					capacity;
	int					count;
	int					i;
	int					j;
	char				**text;
	char				**map;
	int					tmp;
	int					width;
	int					height;
	char				*line;
	char				**new_lines;
	char				**map_dup;
	int					pos_x;
	int					pos_y;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				*f;
	char				*f_aux;
	char				*c_aux;
	char				*c;
	int					fd_no;
	int					fd_so;
	int					fd_we;
	int					fd_ea;
	t_color				floor_c;
	t_color				ceiling_c;
	int					error;
	int					flag;
};

struct					s_player
{
	t_v2				position;
	double				speed;
	int					fov;
	double				angle;
};

struct					s_map
{
	char				**data;
	int					rows;
	int					cols;
};

struct					s_info
{
	mlx_t				*mlx;
	mlx_image_t			*img[4];
	mlx_texture_t		*tex[4];
	t_player			player;
	t_map				map;
	t_screen			screen;
	t_color				ceiling_color;
	t_color				floor_color;
	bool				is_cursor_free;
};

struct					s_ray
{
	t_v2				start;
	t_v2				dir;
	t_v2				step;
	t_v2				length;
	t_v2				map_check;
	t_v2				map_step;
	bool				hit;
	double				distance;
	int					side;
};

struct					s_wall
{
	int					height;
	int					draw_start;
	int					draw_end;
	int					tex_num;
	double				x;
	int					tex_x;
	int					tex_y;
	double				tex_step;
	double				tex_pos;
};

/* @------------------------------------------------------------------------@ */
/* |                           Function Section                             | */
/* @------------------------------------------------------------------------@ */

int						ft_check_arg(int argc, char **argv, t_cub *cub);
int						ft_check_extension(char *str, t_cub *cub);
int						ft_extract_path(char *filename, t_cub *cub);
int						ft_read_file(t_cub *cub);
void					ft_print_map(t_cub *cub);
int						ft_extract_text(t_cub *cub);
void					ft_extract_path_texture(t_cub *cub, int flag);
int						ft_extract_color(t_cub *cub, int flag);
int						ft_extract_color_aux_f(t_cub *cub);
int						ft_extract_color_aux_c(t_cub *cub);
int						ft_extract_map(t_cub *cub);
void					ft_print_paths(t_cub *cub);
void					ft_free_cub(t_cub *cub);
void					initialize_cub(t_cub *cub);
int						ft_process_texture(t_cub *cub);
int						ft_check_paths(t_cub *cub);
int						ft_open_file(char *filename, int *fd, int flag,
							t_cub *cub);
int						ft_check_map(t_cub *cub);
void					ft_check_error(t_cub *cub);
void					ft_paths_close(t_cub *cub);
void					ft_close_fd(t_cub *cub);
void					ft_check_error(t_cub *cub);
void					ft_check_error_2(t_cub *cub);
int						ft_check_extension_texture(char *str);
int						ft_init_pos(t_cub *cub);
int						ft_map_functions(t_cub *cub);
void					ft_clean_paths(t_cub *cub);
void					ft_duplicate_map(t_cub *cub);
int						ft_mapextract(t_cub *cub);
int						ft_is_valid_map_char(char c);
int						ft_remove_path_spaces(t_cub *cub);
int						ft_remove_path_spaces_second(t_cub *cub);
int						set_cub_error(t_cub *cub, int error);

#endif
