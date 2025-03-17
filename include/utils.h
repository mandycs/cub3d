/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:15:58 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/03/17 03:52:03 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* @------------------------------------------------------------------------@ */
/* |                            Include Section                             | */
/* @------------------------------------------------------------------------@ */

# include "v2.h"
# include "colors.h"
# include <math.h>
# include "cub3d.h"

typedef struct s_cub	t_cub;
typedef struct s_player	t_player;
typedef struct s_map	t_map;
typedef struct s_ray	t_ray;
typedef struct s_wall	t_wall;
typedef struct s_info	t_info;

/* @------------------------------------------------------------------------@ */
/* |                           Function Section                             | */
/* @------------------------------------------------------------------------@ */

double	deg_to_rads(double angle);
int		calculate_step(double dx, double dy);
double	calculate_distance(t_player *player, t_map *map, double angle);
t_v2	calculate_wall_collision(t_v2 start, double angle, t_map *map);
t_v2	calculate_wall_collision2(t_v2 start, double angle, t_map *map);
bool	is_wall_collision(t_map *map, int x, int y);

bool	create_textures(t_info *info, t_cub *cub);
void	destroy_textures(t_info *info);

void	render(void *param);
void	render_map(t_map *map, t_v2 *position, t_screen *screen);
void	render_player(t_player *player, t_screen *screen);
void	render_fov(t_player *player, t_map *map, t_screen *screen);
void	render_view(t_player *player, t_map *map, t_screen *screen);
void	render_map_element(t_map *map, t_screen *screen, int i, int j);
void	render_ceiling(t_screen *screen, t_color color);
void	render_floor(t_screen *screen, t_color color);
void	render_wall(t_screen *screen, int x, double distance, t_color color);

void	set_color(uint8_t *pixel, t_color color);
void	put_pixel(mlx_image_t *img, int x, int y, t_color color);

void	draw_rectangle(mlx_image_t *img, t_v2 position, t_v2 size,
			t_color color);
void	draw_line(mlx_image_t *img, t_v2 start, t_v2 end, t_color color);

void	clear_background(void *param);
void	swap_buffers(void *param);
void	update(void *param);

void	move_left(t_info *info);
void	move_right(t_info *info);
void	move_backward(t_info *info);
void	move_forward(t_info *info);

void	rotate_left(t_info *info);
void	rotate_right(t_info *info);

void	hook_loader(t_info *info);

bool	cub_create(t_info *info, t_cub *cub);
void	cub_close_window(mlx_t *mlx);
void	cub_destroy(t_info *info, t_cub *cub);

bool	create_player(t_player *player, t_cub *cub);

bool	create_map(t_map *map, t_cub *cub);

void	init_ray(t_ray *ray, t_player *player, const int size, double rangle);
bool	keep_looping(t_ray *ray, t_map *map, t_screen *screen);
void	increase_ray(t_ray *ray);
t_ray	new_cast_ray(t_screen *screen, t_map *map, t_player *player,
			double rangle);

t_color	get_texture_color(mlx_image_t *img, int x, int y);
t_wall	init_wall(t_ray *ray, t_screen *screen, t_player *player,
			double rangle);
void	init_textures(t_wall *wall, t_ray *ray, mlx_image_t *img[4],
			t_screen *screen);
void	paint_wall(t_wall *wall, t_screen *screen, mlx_image_t *img[4], int x);
void	new_render_view(t_info *info, double rangle, int x, t_color *color);

void	new_render_minimap(t_screen *screen, t_map *map, t_player *player);
void	new_render_player(t_screen *screen, t_player *player, t_map *map);

void	collision_forward(t_player *player, t_map *map);
void	collision_right(t_player *player, t_map *map, double angle);
void	collision_left(t_player *player, t_map *map, double angle);
void	collision_backward(t_player *player, t_map *map);

#endif // UTILS_H
