/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:46 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2026/09/03 02:43:53 by ribana-b         ###   ########.com      */
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

static void	apply_rotation(t_info *info, double sign)
{
	const double	rotation_speed = 30.0;

	info->player.angle = fmod(info->player.angle
			+ (sign * rotation_speed * info->mlx->delta_time), 360.0);
}

#ifdef __EMSCRIPTEN__

void	rotate_mouse(double xpos, double ypos, void *param)
{
	t_info			*info;
	static double	last_x;
	double			delta;

	(void)ypos;
	info = param;
	delta = xpos - last_x;
	last_x = xpos;
	if (info->is_cursor_free)
		return ;
	if (delta < 0.0)
		apply_rotation(info, -1.0);
	else if (delta > 0.0)
		apply_rotation(info, 1.0);
}

#else

void	rotate_mouse(double xpos, double ypos, void *param)
{
	t_info	*info;

	(void)ypos;
	info = param;
	if (info->is_cursor_free)
		return ;
	if (xpos < info->screen.width * 0.5)
		apply_rotation(info, -1.0);
	if (xpos > info->screen.width * 0.5)
		apply_rotation(info, 1.0);
}

#endif
