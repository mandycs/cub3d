/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:35 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/01/25 12:50:58 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	clear_background(void *param)
{
	t_info			*info;
	unsigned int	i;

	info = param;
	i = 0;
	while (i < info->screen.buffer->width * info->screen.buffer->height
		* sizeof(int))
	{
		set_color(&info->screen.buffer->pixels[i], gray());
		i += 4;
	}
}

void	swap_buffers(void *param)
{
	t_info	*info;

	info = param;
	bfl_memcpy(info->screen.view->pixels, info->screen.buffer->pixels,
		info->screen.width * info->screen.height * sizeof(int));
}

void	update(void *param)
{
	t_info		*info;
	static bool	is_speed_scaled;

	info = param;
	if (!is_speed_scaled)
	{
		is_speed_scaled = true;
		info->player.speed = info->player.speed * info->mlx->delta_time;
	}
}
