/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:46 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/03/16 22:02:34 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	rotate_left(t_info *info)
{
	const double	rotation_speed = 100.0;

	info->player.angle = fmod(info->player.angle
			- (rotation_speed * info->mlx->delta_time), 360.0);
	log_info("Rotate left");
}

void	rotate_right(t_info *info)
{
	const double	rotation_speed = 100.0;

	info->player.angle = fmod(info->player.angle
			+ (rotation_speed * info->mlx->delta_time), 360.0);
	log_info("Rotate right");
}
