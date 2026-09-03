/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:34 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2026/09/03 03:46:20 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	clear_background(void *param)
{
	t_info			*info;
	unsigned int	i;

	info = param;
	i = 0;
	while (i < info->screen.buffer->width * info->screen.buffer->height
		* sizeof(int))
	{
		set_color(&info->screen.buffer->pixels[i], darkgray());
		i += 4;
	}
}

static void	swap_buffers(void *param)
{
	t_info	*info;

	info = param;
	bfl_memcpy(info->screen.view->pixels, info->screen.buffer->pixels,
		info->screen.width * info->screen.height * sizeof(int));
}

static void	hook_control_keys(void *param)
{
	t_info	*info;

	info = param;
	if (mlx_is_key_down(info->mlx, MLX_KEY_Q)
		|| mlx_is_key_down(info->mlx, MLX_KEY_ESCAPE))
		cub_close_window(info->mlx);
	if (mlx_is_key_down(info->mlx, MLX_KEY_W))
		move_forward(info);
	if (mlx_is_key_down(info->mlx, MLX_KEY_A))
		move_left(info);
	if (mlx_is_key_down(info->mlx, MLX_KEY_D))
		move_right(info);
	if (mlx_is_key_down(info->mlx, MLX_KEY_S))
		move_backward(info);
	if (mlx_is_key_down(info->mlx, MLX_KEY_LEFT))
		rotate_left(info);
	if (mlx_is_key_down(info->mlx, MLX_KEY_RIGHT))
		rotate_right(info);
}

static void	is_key_pressed(mlx_key_data_t keydata, void *param)
{
	t_info	*info;

	info = param;
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		info->is_cursor_free = !info->is_cursor_free;
}

void	hook_loader(t_info *info)
{
	mlx_loop_hook(info->mlx, update, info);
	mlx_loop_hook(info->mlx, hook_control_keys, info);
	mlx_key_hook(info->mlx, is_key_pressed, info);
	mlx_cursor_hook(info->mlx, rotate_mouse, info);
	mlx_loop_hook(info->mlx, clear_background, info);
	mlx_loop_hook(info->mlx, render, info);
	mlx_loop_hook(info->mlx, swap_buffers, info);
}
