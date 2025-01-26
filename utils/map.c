/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:37 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/01/26 19:53:30 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	create_map(t_map *map, t_cub *cub)
{
	map->data = cub->map;
	map->rows = cub->height;
	map->cols = cub->width;
	return (true);
}
