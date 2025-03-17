/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:46 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/03/17 17:02:32 by ribana-b         ###   ########.com      */
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

void	rotate_mouse(double xpos, double ypos, void *param)
{
	t_info			*info;
	const double	rotation_speed = 30.0;

	(void)ypos;
	info = param;
	if (xpos < info->screen.width * 0.5)
	{
		info->player.angle = fmod(info->player.angle
				- (rotation_speed * info->mlx->delta_time), 360.0);
		log_info("Rotate left");
	}
	if (xpos > info->screen.width * 0.5)
	{
		info->player.angle = fmod(info->player.angle
				+ (rotation_speed * info->mlx->delta_time), 360.0);
		log_info("Rotate right");
	}
}
