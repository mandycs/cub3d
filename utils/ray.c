/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:31:35 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/03/17 09:51:15 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
