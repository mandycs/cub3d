/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:43 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/03/16 13:27:53 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/* ========================================================================== */

// NOTE: The player position will be taked into account to render the minimap,
// so I can have a fixed size instead of drawing the whole map, useful for
// big maps.
void	new_render_minimap(t_screen *screen, t_map *map, t_player *player)
{
	const int	size = screen->scale;
	int			x;
	int			y;

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
	const int	size = screen->scale;
	const int	resized_x = player->position.x * size - size * 0.5;
	const int	resized_y = player->position.y * size - size * 0.5;

	draw_rectangle(screen->buffer,
		v2_create(resized_y, resized_x),
		v2_create(size, size),
		lightred());
}

/* ========================================================================== */

t_v2	set_step(t_v2 ray_dir)
{
	t_v2	step;

	step = v2_create(1, 1);
	if (ray_dir.x < 0)
		step.x = -1;
	if (ray_dir.y < 0)
		step.y = -1;
	return (step);
}

void	init_ray(t_ray *ray,
						t_player *player,
						const int size,
						double rangle)
{
	ray->hit = false;
	ray->map_check = v2_create(floor(player->position.x * size),
			floor(player->position.y * size));
	ray->start = v2_create(player->position.x * size,
			player->position.y * size);
	ray->dir = v2_create(sin(rangle), cos(rangle));
	ray->step = v2_create(fabs(1 / ray->dir.x), fabs(1 / ray->dir.y));
	ray->length = v2_create((ray->map_check.x + 1 - ray->start.x) * ray->step.x,
			(ray->map_check.y + 1 - ray->start.y) * ray->step.y);
	ray->map_step = set_step(ray->dir);
	if (ray->dir.x < 0)
		ray->length.x = (ray->start.x - ray->map_check.x) * ray->map_step.x;
	if (ray->dir.y < 0)
		ray->length.y = (ray->start.y - ray->map_check.y) * ray->map_step.y;
}

bool	keep_looping(t_ray *ray,
						t_map *map,
						t_screen *screen)
{
	t_v2		check;
	const int	size = screen->scale;

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
		ray->map_check.x += ray->map_step.x;
		ray->length.x += ray->step.x;
	}
	else
	{
		ray->map_check.y += ray->map_step.y;
		ray->length.y += ray->step.y;
	}
}

