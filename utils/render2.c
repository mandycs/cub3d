/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:42 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/03/16 19:31:40 by ribana-b         ###   ########.com      */
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
