/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:59:21 by mancorte          #+#    #+#             */
/*   Updated: 2025/03/16 02:45:20 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_extension_texture(char *str)
{
	int	len;
	
	len = bfl_strlen(str);
	len = len - 4;
	if (str[len + 1] != 'p' || str[len + 2] != 'n' || str[len + 3] != 'g')
	{
		bfl_fprintf(STDERR, "Error in extension file\n");
		return (BFL_LKO);
	}
	return (BFL_OK);
}

// add error log about which one fails
int	ft_extract_color_aux_f(t_cub *cub)
{
	int	tmp;

	tmp = 0;
	tmp = bfl_atoi(cub->f);
	if (tmp < 0 || tmp > 255)
		return (BFL_LKO);
	cub->floor_c.r = tmp;
	cub->f_aux = bfl_strchr(cub->f, ',');
	if (!cub->f_aux)
		return (BFL_LKO);
	tmp = bfl_atoi(cub->f_aux + 1);
	if (tmp < 0 || tmp > 255)
		return (BFL_LKO);
	cub->floor_c.g = tmp;
	cub->f_aux = bfl_strchr(cub->f_aux + 1, ',');
	if (!cub->f_aux)
		return (BFL_LKO);
	tmp = bfl_atoi(cub->f_aux + 1);
	if (tmp < 0 || tmp > 255)
		return (BFL_LKO);
	cub->floor_c.b = tmp;
	return (BFL_OK);
}

int	flood_fill(t_cub *cub, char **map, int x, int y)
{
	if (x < 0 || y < 0 || x >= cub->height || y >= cub->width)
		return (1);
	if (map[x][y] == WALL || map[x][y] == FILL)
		return (0);
	map[x][y] = FILL;
	if (flood_fill(cub, map, x - 1, y))
		return (1);
	if (flood_fill(cub, map, x, y - 1))
		return (1);
	if (flood_fill(cub, map, x + 1, y))
		return (1);
	if (flood_fill(cub, map, x, y + 1))
		return (1);
	return (0);
}

int	ft_init_pos(t_cub *cub)
{
	int	init_pos;

	init_pos = -1;
	cub->i = 0;
	while (cub->map[cub->i])
	{
		cub->j = 0;
		while (cub->map[cub->i][cub->j])
		{
			if (cub->map[cub->i][cub->j] == 'N'
				|| cub->map[cub->i][cub->j] == 'S'
				|| cub->map[cub->i][cub->j] == 'W'
				|| cub->map[cub->i][cub->j] == 'E')
			{
				cub->pos_x = cub->j;
				cub->pos_y = cub->i;
				init_pos++;
			}
			cub->j++;
		}
		cub->i++;
	}
	return (init_pos);
}

int	ft_map_functions(t_cub *cub)
{
	if (ft_check_map(cub) != CUB_OK)
		return (BFL_LKO);
	if (ft_init_pos(cub) != CUB_OK)
	{
		bfl_fprintf(STDERR, "Error in map (No player / Repeated)\n");
		cub->error = CUB_ERROR_MAP;
		return (CUB_LKO);
	}
	ft_duplicate_map(cub);
	if (flood_fill(cub, cub->map_dup, cub->pos_y, cub->pos_x))
	{
		bfl_printf("Error in map (Not closed)\n");
		cub->error = CUB_ERROR_MAP_NOT_CLOSED;
		return (CUB_LKO);
	}
	cub->error = END_GAME;
	return (CUB_OK);
}
