/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_resources.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:31 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/01/26 19:52:23 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	cub_create(t_info *info, t_cub *cub)
{
	info->mlx = mlx_init(PIXEL_SIZE * 16 * RESIZE, PIXEL_SIZE * 9 * RESIZE,
			"Cub3D", false);
	if (!info->mlx)
		return (false);
	log_info("Window initialized");
	if (!create_player(&info->player, cub))
		return (!log_error("Couldn't create player"));
	if (!create_map(&info->map, cub))
		return (!log_error("Couldn't create map"));
	if (!create_textures(info, cub))
		return (!log_error("Couldn't create textures"));
	if (!create_screen(&info->screen, info->mlx))
		return (!log_error("Couldn't create screen"));
	return (true);
}

void	cub_close_window(mlx_t *mlx)
{
	log_info("Window closed");
	mlx_close_window(mlx);
}

void	cub_destroy(t_info *info, t_cub *cub)
{
	ft_free_cub(cub);
	ft_close_fd(cub);
	bfl_free(&cub->map_dup, 2);
	destroy_textures(info);
	mlx_terminate(info->mlx);
	log_info("Resources destroyed");
}
