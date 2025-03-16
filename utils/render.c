/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:43 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/03/16 19:15:50 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/* ========================================================================== */

// NOTE: The player position will be taked into account to render the minimap,
// so I can have a fixed size instead of drawing the whole map, useful for
// big maps.
void	new_render_minimap(t_screen *screen, t_map *map, t_player *player)
{
	const double	size = screen->scale;
	int				x;
	int				y;

	(void)player;
	x = -1;
	while (++x < map->rows)
	{
		y = -1;
		while (++y < map->cols)
		{
			if (map->data[x][y] == '1')
			{
				draw_rectangle(screen->buffer, v2_create(y * size, x * size),
					v2_create(size, size), gray());
			}
			else if (map->data[x][y] != '1' && map->data[x][y] != '\0'
						&& map->data[x][y] != '\n' && map->data[x][y] != ' ')
			{
				draw_rectangle(screen->buffer, v2_create(y * size, x * size),
					v2_create(size, size), black());
			}
		}
	}
}

/* ========================================================================== */

void	new_render_player(t_screen *screen, t_player *player)
{
	const double	size = screen->scale;
	const int		resized_x = player->position.x * size - size * 0.5;
	const int		resized_y = player->position.y * size - size * 0.5;

	draw_rectangle(screen->buffer,
		v2_create(resized_y, resized_x),
		v2_create(size, size),
		lightred());
}

/* ========================================================================== */

void	init_ray(t_ray *ray,
						t_player *player,
						const int size,
						double rangle)
{
	ray->distance = 0;
	ray->hit = false;
	ray->map_check = v2_create(floor(player->position.x * size),
			floor(player->position.y * size));
	ray->start = v2_create(player->position.x * size,
			player->position.y * size);
	ray->dir = v2_create(sin(rangle), cos(rangle));
	ray->step = v2_create(fabs(1 / ray->dir.x), fabs(1 / ray->dir.y));
	ray->length = v2_create((ray->map_check.x + 1 - ray->start.x) * ray->step.x,
			(ray->map_check.y + 1 - ray->start.y) * ray->step.y);
	ray->map_step = v2_create(1, 1);
	if (ray->dir.x < 0)
	{
		ray->map_step.x = -1;
		ray->length.x = (ray->start.x - ray->map_check.x) * ray->step.x;
	}
	if (ray->dir.y < 0)
	{
		ray->map_step.y = -1;
		ray->length.y = (ray->start.y - ray->map_check.y) * ray->step.y;
	}
}

bool	keep_looping(t_ray *ray,
						t_map *map,
						t_screen *screen)
{
	t_v2			check;
	const double	size = screen->scale;

	check = v2_create(ray->map_check.x / size, ray->map_check.y / size);
	if (check.x < 0 || check.x >= map->rows
		|| check.y < 0 || check.y >= map->cols)
		return (false);
	if (map->data[(int)check.x][(int)check.y] == '1')
	{
		ray->hit = true;
		draw_line(screen->buffer, v2_create(ray->start.y, ray->start.x),
			v2_create(ray->map_check.y, ray->map_check.x), lightgreen());
	}
	return (true);
}

void	increase_ray(t_ray *ray)
{
	if (ray->length.x < ray->length.y)
	{
		ray->side = 0;
		ray->distance = ray->length.x;
		ray->map_check.x += ray->map_step.x;
		ray->length.x += ray->step.x;
	}
	else
	{
		ray->side = 1;
		ray->distance = ray->length.y;
		ray->map_check.y += ray->map_step.y;
		ray->length.y += ray->step.y;
	}
}

t_ray	new_cast_ray(t_screen *screen,
						t_map *map,
						t_player *player,
						double rangle)
{
	const double	size = screen->scale;
	t_ray			ray;

	init_ray(&ray, player, size, rangle);
	while (!ray.hit)
	{
		increase_ray(&ray);
		if (!keep_looping(&ray, map, screen))
			break ;
	}
	return (ray);
}

/* ========================================================================== */

t_color	get_texture_color(mlx_image_t *img, int x, int y)
{
	t_color			color;
	const uint32_t	pos = ((uint32_t)y * img->width + x) * 4;

	if (x < 0 || y < 0 || x >= (int)img->width || y >= (int)img->height)
		return (black());
	color.r = img->pixels[pos + 0];
	color.g = img->pixels[pos + 1];
	color.b = img->pixels[pos + 2];
	color.a = img->pixels[pos + 3];
	return (color);
}

