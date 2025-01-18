#ifndef UTILS_H
# define UTILS_H

/* @------------------------------------------------------------------------@ */
/* |                            Include Section                             | */
/* @------------------------------------------------------------------------@ */

# include "v2.h"
# include "colors.h"
# include <math.h>
# include "cub3d.h"

typedef struct s_player	t_player;
typedef struct s_map	t_map;
typedef struct s_info	t_info;

/* @------------------------------------------------------------------------@ */
/* |                           Function Section                             | */
/* @------------------------------------------------------------------------@ */

float	deg_to_rads(float angle);
int		calculate_step(float dx, float dy);
float	calculate_distance(t_player *player, t_map *map, float angle);
t_v2	calculate_wall_collision(t_v2 start, float angle, int fov, t_map *map);
bool	is_wall_collision(t_map *map, int x, int y);

bool	create_textures(t_info *info);
void	destroy_textures(t_info *info);

void	render(void *param);
void	render_map(t_map *map, t_screen *screen);
void	render_player(t_player *player, t_screen *screen);
void	render_fov(t_player *player, t_map *map, t_screen *screen);
void	render_view(t_player *player, t_map *map, t_screen *screen);
void	render_map_element(t_map *map, t_screen *screen, int i, int j);
void	render_ceiling(t_screen *screen, t_color color);
void	render_floor(t_screen *screen, t_color color);
void	render_wall(t_screen *screen, int x, float distance, t_color color);

void	set_color(uint8_t *pixel, t_color color);
void	put_pixel(mlx_image_t *img, int x, int y, t_color color);

void	draw_rectangle(mlx_image_t *img, t_v2 position, t_v2 size,
		t_color color);
void	draw_line(mlx_image_t *img, t_v2 start, t_v2 end, t_color color);

#endif // UTILS_H
