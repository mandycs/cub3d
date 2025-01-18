/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:43 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/01/18 21:42:38 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	render_view(t_player *player, t_map *map, t_screen *screen)
{
	double	step;
	double	angle;
	double	distance;
	int		x;

	step = (double)player->fov / screen->width;
	angle = bfl_mod(player->angle - player->fov * 0.5, 360);
	x = 0;
	render_ceiling(screen, blue());
	render_floor(screen, lightblue());
	while (x < screen->width)
	{
		distance = calculate_distance(player, map, angle);
		render_wall(screen, x, distance, lightgreen());
		angle += step;
		++x;
	}
}

void	render_map(t_map *map, t_screen *screen)
{
	int	i;
	int	j;

	i = -1;
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

	position = v2_create(player->position.y, player->position.x);
	size = v2_create(PIXEL_SIZE, PIXEL_SIZE);
	draw_rectangle(screen->buffer, position, size, lightred());
}

void	render_fov(t_player *player, t_map *map, t_screen *screen)
{
	t_v2	start;
	t_v2	end;
	int		i;

	start = v2_create(player->position.y + PIXEL_SIZE * 0.5,
			player->position.x + PIXEL_SIZE * 0.5);
	end = calculate_wall_collision(start, deg_to_rads(player->angle),
			player->fov, map);
	draw_line(screen->buffer, start, end, green());
	i = -1;
	while (++i < 31)
	{
		end = calculate_wall_collision(start,
				deg_to_rads(bfl_mod(player->angle + i, 360)), player->fov, map);
		draw_line(screen->buffer, start, end, green());
		end = calculate_wall_collision(start,
				deg_to_rads(bfl_mod(player->angle - i, 360)), player->fov, map);
		draw_line(screen->buffer, start, end, green());
	}
}

void	render(void *param)
{
	t_info	*info;

	info = param;
	render_view(&info->player, &info->map, &info->screen);
	render_map(&info->map, &info->screen);
	render_player(&info->player, &info->screen);
	render_fov(&info->player, &info->map, &info->screen);
}
