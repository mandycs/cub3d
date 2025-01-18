#ifndef CUB3D_H
# define CUB3D_H

/* @------------------------------------------------------------------------@ */
/* |                            Define Section                              | */
/* @------------------------------------------------------------------------@ */

# define INITIAL_CAPACITY 16
# define WALL = '1'
# define FILL = '.'
# define PIXEL_SIZE 32
# define RESIZE 4

/* @------------------------------------------------------------------------@ */
/* |                            Include Section                             | */
/* @------------------------------------------------------------------------@ */

# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include "BFL.h"
# include "MLX42.h"
# include "screen.h"
# include "weapon.h"
# include "utils.h"

/* @------------------------------------------------------------------------@ */
/* |                            Typedef Section                             | */
/* @------------------------------------------------------------------------@ */

typedef struct s_cub	t_cub;
typedef struct s_player	t_player;
typedef struct s_map	t_map;
typedef struct s_info	t_info;

/* @------------------------------------------------------------------------@ */
/* |                             Enum Section                               | */
/* @------------------------------------------------------------------------@ */

enum					e_exit_status_cub
{
	CUB_OK = 0,     /**< 0 */
	CUB_LKO,        /**< 1 */
	CUB_RIP_MALLOC, /**< Amount of enums */
	CUB_RIP_READ,
	CUB_NO_TEXT,
	CUB_NO_PATH,
	CUB_ERROR_NO_PATH,
	CUB_ERROR_SO_PATH,
	CUB_ERROR_WE_PATH,
	CUB_ERROR_EA_PATH,
	CUB_ERROR_COLOR,
	CUB_ERROR_MAP,
	CUB_ERROR_NO_MAP
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
	int					len;
	char				*line;
	char				**new_lines;
	int					pos_x;
	int					pos_y;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				*f;
	char				*f_aux;
	char				*c;
	int					fd_no;
	int					fd_so;
	int					fd_we;
	int					fd_ea;
	t_color				floor_c;
	t_color				ceiling_c;
	int					error;
};

struct s_player
{
	t_v2		position;
	t_toolbar	toolbar;
	double		speed;
	int			fov;
	double		angle;
};

struct s_map
{
	char		**data;
	int			rows;
	int			cols;
};

struct s_info
{
	mlx_t			*mlx;
	mlx_image_t		*img[4];
	mlx_texture_t	*tex[4];
	t_player		player;
	t_map			map;
	t_screen		screen;
};

/* @------------------------------------------------------------------------@ */
/* |                           Function Section                             | */
/* @------------------------------------------------------------------------@ */

void					ribanab(void);
int						ft_check_arg(int argc, char **argv, t_cub *cub);
int						ft_check_extension(char *str);
int						ft_extract_path(char *filename);
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
void					ft_process_texture(t_cub *cub);
int						ft_check_paths(t_cub *cub);
int						ft_open_file(char *filename, int *fd, int flag,
							t_cub *cub);
int						ft_check_map(t_cub *cub);
void					ft_check_error(t_cub *cub);
void					ft_paths_close(t_cub *cub);
void					ft_close_fd(t_cub *cub);
void					ft_check_error(t_cub *cub);
void					ft_check_error_2(t_cub *cub);
void					ft_map_len(t_cub *cub);
int						ft_check_extension_texture(char *str);
// static void				flood_fill(t_info *info, char ***map, int x, int y);
void					ft_init_pos(t_cub *cub);
int						ft_map_functions(t_cub *cub);
void					ft_clean_paths(t_cub *cub);
#endif
