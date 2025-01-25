/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:38 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/01/19 14:16:26 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	move_forward(t_info *info)
{
	t_player	*player;

	player = &info->player;
	player->position.x += player->speed * sin(deg_to_rads(player->angle));
	player->position.y += player->speed * cos(deg_to_rads(player->angle));
	if (player->position.x < 0)
		player->position.x = 0;
	if (player->position.y < 0)
		player->position.y = 0;
	if (player->position.x >= info->screen.height - PIXEL_SIZE)
		player->position.x = info->screen.height - PIXEL_SIZE;
	if (player->position.y >= info->screen.width - PIXEL_SIZE)
		player->position.y = info->screen.width - PIXEL_SIZE;
	log_info("Move forward");
}

void	move_left(t_info *info)
{
	t_player	*player;

	player = &info->player;
	player->position.x -= player->speed
		* sin(deg_to_rads(bfl_mod(player->angle + 90, 360)));
	player->position.y -= player->speed
		* cos(deg_to_rads(bfl_mod(player->angle + 90, 360)));
	if (player->position.x < 0)
		player->position.x = 0;
	if (player->position.y < 0)
		player->position.y = 0;
	if (player->position.x >= info->screen.height - PIXEL_SIZE)
		player->position.x = info->screen.height - PIXEL_SIZE;
	if (player->position.y >= info->screen.width - PIXEL_SIZE)
		player->position.y = info->screen.width - PIXEL_SIZE;
	log_info("Move right");
}

void	move_right(t_info *info)
{
	t_player	*player;

	player = &info->player;
	player->position.x += player->speed
		* sin(deg_to_rads(bfl_mod(player->angle + 90, 360)));
	player->position.y += player->speed
		* cos(deg_to_rads(bfl_mod(player->angle + 90, 360)));
	if (player->position.x < 0)
		player->position.x = 0;
	if (player->position.y < 0)
		player->position.y = 0;
	if (player->position.x >= info->screen.height - PIXEL_SIZE)
		player->position.x = info->screen.height - PIXEL_SIZE;
	if (player->position.y >= info->screen.width - PIXEL_SIZE)
		player->position.y = info->screen.width - PIXEL_SIZE;
	log_info("Move right");
}

void	move_backward(t_info *info)
{
	t_player	*player;

	player = &info->player;
	player->position.x -= player->speed * sin(deg_to_rads(player->angle));
	player->position.y -= player->speed * cos(deg_to_rads(player->angle));
	if (player->position.x < 0)
		player->position.x = 0;
	if (player->position.y < 0)
		player->position.y = 0;
	if (player->position.x >= info->screen.height - PIXEL_SIZE)
		player->position.x = info->screen.height - PIXEL_SIZE;
	if (player->position.y >= info->screen.width - PIXEL_SIZE)
		player->position.y = info->screen.width - PIXEL_SIZE;
	log_info("Move backward");
}
