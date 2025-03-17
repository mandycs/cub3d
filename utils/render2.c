/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:42 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/03/17 09:49:17 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	draw_element(t_v2 *p, t_screen *screen, t_map *map)
{
	const int	size = screen->scale;

	if (map->data[(int)p[1].x][(int)p[1].y] == '1')
		draw_rectangle(screen->buffer, v2_create((p[1].y - p[0].y) * size,
				(p[1].x - p[0].x) * size), v2_create(size, size), gray());
	else if (map->data[(int)p[1].x][(int)p[1].y] != '1'
				&& map->data[(int)p[1].x][(int)p[1].y] != '\0'
				&& map->data[(int)p[1].x][(int)p[1].y] != '\n'
				&& map->data[(int)p[1].x][(int)p[1].y] != ' ')
		draw_rectangle(screen->buffer, v2_create((p[1].y - p[0].y) * size,
				(p[1].x - p[0].x) * size), v2_create(size, size), black());
}

static void	init_start_current_end_x(t_v2 *p,
										t_player *player,
										t_screen *screen,
										t_map *map)
{
	const int	size = screen->scale;

	p[1].x = (int)player->position.x - size;
	p[2].x = (int)player->position.x + size;
	if (p[1].x <= -1)
		p[2].x = (int)player->position.x + size - fmod(p[1].x + 1, size);
	if (p[2].x >= map->rows)
	{
		p[1].x = (int)player->position.x - size - fmod(p[2].x, map->rows);
		p[2].x = map->rows;
	}
	if (p[1].x <= -1)
		p[1].x = -1;
	p[0].x = p[1].x + 1;
}

// TODO: Apply the logic on the rays, I might need another function...
void	new_render_minimap(t_screen *screen, t_map *map, t_player *player)
{
	const int	size = screen->scale;
	t_v2		p[3];

	init_start_current_end_x(p, player, screen, map);
	while (++p[1].x < p[2].x)
	{
		p[1].y = (int)player->position.y - size;
		p[2].y = (int)player->position.y + size;
		if (p[1].y <= -1)
		{
			p[2].y = (int)player->position.y + size - fmod(p[1].y + 1, size);
			p[1].y = -1;
		}
		if (p[2].y >= map->cols)
		{
			p[1].y = (int)player->position.y - size - fmod(p[2].y, map->cols);
			p[2].y = map->cols;
		}
		p[0].y = p[1].y + 1;
		while (++p[1].y < p[2].y)
			draw_element(p, screen, map);
	}
}

void	new_render_player(t_screen *screen, t_player *player, t_map *map)
{
	const double	size = screen->scale;
	double			x;
	double			y;

	x = player->position.x;
	y = player->position.y;
	if (player->position.y >= size)
		y = y - (player->position.y - size);
	if (map->cols - player->position.y < size)
		y = 2 * size - (map->cols - player->position.y) - 1;
	if (player->position.x >= size)
		x = x - (player->position.x - size);
	if (map->rows - player->position.x < size)
		x = 2 * size - (map->rows - player->position.x) - 1;
	draw_rectangle(screen->buffer,
		v2_create(y * size - size, x * size - size),
		v2_create(size, size), lightred());
}
