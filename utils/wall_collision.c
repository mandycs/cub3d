/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:50 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/01/19 13:30:17 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	is_wall_collision(t_map *map, int x, int y)
{
	int		i;
	int		j;

	i = x / PIXEL_SIZE;
	j = y / PIXEL_SIZE;
	if (i >= 0 && i < map->cols && j >= 0 && j < map->rows
		&& map->data[j][i] == '1')
		return (true);
	i = (x + 1) / PIXEL_SIZE;
	j = y / PIXEL_SIZE;
	return (i >= 0 && i < map->cols && j >= 0 && j < map->rows
		&& map->data[j][i] == '1');
}

// NOTE: Angle must be in rads
// This is for render
t_v2	calculate_wall_collision(t_v2 start, double angle, t_map *map)
{
	t_v2	p;
	int		i;

	i = -1;
	p = v2_create(start.x, start.y);
	while (++i < DISTANCE_LENGTH)
	{
		p.x += cos(angle);
		p.y += sin(angle);
		if (is_wall_collision(map, p.x, p.y))
			return (p);
	}
	return (v2_zero());
}

// NOTE: Angle must be in rads
// This is for fov
t_v2	calculate_wall_collision2(t_v2 start, double angle, t_map *map)
{
	t_v2	p;
	int		i;

	i = -1;
	p = v2_create(start.x, start.y);
	while (++i < DISTANCE_LENGTH)
	{
		p.x += cos(angle);
		p.y += sin(angle);
		if (is_wall_collision(map, p.x, p.y))
			return (p);
	}
	return (p);
}
