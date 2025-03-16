/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_distance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:27 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/02/15 14:08:26 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double	calculate_distance(t_player *player, t_map *map, double angle)
{
	double	distance;
	t_v2	start;
	t_v2	end;
	t_v2	zero;

	start = v2_create(player->position.y + PIXEL_SIZE * 0.5,
			player->position.x + PIXEL_SIZE * 0.5);
	end = calculate_wall_collision(start, deg_to_rads(angle), map);
	zero = v2_zero();
	if (v2_equals(end, zero))
		return (0);
	distance = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
	distance *= cos(deg_to_rads(bfl_mod(angle - player->angle, 360)));
	return (distance);
}
