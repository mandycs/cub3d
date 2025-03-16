/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:51:10 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/03/16 21:56:23 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	collision_forward(t_player *player, t_map *map)
{
	int	x;
	int	y;

	x = (int)(player->position.x - 0.5);
	y = (int)(player->position.y);
	if (x < 0 || x >= map->rows
		|| y < 0 || y >= map->cols
		|| map->data[x][y] == '1')
	{
		player->position.x -= player->speed * sin(player->angle * DEG2RAD);
		player->position.y -= player->speed * cos(player->angle * DEG2RAD);
	}
	x = (int)(player->position.x);
	y = (int)(player->position.y - 0.5);
	if (x < 0 || x >= map->rows
		|| y < 0 || y >= map->cols
		|| map->data[x][y] == '1')
	{
		player->position.x -= player->speed * sin(player->angle * DEG2RAD);
		player->position.y -= player->speed * cos(player->angle * DEG2RAD);
	}
}

void	collision_right(t_player *player, t_map *map, double angle)
{
	int	x;
	int	y;

	x = (int)(player->position.x - 0.5);
	y = (int)(player->position.y);
	if (x < 0 || x >= map->rows
		|| y < 0 || y >= map->cols
		|| map->data[x][y] == '1')
	{
		player->position.x -= player->speed * sin(angle * DEG2RAD);
		player->position.y -= player->speed * cos(angle * DEG2RAD);
	}
	x = (int)(player->position.x);
	y = (int)(player->position.y - 0.5);
	if (x < 0 || x >= map->rows
		|| y < 0 || y >= map->cols
		|| map->data[x][y] == '1')
	{
		player->position.x -= player->speed * sin(angle * DEG2RAD);
		player->position.y -= player->speed * cos(angle * DEG2RAD);
	}
}

void	collision_left(t_player *player, t_map *map, double angle)
{
	int	x;
	int	y;

	x = (int)(player->position.x - 0.5);
	y = (int)(player->position.y);
	if (x < 0 || x >= map->rows
		|| y < 0 || y >= map->cols
		|| map->data[x][y] == '1')
	{
		player->position.x += player->speed * sin(angle * DEG2RAD);
		player->position.y += player->speed * cos(angle * DEG2RAD);
	}
	x = (int)(player->position.x);
	y = (int)(player->position.y - 0.5);
	if (x < 0 || x >= map->rows
		|| y < 0 || y >= map->cols
		|| map->data[x][y] == '1')
	{
		player->position.x += player->speed * sin(angle * DEG2RAD);
		player->position.y += player->speed * cos(angle * DEG2RAD);
	}
}

void	collision_backward(t_player *player, t_map *map)
{
	int	x;
	int	y;

	x = (int)(player->position.x - 0.5);
	y = (int)(player->position.y);
	if (x < 0 || x >= map->rows
		|| y < 0 || y >= map->cols
		|| map->data[x][y] == '1')
	{
		player->position.x += player->speed * sin(player->angle * DEG2RAD);
		player->position.y += player->speed * cos(player->angle * DEG2RAD);
	}
	x = (int)(player->position.x);
	y = (int)(player->position.y - 0.5);
	if (x < 0 || x >= map->rows
		|| y < 0 || y >= map->cols
		|| map->data[x][y] == '1')
	{
		player->position.x += player->speed * sin(player->angle * DEG2RAD);
		player->position.y += player->speed * cos(player->angle * DEG2RAD);
	}
}
