/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:38 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/03/16 21:56:03 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	move_forward(t_info *info)
{
	t_player	*player;
	t_map		*map;
	int			x;
	int			y;

	player = &info->player;
	map = &info->map;
	player->position.x += player->speed * sin(player->angle * DEG2RAD);
	player->position.y += player->speed * cos(player->angle * DEG2RAD);
	x = (int)(player->position.x);
	y = (int)(player->position.y);
	if (x < 0 || x >= map->rows
		|| y < 0 || y >= map->cols
		|| map->data[x][y] == '1')
	{
		player->position.x -= player->speed * sin(player->angle * DEG2RAD);
		player->position.y -= player->speed * cos(player->angle * DEG2RAD);
	}
	collision_forward(player, map);
	log_info("Move forward");
}

void	move_left(t_info *info)
{
	t_player	*player;
	double		angle;
	int			x;
	int			y;
	t_map		*map;

	map = &info->map;
	player = &info->player;
	angle = player->angle + 90;
	if (angle >= 360)
		angle -= 360;
	player->position.x -= player->speed * sin(angle * DEG2RAD);
	player->position.y -= player->speed * cos(angle * DEG2RAD);
	x = (int)(player->position.x);
	y = (int)(player->position.y);
	if (x < 0 || x >= map->rows
		|| y < 0 || y >= map->cols
		|| map->data[x][y] == '1')
	{
		player->position.x += player->speed * sin(angle * DEG2RAD);
		player->position.y += player->speed * cos(angle * DEG2RAD);
	}
	collision_left(player, map, angle);
	log_info("Move right");
}

void	move_right(t_info *info)
{
	t_player	*player;
	double		angle;
	int			x;
	int			y;
	t_map		*map;

	player = &info->player;
	angle = player->angle + 90;
	map = &info->map;
	if (angle > 360)
		angle -= 360;
	player->position.x += player->speed * sin(angle * DEG2RAD);
	player->position.y += player->speed * cos(angle * DEG2RAD);
	x = (int)(player->position.x);
	y = (int)(player->position.y);
	if (x < 0 || x >= map->rows
		|| y < 0 || y >= map->cols
		|| map->data[x][y] == '1')
	{
		player->position.x -= player->speed * sin(angle * DEG2RAD);
		player->position.y -= player->speed * cos(angle * DEG2RAD);
	}
	collision_right(player, map, angle);
	log_info("Move right");
}

void	move_backward(t_info *info)
{
	t_player	*player;
	int			x;
	int			y;
	t_map		*map;

	player = &info->player;
	map = &info->map;
	player->position.x -= player->speed * sin(player->angle * DEG2RAD);
	player->position.y -= player->speed * cos(player->angle * DEG2RAD);
	x = (int)(player->position.x - 0.5);
	y = (int)(player->position.y - 0.5);
	if (x < 0 || x >= map->rows
		|| y < 0 || y >= map->cols
		|| map->data[x][y] == '1')
	{
		player->position.x += player->speed * sin(player->angle * DEG2RAD);
		player->position.y += player->speed * cos(player->angle * DEG2RAD);
	}
	collision_backward(player, map);
	log_info("Move backward");
}