t_wall	init_wall(t_ray *ray, t_screen *screen, t_player *player, double rangle)
{
	const double	size = screen->scale;
	t_wall			wall;

	wall.height = (int)(screen->height * size
			/ (ray->distance * cos(rangle - (player->angle * DEG2RAD))));
	wall.draw_start = screen->height / 2 - wall.height / 2;
	if (wall.draw_start < 0)
		wall.draw_start = 0;
	wall.draw_end = wall.draw_start + wall.height;
	if (wall.draw_end >= screen->height)
		wall.draw_end = screen->height - 1;
	wall.tex_num = 0;
	if (ray->side == 0)
		wall.x = (ray->start.y + ray->distance * ray->dir.y) / size;
	else
		wall.x = (ray->start.x + ray->distance * ray->dir.x) / size;
	wall.x -= (int)wall.x;
	return (wall);
}

void	init_textures(t_wall *wall,
						t_ray *ray,
						mlx_image_t *img[4],
						t_screen *screen)
{
	if (ray->side == 0 && ray->dir.x > 0)
		wall->tex_num = 1;
	else if (ray->side == 0 && ray->dir.x <= 0)
		wall->tex_num = 0;
	else if (ray->side == 0 && ray->dir.y > 0)
		wall->tex_num = 3;
	else if (ray->side == 0 && ray->dir.y <= 0)
		wall->tex_num = 2;
	wall->tex_x = (int)(wall->x * (double)img[wall->tex_num]->width);
	if ((ray->side == 0 && ray->dir.x > 0)
		|| (ray->side == 1 && ray->dir.y < 0))
		wall->tex_x = img[wall->tex_num]->width - wall->tex_x - 1;
	wall->tex_step = img[wall->tex_num]->height / (double)wall->height;
	wall->tex_pos = 0;
	if (wall->height > screen->height)
	{
		wall->tex_pos = (wall->draw_start
				- screen->height * 0.5
				+ wall->height * 0.5) * wall->tex_step;
	}
}

void	paint_wall(t_wall *wall, t_screen *screen, mlx_image_t *img[4], int x)
{
	int		y;
	t_color	color;

	y = wall->draw_start - 1;
	while (++y <= wall->draw_end)
	{
		wall->tex_y = (int)wall->tex_pos;
		if (wall->tex_y >= (int)img[wall->tex_num]->height)
			wall->tex_y = img[wall->tex_num]->height - 1;
		color = get_texture_color(img[wall->tex_num], wall->tex_x, wall->tex_y);
		put_pixel(screen->buffer, x, y, color);
		wall->tex_pos += wall->tex_step;
	}
}

void	new_render_view(t_info *info,
						double rangle,
						int x,
						t_color *color)
{
	t_ray	ray;
	t_wall	wall;

	ray = new_cast_ray(&info->screen, &info->map, &info->player, rangle);
	if (!ray.hit)
		return ;
	wall = init_wall(&ray, &info->screen, &info->player, rangle);
	init_textures(&wall, &ray, info->img, &info->screen);
	paint_wall(&wall, &info->screen, info->img, x);
	if (wall.draw_start > 0)
		draw_line(info->screen.buffer, v2_create(x, 0),
			v2_create(x, wall.draw_start - 1), color[1]);
	if (wall.draw_end < info->screen.height - 1)
		draw_line(info->screen.buffer, v2_create(x, wall.draw_end + 1),
			v2_create(x, info->screen.height - 1), color[0]);
}

/* ========================================================================== */

void	render2(void *param)
{
	t_info	*info;
	double	fov;
	double	step_view;
	double	rangle_view;
	int		x;

	info = param;
	fov = info->player.fov * DEG2RAD;
	step_view = fov / info->screen.width;
	rangle_view = info->player.angle * DEG2RAD - (fov * 0.5);
	x = -1;
	while (++x < info->screen.width)
	{
		new_render_view(info, fmod(rangle_view + (x * step_view), 2 * M_PI), x,
			(t_color [2]){info->floor_color, info->ceiling_color});
	}
}

void	render(void *param)
{
	t_info	*info;
	double	a;

	info = param;
	render2(info);
	new_render_minimap(&info->screen, &info->map, &info->player);
	a = 0;
	while (a < round(info->player.fov * 0.5))
	{
		new_cast_ray(&info->screen, &info->map, &info->player,
			(info->player.angle - a) * DEG2RAD);
		new_cast_ray(&info->screen, &info->map, &info->player,
			(info->player.angle + a) * DEG2RAD);
		a += 0.1;
	}
	new_render_player(&info->screen, &info->player);
}
