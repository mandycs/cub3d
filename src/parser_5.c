/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 02:12:40 by mancorte          #+#    #+#             */
/*   Updated: 2025/01/20 03:25:49 by mancorte         ###   ########.fr       */
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
	cub->width -= 1;
	while (i < cub->height)
	{
		if (i < cub->height - 1)
			bfl_strchr(cub->map[i], '\n')[0] = '\0';
		new_lines[i] = bfl_calloc(cub->width + 1, 1);
		bfl_strlcpy(new_lines[i], cub->map[i], cub->width);
		i++;
	}
	new_lines[i] = NULL;
	cub->map_dup = new_lines;
}

int	ft_mapextract(t_cub *cub)
{
	cub->i = 0;
	while (cub->text[cub->count] && cub->text[cub->count][cub->i])
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
		if (!bfl_isblank(cub->text[cub->count][cub->i])
			&& cub->text[cub->count][cub->i] != '\n')
		{
			bfl_fprintf(STDERR, "Error in map(Invalid Char)\n");
			cub->error = CUB_ERROR_MAP;
			return (CUB_LKO);
		}
		cub->i++;
	}
	return (CUB_OK);
}

int	ft_is_valid_map_char(char c)
{
	return (c != '1' && c != '0' && bfl_isspace(c) == 0 && c != 'N' && c != 'S'
		&& c != 'W' && c != 'E');
}
