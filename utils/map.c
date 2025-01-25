/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:37 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/01/25 15:47:30 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	destroy_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->data && map->data[i])
	{
		free(map->data[i]);
		++i;
	}
	free(map->data);
}

bool	create_map(t_map *map, t_cub *cub)
{
	map->data = cub->map;
	map->rows = cub->height;
	map->cols = cub->width;
	return (true);
}
