/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 02:12:40 by mancorte          #+#    #+#             */
/*   Updated: 2025/01/19 19:29:20 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_clean_paths(t_cub *cub)
{
	bfl_strrchr(cub->no, '\n')[0] = '\0';
	bfl_strrchr(cub->so, '\n')[0] = '\0';
	bfl_strrchr(cub->we, '\n')[0] = '\0';
	bfl_strrchr(cub->ea, '\n')[0] = '\0';
}

void	ft_duplicate_map(t_cub *cub)
{
	int		i;
	char	**new_lines;

	i = 0;
	new_lines = bfl_calloc(cub->height + 1, sizeof(char *));
	while (i < cub->height)
	{
		new_lines[i] = bfl_strdup(cub->map[i]);
		i++;
	}
	new_lines[i] = NULL;
	cub->map_dup = new_lines;
}

int	ft_mapextract(t_cub *cub)
{
	cub->i = 0;
	while (cub->text[cub->count][cub->i] && cub->text[cub->count])
	{
		if (cub->text[cub->count][cub->i] == '1'
			|| cub->text[cub->count][cub->i] == '0'
			|| cub->text[cub->count][cub->i] == 'N'
			|| cub->text[cub->count][cub->i] == 'S'
			|| cub->text[cub->count][cub->i] == 'W'
			|| cub->text[cub->count][cub->i] == 'E')
		{
			ft_extract_map(cub);
			break ;
		}
		if (!bfl_isblank(cub->text[cub->count][cub->i]) && cub->text[cub->count][cub->i] != '\n')
		{
			bfl_fprintf(STDERR, "Error in map(Invalid Char)\n");
			cub->error = CUB_ERROR_MAP;
			return (CUB_LKO);
		}
		cub->i++;
	}
	return (CUB_OK);
}
