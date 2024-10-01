/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:50:42 by mancorte          #+#    #+#             */
/*   Updated: 2024/10/02 00:27:20 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_valid_char(t_cub *cub)
{
	if (cub->text[cub->count][cub->i] == 'N'
		|| cub->text[cub->count][cub->i] == 'S'
		|| cub->text[cub->count][cub->i] == 'W'
		|| cub->text[cub->count][cub->i] == 'E'
		|| cub->text[cub->count][cub->i] == '1'
		|| cub->text[cub->count][cub->i] == '0')
		return (BFL_OK);
	else if (bfl_isspace(cub->text[cub->count][cub->i]))
		return (BFL_OK);
	else
		return (BFL_LKO);
}

void	ft_process_texture(t_cub *cub)
{
	if (bfl_strncmp(cub->text[cub->count], "NO", 2) == 0)
		ft_extract_path_texture(cub, 0);
	else if (bfl_strncmp(cub->text[cub->count], "SO", 2) == 0)
		ft_extract_path_texture(cub, 1);
	else if (bfl_strncmp(cub->text[cub->count], "WE", 2) == 0)
		ft_extract_path_texture(cub, 2);
	else if (bfl_strncmp(cub->text[cub->count], "EA", 2) == 0)
		ft_extract_path_texture(cub, 3);
	else if (bfl_strncmp(cub->text[cub->count], "F", 1) == 0)
		ft_extract_color(cub, 0);
	else if (bfl_strncmp(cub->text[cub->count], "C", 1) == 0)
		ft_extract_color(cub, 1);
}

void	ft_extract_path_texture(t_cub *cub, int flag)
{
	while (cub->text[cub->count][cub->i] != '.'
		&& cub->text[cub->count][cub->i])
		cub->i++;
	if (flag == 0)
		cub->no = bfl_strdup(&cub->text[cub->count][cub->i]);
	else if (flag == 1)
		cub->so = bfl_strdup(&cub->text[cub->count][cub->i]);
	else if (flag == 2)
		cub->we = bfl_strdup(&cub->text[cub->count][cub->i]);
	else if (flag == 3)
		cub->ea = bfl_strdup(&cub->text[cub->count][cub->i]);
	cub->count++;
	cub->i = 0;
}

void	ft_extract_color(t_cub *cub, int flag)
{
	while (!bfl_isdigit(cub->text[cub->count][cub->i]))
		cub->i++;
	if (flag == 0)
		cub->f = bfl_strdup(&cub->text[cub->count][cub->i]);
	else if (flag == 1)
		cub->c = bfl_strdup(&cub->text[cub->count][cub->i]);
	cub->count++;
	cub->i = 0;
}

int	ft_extract_map(t_cub *cub)
{
	int	len;
	int	tmp;

	tmp = 0;
	tmp = cub->count;
	len = 0;
	cub->i = 0;
	while (cub->text[cub->count])
	{
		cub->i = 0;
		while (cub->text[cub->count][cub->i])
			cub->i++;
		cub->count++;
		len++;
	}
	cub->map = bfl_calloc(len + 1, sizeof(char *));
	cub->i = 0;
	while (cub->text[tmp])
	{
		cub->map[cub->i] = bfl_strdup(cub->text[tmp]);
		cub->i++;
		tmp++;
	}
	return (BFL_OK);
}
