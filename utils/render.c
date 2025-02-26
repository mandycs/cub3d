/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:43 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/02/26 17:35:19 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// TODO?: When the player is outside of the map it doesn't render anything
// *Maybe it is not necessary to see anything because I'll implement
// wall collision later.
void	render_view(t_player *player, t_map *map, t_screen *screen)
{
	double	step;
	double	angle;
	double	distance;
	int		x;

	angle = bfl_mod(player->angle - player->fov * 0.5, 360);
	step = (double)player->fov / screen->width;
	x = 0;
	while (x < screen->width)
	{
		distance = calculate_distance(player, map, angle);
		if (distance)
			render_wall(screen, x, distance, lightgreen());
		angle += step;
		++x;
	}
}

void	render_map(t_map *map, t_v2 *position, t_screen *screen)
{
	int	i;
	int	j;

	i = -1;
	(void)position;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
		{
			render_map_element(map, screen, i, j);
		}
	}
}

void	render_player(t_player *player, t_screen *screen)
{
	t_v2	position;
	t_v2	size;

	position = v2_create(player->position.y * screen->scale,
			player->position.x * screen->scale);
	size = v2_create(screen->scale, screen->scale);
	draw_rectangle(screen->buffer, position, size, lightred());
}

void	render_fov(t_player *player, t_map *map, t_screen *screen)
{
	t_v2	start;
	t_v2	end;
	int		i;

	start = v2_create(player->position.y * screen->scale + screen->scale * 0.5,
			player->position.x * screen->scale + screen->scale * 0.5);
	end = calculate_wall_collision2(start, deg_to_rads(player->angle), map);
	draw_line(screen->buffer, start, end, green());
	i = -1;
	while (++i < player->fov * 0.5)
	{
		end = calculate_wall_collision2(start,
				deg_to_rads(bfl_mod(player->angle + i, 360)), map);
		draw_line(screen->buffer, start, end, green());
		end = calculate_wall_collision2(start,
				deg_to_rads(bfl_mod(player->angle - i, 360)), map);
		draw_line(screen->buffer, start, end, green());
	}
}

// NOTE: The player position will be taked into account to render the minimap,
// so I can have a fixed size instead of drawing the whole map, useful for
// big maps.
void	new_render_minimap(t_screen *screen, t_map *map, t_player *player)
{
	(void)player;
	for (int x = 0; x < map->rows; ++x)
	{
		for (int y = 0; y < map->cols; ++y)
		{
			bool is_wall = map->data[x][y] == '1';
			bool is_floor = map->data[x][y] != '1' && map->data[x][y] != '\0'
						&& map->data[x][y] != '\n' && map->data[x][y] != ' ';
			int size = screen->scale;
			if (is_wall)
			{
				int resized_x = x * size;
				int resized_y = y * size;
				draw_rectangle(screen->buffer,
								v2_create(resized_y, resized_x),
								v2_create(size, size),
								gray());
			}
			else if (is_floor)
			{
				int resized_x = x * size;
				int resized_y = y * size;
				draw_rectangle(screen->buffer,
								v2_create(resized_y, resized_x),
								v2_create(size, size),
								black());
			}
		}
	}
}

void	new_render_player(t_screen *screen, t_player *player)
{
	int size = screen->scale;
	int resized_x = player->position.x * size;
	int resized_y = player->position.y * size;
	draw_rectangle(screen->buffer,
					v2_create(resized_y, resized_x),
					v2_create(size, size),
					lightred());
}

void new_cast_ray(t_screen *screen, t_map *map, t_player *player, double rangle)
{
    int size = screen->scale;
	t_v2 ray_start = v2_create(player->position.x * size, player->position.y * size);
	ray_start = v2_add_scalar(ray_start, 0.5 * size);
    t_v2 ray_dir = v2_create(sin(rangle), cos(rangle));
    t_v2 ray_step = v2_create(fabs(1 / ray_dir.x), fabs(1 / ray_dir.y));
    t_v2 map_check = ray_start;
	t_v2 step = v2_create(1, 1);
    t_v2 ray_length = v2_create(((map_check.x + 1) - ray_start.x) * ray_step.x,
								((map_check.y + 1) - ray_start.y) * ray_step.y);

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
    while (!hit)
    {
        if (ray_length.x < ray_length.y)
        {
            map_check.x += step.x;
            ray_length.x += ray_step.x;
            side = 0;
        }
        else
        {
            map_check.y += step.y;
            ray_length.y += ray_step.y;
            side = 1;
        }

		t_v2 check = v2_create(map_check.x / size, map_check.y / size);
		t_v2 res = v2_mult_scalar(check, size);
        if (check.x < 0 || check.x >= map->rows || check.y < 0 || check.y >= map->cols)
        {
            break;
        }
        if (map->data[(int)check.x][(int)check.y] == '1')
        {
            hit = true;
			draw_rectangle(screen->buffer, v2_create(res.y, res.x), v2_create(1, 1), yellow());
			draw_line(screen->buffer, v2_create(player->position.y * size + size * 0.5, player->position.x * size + size * 0.5), v2_create(res.y, res.x), lightgreen());
        }
    }
	(void)side;
	(void)size;
}

void	render(void *param)
{
	t_info	*info;

	info = param;
	//printf("FPS: %f\n", 1 / info->mlx->delta_time);
	new_render_minimap(&info->screen, &info->map, &info->player);
	for (int i = 0; i  < 180; ++i)
	{
		new_cast_ray(&info->screen, &info->map, &info->player, deg_to_rads(info->player.angle + i));
		new_cast_ray(&info->screen, &info->map, &info->player, deg_to_rads(info->player.angle - i));
	}
	new_render_player(&info->screen, &info->player);

	//render_view(&info->player, &info->map, &info->screen);
	//render_map(&info->map, &info->player.position, &info->screen);
	//render_player(&info->player, &info->screen);
	//render_fov(&info->player, &info->map, &info->screen);
}
