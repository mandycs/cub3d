/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:38 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/02/27 14:18:43 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	move_forward(t_info *info)
{
	t_player	*player;

	player = &info->player;
	player->position.x += player->speed * sin(player->angle * DEG2RAD);
	player->position.y += player->speed * cos(player->angle * DEG2RAD);
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
	double		angle;

	player = &info->player;
	angle = player->angle + 90;
	if (angle >= 360)
		angle -= 360;
	player->position.x -= player->speed * sin(angle * DEG2RAD);
	player->position.y -= player->speed * cos(angle * DEG2RAD);
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
	double		angle;

	player = &info->player;
	angle = player->angle + 90;
	if (angle > 360)
		angle -= 360;
	player->position.x += player->speed * sin(angle * DEG2RAD);
	player->position.y += player->speed * cos(angle * DEG2RAD);
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
	player->position.x -= player->speed * sin(player->angle * DEG2RAD);
	player->position.y -= player->speed * cos(player->angle * DEG2RAD);
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
