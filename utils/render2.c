/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:42 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/01/18 21:27:12 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	render_map_element(t_map *map, t_screen *screen, int i, int j)
{
	t_v2	position;
	t_v2	size;

	position = v2_create(j * PIXEL_SIZE, i * PIXEL_SIZE);
	size = v2_create(PIXEL_SIZE, PIXEL_SIZE);
	if (map->data[i][j] != '1' && map->data[i][j] != ' ')
		draw_rectangle(screen->buffer, position, size, white());
	else if (map->data[i][j] == '1')
		draw_rectangle(screen->buffer, position, size, black());
}

void	render_ceiling(t_screen *screen, t_color color)
{
	t_v2	start;
	t_v2	end;
	int		x;

	x = 0;
	start = v2_create(x, 0);
	end = v2_create(x, screen->height * 0.5);
	while (x < screen->width)
	{
		start.x = x;
		end.x = x;
		draw_line(screen->buffer, start, end, color);
		++x;
	}
}

void	render_floor(t_screen *screen, t_color color)
{
	t_v2	start;
	t_v2	end;
	int		x;

	x = 0;
	start = v2_create(x, screen->height * 0.5);
	end = v2_create(x, screen->height - 1);
	while (x < screen->width)
	{
		start.x = x;
		end.x = x;
		draw_line(screen->buffer, start, end, color);
		++x;
	}
}

// TODO: Rename this function
void	render_wall(t_screen *screen, int x, double distance, t_color color)
{
	t_v2	start;
	t_v2	end;
	int		wall_start;
	int		wall_end;
	int		wall_height;

	wall_height = (int)(screen->height * PIXEL_SIZE * 0.5 / distance);
	wall_start = screen->height * 0.5 - wall_height * 0.5;
	wall_end = wall_start + wall_height;
	start = v2_create(x, wall_start);
	end = v2_create(x, wall_end);
	if (end.y >= screen->height)
		end.y = screen->height - 1;
	draw_line(screen->buffer, start, end, color);
	draw_line(screen->buffer, v2_create(x, 0), start, lightyellow());
	draw_line(screen->buffer, v2_create(x, end.y),
		v2_create(x, screen->height), lightblue());
}
