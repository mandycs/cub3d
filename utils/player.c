/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:40 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/01/25 15:17:38 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// NOTE(srvariable): This will probably accept a map later on
// Also, maybe the fact that I multiply by PIXEL_SIZE to "scale" the position
// could be an issue
t_v2	get_player_position(void)
{
	t_v2	position;
	int		i;
	int		j;
	int		map_rows;

	i = -1;
	map_rows = sizeof(smap) / sizeof(smap[0]);
	while (++i < map_rows)
	{
		j = -1;
		while (++j < (int)bfl_strlen(smap[i]))
		{
			if (smap[i][j] == 'N')
			{
				position.x = (double)i * PIXEL_SIZE;
				position.y = (double)j * PIXEL_SIZE;
				return (position);
			}
		}
	}
	return (v2_create(-1, -1));
}

bool	create_player(t_player *player, t_cub *cub)
{
	player->position.x = cub->pos_y;
	player->position.y = cub->pos_x;
	if (!create_toolbar(&player->toolbar))
		return (false);
	player->speed = 10;
	player->fov = 90;
	player->angle = 0;
	log_info("Created player");
	return (true);
}
