/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:23:51 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/01/19 14:23:52 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

// Single file program to facilitate the development, I'll refactor it later

/**
 * TODO:
 *
 * - Reimplement wall collision when moving
 * - Implement textures
 * - Have a limit distance rendering
 * - Make logs to accept va_args or create something like sprintf
 * to allow giving more information
 * - Reimplement the minimap to scale according to the size of the screen
 *
 * NOTE:
 * Don't activate logging while outside of the map, because it will lag due
 * to printing error
 *
 * MANDATORY:
 * - Parse the map
 *   - Check valid chars (01NSWE)
 *   - Check map closed
 *   - Allow multiple lines between parameters except for the map
 *   - Allow any order, except for the map which has to be at the end
 * - Different wall textures depending on the side
 * - Camera rotation with Left/Right Arrows (DONE)
 * - Move with WASD (DONE)
 * - Press ESC to close the window (DONE)
 * - Closing the window terminates the program (DONE)
 *
 * BONUS:
 * - Wall collisions
 * - A minimap system (DONE)
 * - Doors that can open and close
 * - Animated sprites
 * - Camera rotation with mouse
 */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	static t_info	info;

	(void)argc;
	(void)argv;
	if (!cub_create(&info))
	{
		if (info.mlx)
			cub_destroy(&info);
		return (log_error("Couldn't create cub resources"));
	}
	if (mlx_image_to_window(info.mlx, info.screen.view, 0, 0) < 0)
	{
		cub_destroy(&info);
		return (log_error("Couldn't draw the screen"));
	}
	hook_loader(&info);
	mlx_loop(info.mlx);
	cub_destroy(&info);
	return (0);
}