t_ray	new_cast_ray(t_screen *screen,
						t_map *map,
						t_player *player,
						double rangle)
{
	const int	size = screen->scale;
	t_ray		ray;

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

t_color get_texture_color(mlx_image_t *img, int x, int y)
{
	t_color color;
	uint32_t pos = ((uint32_t)y * img->width + x) * 4;

	if (x < 0 || y < 0 || x >= (int)img->width || y >= (int)img->height)
		return (black());
	color.r = img->pixels[pos + 0];
	color.g = img->pixels[pos + 1];
	color.b = img->pixels[pos + 2];
	color.a = img->pixels[pos + 3];
	return (color);
}

// TODO(srvariable): Merge new_render_view and new_cast_ray to optimize.
// I might need to create another struct to values related to rays
void new_render_view(t_screen *screen, t_map *map, t_player *player, double rangle, int x, mlx_image_t *img[4], t_color floor_color, t_color ceiling_color)
{
	double size = screen->scale;
	t_v2 ray_start = v2_create(player->position.x * size, player->position.y * size);
	t_v2 ray_dir = v2_create(sin(rangle), cos(rangle));
	t_v2 ray_step = v2_create(fabs(1 / ray_dir.x), fabs(1 / ray_dir.y));
	t_v2 map_check = v2_create(floor(player->position.x * size), floor(player->position.y * size));
	t_v2 step = v2_create(1, 1);
	t_v2 ray_length = v2_create((map_check.x + 1 - ray_start.x) * ray_step.x,
								(map_check.y + 1 - ray_start.y) * ray_step.y);

	if (ray_dir.x < 0)
	{
		step.x = -1;
		ray_length.x = (ray_start.x - map_check.x) * ray_step.x;
	}
	if (ray_dir.y < 0)
	{
		step.y = -1;
		ray_length.y = (ray_start.y - map_check.y) * ray_step.y;
	}

	bool hit = false;
	int side = 0;
	double distance = 0;
	while (!hit)
	{
		if (ray_length.x < ray_length.y)
		{
			distance = ray_length.x;
			map_check.x += step.x;
			ray_length.x += ray_step.x;
			side = 0;
		}
		else
		{
			distance = ray_length.y;
			map_check.y += step.y;
			ray_length.y += ray_step.y;
			side = 1;
		}

		t_v2 check = v2_create(map_check.x / size, map_check.y / size);
		if (check.x < 0 || check.x >= map->rows || check.y < 0 || check.y >= map->cols)
		{
			break;
		}
		if (map->data[(int)check.x][(int)check.y] == '1')
		{
			hit = true;
		}
	}
	if (hit)
	{
		int line_height = (int)(screen->height * size / (distance * cos(rangle - (player->angle * DEG2RAD))));
		int draw_start = screen->height / 2 - line_height / 2;
		if (draw_start < 0)
		{
			draw_start = 0;
		}
		int draw_end = screen->height / 2 + line_height / 2;
		if (draw_end >= screen->height)
		{
			draw_end = screen->height - 1;
		}
		double wall_x;
		int texNum = 0;
		if (side == 0)
		{
			wall_x = (ray_start.y + distance * ray_dir.y) / size;
			if (!(rangle >= 0 && rangle < M_PI))
			{
				texNum = 0;
			}
			else
			{
				texNum = 1;
			}
		}
		if (side == 1)
		{
			wall_x = (ray_start.x + distance * ray_dir.x) / size;
			if (rangle >= M_PI / 2 && rangle < 3 * M_PI / 2)
			{
				texNum = 2;
			}
			else
			{
				texNum = 3;
			}
		}
		wall_x -= (int)wall_x;
		int tex_x = (int)(wall_x * (double)img[texNum]->width);
		if ((side == 0 && ray_dir.x > 0) || (side == 1 && ray_dir.y < 0))
		{
			tex_x = img[texNum]->width - tex_x - 1;
		}
		double step_tex = img[texNum]->height / (double)line_height;
		double tex_pos = 0;
		if (line_height > screen->height)
		{
			tex_pos = (draw_start - screen->height * 0.5 + line_height * 0.5) * step_tex;
		}
		for (int y = draw_start; y <= draw_end; ++y)
		{
			int tex_y = (int)tex_pos;
			if (tex_y >= (int)img[texNum]->height)
			{
				tex_y = img[texNum]->height - 1;
			}
			t_color color = get_texture_color(img[texNum], tex_x, tex_y);
			put_pixel(screen->buffer, x, y, color);
			tex_pos += step_tex;
		}
		if (draw_start > 0)
		{
			draw_line(screen->buffer, v2_create(x, 0), v2_create(x, draw_start - 1), ceiling_color);
		}
		if (draw_end < screen->height - 1)
		{
			draw_line(screen->buffer, v2_create(x, draw_end + 1), v2_create(x, screen->height - 1), floor_color);
		}
	}
}

/* ========================================================================== */

void	render(void *param)
{
	t_info	*info;

	info = param;
	if (mlx_is_key_down(info->mlx, MLX_KEY_P))
	{
		printf("FPS: %f\n", 1 / info->mlx->delta_time);
		printf("Angle: %f\n", info->player.angle);
	}
	double fov = info->player.fov * DEG2RAD;
	double step_view = fov / info->screen.width;
	double rangle_view = info->player.angle * DEG2RAD - (fov * 0.5);
	for (int x = 0; x < info->screen.width; ++x)
	{
		double new_rangle_view = fmod(rangle_view + (x * step_view), 2 * M_PI);
		new_render_view(&info->screen, &info->map, &info->player, new_rangle_view, x, info->img, info->floor_color, info->ceiling_color);
	}
	new_render_minimap(&info->screen, &info->map, &info->player);
	for (double a = 0; a < round(info->player.fov * 0.5); ++a)
	{
		new_cast_ray(&info->screen, &info->map, &info->player, (info->player.angle - a) * DEG2RAD);
		new_cast_ray(&info->screen, &info->map, &info->player, (info->player.angle + a) * DEG2RAD);
	}
	new_render_player(&info->screen, &info->player);
}
