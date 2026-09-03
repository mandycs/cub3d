/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:51:10 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2026/09/03 02:34:25 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static bool	is_wall(t_map *map, double x, double y)
{
	int	row;
	int	col;

	row = (int)x;
	col = (int)y;
	return (row < 0 || row >= map->rows
		|| col < 0 || col >= map->cols
		|| map->data[row][col] == WALL);
}

void	resolve_movement(t_player *player, t_map *map, t_v2 delta)
{
	double	edge_x;
	double	edge_y;

	edge_x = PLAYER_RADIUS;
	if (delta.x < 0)
		edge_x = -PLAYER_RADIUS;
	edge_y = PLAYER_RADIUS;
	if (delta.y < 0)
		edge_y = -PLAYER_RADIUS;
	if (!is_wall(map, player->position.x + delta.x + edge_x,
			player->position.y))
		player->position.x += delta.x;
	if (!is_wall(map, player->position.x,
			player->position.y + delta.y + edge_y))
		player->position.y += delta.y;
}
