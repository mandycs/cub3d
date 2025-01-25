/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:43 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/01/25 12:12:24 by ribana-b         ###   ########.com      */
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
	end = calculate_wall_collision2(start, deg_to_rads(player->angle), map);
	draw_line(screen->buffer, start, end, green());
	i = -1;
	while (++i < PIXEL_SIZE - 1)
	{
		end = calculate_wall_collision2(start,
				deg_to_rads(bfl_mod(player->angle + i, 360)), map);
		draw_line(screen->buffer, start, end, green());
		end = calculate_wall_collision2(start,
				deg_to_rads(bfl_mod(player->angle - i, 360)), map);
		draw_line(screen->buffer, start, end, green());
	}
}

void	render(void *param)
{
	t_info	*info;

	info = param;
	render_view(&info->player, &info->map, &info->screen);
	//render_map(&info->map, &info->screen);
	//render_player(&info->player, &info->screen);
	//render_fov(&info->player, &info->map, &info->screen);
}
