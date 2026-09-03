/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:35 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2026/09/03 02:39:48 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	scale_speed(t_info *info)
{
	static bool	is_speed_scaled;

	if (is_speed_scaled || info->mlx->delta_time <= 0.0
		|| info->mlx->delta_time >= 0.1)
		return ;
	is_speed_scaled = true;
	info->player.speed = info->player.speed * info->mlx->delta_time;
}

#ifdef __EMSCRIPTEN__

static void	update_cursor(t_info *info)
{
	static bool	last_free = true;

	if (info->is_cursor_free == last_free)
		return ;
	last_free = info->is_cursor_free;
	if (info->is_cursor_free)
		mlx_set_cursor_mode(info->mlx, MLX_MOUSE_NORMAL);
	else
		mlx_set_cursor_mode(info->mlx, MLX_MOUSE_DISABLED);
}

#else

static void	update_cursor(t_info *info)
{
	if (!info->is_cursor_free)
	{
		mlx_set_mouse_pos(info->mlx, info->screen.width * 0.5,
			info->screen.height * 0.5);
		mlx_set_cursor_mode(info->mlx, MLX_MOUSE_HIDDEN);
	}
	else
		mlx_set_cursor_mode(info->mlx, MLX_MOUSE_NORMAL);
}

#endif

void	update(void *param)
{
	t_info	*info;

	info = param;
	scale_speed(info);
	update_cursor(info);
}
