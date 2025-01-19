/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:47 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/01/18 22:48:27 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	create_textures(t_info *info)
{
	int	i;

	i = 0;
	info->tex[i++] = mlx_load_png("./sprites/red.png");
	info->tex[i++] = mlx_load_png("./sprites/green.png");
	info->tex[i++] = mlx_load_png("./sprites/yellow.png");
	info->tex[i++] = mlx_load_png("./sprites/purple.png");
	while (i--)
	{
		if (!info->tex[i])
			return (false);
		info->img[i] = mlx_texture_to_image(info->mlx, info->tex[i]);
		if (!info->img[i])
			return (false);
	}
	log_info("Created textures");
	return (true);
}

void	destroy_textures(t_info *info)
{
	int	i;

	i = 4;
	while (i--)
	{
		if (info->img[i])
			mlx_delete_image(info->mlx, info->img[i]);
		if (info->tex[i])
			mlx_delete_texture(info->tex[i]);
	}
}
