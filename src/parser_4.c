/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:59:21 by mancorte          #+#    #+#             */
/*   Updated: 2025/01/18 23:22:17 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_extension_texture(char *str)
{
	int	i;
	int	tmp;
	int	len;

	tmp =0;
	i = 0;
	len = bfl_strlen(str);
	len = len - 4;
	printf("len = %d\n", len);
	printf("Extension =%s\n", str + len);
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

static void	flood_fill(t_cub *cub, ***map, int x, int y)
{
	if ((*map)[x][y] == WALL && (*map)[x][y] == FILL && x < 0 && y < 0 && x >= cub->width && y >= cub->height)
		return;
	(*map)[x][y] = FILL;
	flood_fill(cub, map, x - 1, y);
	flood_fill(cub, map, x, y - 1);
	flood_fill(cub, map, x + 1, y);
	flood_fill(cub, map, x, y + 1);
}

void	ft_init_pos(t_cub *cub)
{
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
			}
			cub->j++;
		}
	cub->i++;
	}
}

int	ft_map_functions(t_cub *cub)
{
	if (ft_check_map(cub) != CUB_OK)
		return (BFL_LKO);
	ft_init_pos(cub);
	ft_map_len(cub);
	ft_floodfill(cub, cub->map, cub->pos_x, cub->pos_y)
	
	return (CUB_OK);
}
