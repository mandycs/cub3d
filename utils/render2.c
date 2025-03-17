/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:42 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/03/17 05:35:56 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// TODO: Refactor this and apply the logic on the rays, I might need another
// function...
void	new_render_minimap(t_screen *screen, t_map *map, t_player *player)
{
	const int	size = screen->scale;
	t_v2		c;
	t_v2		e;
	t_v2		s;

	c.x = (int)player->position.x - size;
	e.x = (int)player->position.x + size;
	if (c.x <= -1)
		e.x = (int)player->position.x + size - fmod(c.x + 1, size);
	if (e.x >= map->rows)
	{
		c.x = (int)player->position.x - size - fmod(e.x, map->rows);
		e.x = map->rows;
	}
	if (c.x <= -1)
		c.x = -1;
	s.x = c.x + 1;
	while (++c.x < e.x)
	{
		c.y = (int)player->position.y - size;
		e.y = (int)player->position.y + size;
		if (c.y <= -1)
		{
			e.y = (int)player->position.y + size - fmod(c.y + 1, size);
			c.y = -1;
		}
		if (e.y >= map->cols)
		{
			c.y = (int)player->position.y - size - fmod(e.y, map->cols);
			e.y = map->cols;
		}
		s.y = c.y + 1;
		while (++c.y < e.y)
		{
			if (map->data[(int)c.x][(int)c.y] == '1')
				draw_rectangle(screen->buffer, v2_create((c.y - s.y) * size,
						(c.x - s.x) * size), v2_create(size, size), gray());
			else if (map->data[(int)c.x][(int)c.y] != '1'
						&& map->data[(int)c.x][(int)c.y] != '\0'
						&& map->data[(int)c.x][(int)c.y] != '\n'
						&& map->data[(int)c.x][(int)c.y] != ' ')
				draw_rectangle(screen->buffer, v2_create((c.y - s.y) * size,
						(c.x - s.x) * size), v2_create(size, size), black());
		}
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
