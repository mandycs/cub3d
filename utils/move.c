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
	t_v2		delta;

	player = &info->player;
	delta = v2_create(player->speed * sin(player->angle * DEG2RAD),
			player->speed * cos(player->angle * DEG2RAD));
	resolve_movement(player, &info->map, delta);
	log_info("Move forward");
}

void	move_backward(t_info *info)
{
	t_player	*player;
	t_v2		delta;

	player = &info->player;
	delta = v2_create(-player->speed * sin(player->angle * DEG2RAD),
			-player->speed * cos(player->angle * DEG2RAD));
	resolve_movement(player, &info->map, delta);
	log_info("Move backward");
}

void	move_left(t_info *info)
{
	t_player	*player;
	t_v2		delta;
	double		angle;

	player = &info->player;
	angle = player->angle + 90;
	if (angle >= 360)
		angle -= 360;
	delta = v2_create(-player->speed * sin(angle * DEG2RAD),
			-player->speed * cos(angle * DEG2RAD));
	resolve_movement(player, &info->map, delta);
	log_info("Move left");
}

void	move_right(t_info *info)
{
	t_player	*player;
	t_v2		delta;
	double		angle;

	player = &info->player;
	angle = player->angle + 90;
	if (angle >= 360)
		angle -= 360;
	delta = v2_create(player->speed * sin(angle * DEG2RAD),
			player->speed * cos(angle * DEG2RAD));
	resolve_movement(player, &info->map, delta);
	log_info("Move right");
}
