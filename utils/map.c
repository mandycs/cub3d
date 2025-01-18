/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:37 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/01/18 21:26:38 by ribana-b         ###   ########.com      */
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

bool	create_map(t_map *map)
{
	if (!create_map_data(map))
		return (false);
	log_info("Created map");
	return (true);
}

void	temp_fill_map(t_map *map)
{
	for (int i = 0; i < map->rows; ++i)
	{
		for (int j = 0; j < map->cols; ++j)
		{
			map->data[i][j] = smap[i][j];
		}
	}
}

bool	create_map_data(t_map *map)
{
	int	i;

	map->rows = 10;
	map->cols = 21;
	map->data = malloc((map->rows + 1) * sizeof(char *));
	if (!map->data)
		return (false);
	i = -1;
	while (++i < map->rows)
	{
		map->data[i] = bfl_calloc((map->cols + 1), sizeof(char));
		if (!map->data[i])
		{
			destroy_map(map);
			return (false);
		}
	}
	map->data[i] = NULL;
	temp_fill_map(map);
	return (true);
}
