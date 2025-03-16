/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:40 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/03/16 20:25:51 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	create_player(t_player *player, t_cub *cub)
{
	player->position.x = cub->pos_y + 0.5;
	player->position.y = cub->pos_x + 0.5;
	if (!create_toolbar(&player->toolbar))
		return (false);
	player->speed = 1;
	player->fov = 60;
	if (cub->map[cub->pos_y][cub->pos_x] == 'E')
		player->angle = 0;
	else if (cub->map[cub->pos_y][cub->pos_x] == 'S')
		player->angle = 90;
	else if (cub->map[cub->pos_y][cub->pos_x] == 'W')
		player->angle = 180;
	else if (cub->map[cub->pos_y][cub->pos_x] == 'N')
		player->angle = 270;
	log_info("Created player");
	return (true);
}
