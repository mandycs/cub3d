/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:47 by ribana-b          #+#    #+#             */
/*   Updated: 2025/03/16 03:28:50 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	create_textures(t_info *info, t_cub *cub)
{
	int	i;

	i = 0;
	info->tex[i++] = mlx_load_png(cub->no);
	info->tex[i++] = mlx_load_png(cub->so);
	info->tex[i++] = mlx_load_png(cub->we);
	info->tex[i++] = mlx_load_png(cub->ea);
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
