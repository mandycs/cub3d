/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 01:40:00 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2026/09/03 02:35:20 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#ifdef __EMSCRIPTEN__

# include <emscripten/emscripten.h>

static void	web_frame(void *param)
{
	t_info	*info;

	info = param;
	mlx_loop(info->mlx);
	if (mlx_is_key_down(info->mlx, MLX_KEY_Q))
		emscripten_cancel_main_loop();
}

void	cub_run_loop(t_info *info)
{
	emscripten_set_main_loop_arg(web_frame, info, 0, true);
}

#else

void	cub_run_loop(t_info *info)
{
	mlx_loop(info->mlx);
}

#endif
