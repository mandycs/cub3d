/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 22:22:16 by mancorte          #+#    #+#             */
/*   Updated: 2025/01/19 19:09:16 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	cub->i += 2;
	while (bfl_isblank(cub->text[cub->count][cub->i]))
		cub->i++;
	if (cub->text[cub->count][cub->i] != '.' && cub->text[cub->count][cub->i])
	{
		bfl_fprintf(STDERR, "Error (Invalid format in Path)\n");
		cub->error = CUB_NO_PATH;
		return ;
	}
	if (flag == 0)
		cub->no = bfl_strdup(&cub->text[cub->count][cub->i]);
	else if (flag == 1)
		cub->so = bfl_strdup(&cub->text[cub->count][cub->i]);
	else if (flag == 2)
		cub->we = bfl_strdup(&cub->text[cub->count][cub->i]);
	else if (flag == 3)
		cub->ea = bfl_strdup(&cub->text[cub->count][cub->i]);
	cub->count++;
	cub->flag++;
	cub->i = 0;
}

int	ft_extract_color(t_cub *cub, int flag)
{
	cub->i++;
	while (bfl_isblank(cub->text[cub->count][cub->i]))
		cub->i++;
	if (!bfl_isdigit(cub->text[cub->count][cub->i]))
	{
		bfl_fprintf(STDERR, "Error (Invalid format color)\n");
		return (BFL_LKO);
	}
	if (flag == 0 && cub->text[cub->count][cub->i])
	{
		cub->f = bfl_strdup(&cub->text[cub->count][cub->i]);
		if (ft_extract_color_aux_f(cub) == BFL_LKO)
			return (BFL_LKO);
	}
	else if (flag == 1 && cub->text[cub->count][cub->i])
	{
		cub->c = bfl_strdup(&cub->text[cub->count][cub->i]);
		if (ft_extract_color_aux_c(cub) == BFL_LKO)
			return (BFL_LKO);
	}
	cub->count++;
	cub->i = 0;
	cub->flag++;
	return (BFL_OK);
}

int	ft_extract_map(t_cub *cub)
{
	int	tmp;
	
	tmp = 0;
	tmp = cub->count;
	cub->height = 0;
	cub->i = 0;
	
	while (cub->text[cub->count])
	{
		if (bfl_strlen(cub->text[cub->count]) > (size_t)cub->width)
			cub->width = bfl_strlen(cub->text[cub->count]);
		cub->count++;
		cub->height++;
	}
	cub->map = bfl_calloc(cub->height + 1, sizeof(char *));
	while (cub->text[tmp])
	{
		cub->map[cub->i] = bfl_calloc(cub->width + 1, 1);
		bfl_strlcpy(cub->map[cub->i], cub->text[tmp], bfl_strlen(cub->text[tmp]));
		cub->i++;
		tmp++;
	}
	cub->map[cub->i] = NULL;
	return (BFL_OK);
}

int	ft_extract_color_aux_c(t_cub *cub)
{
	int	tmp;

	tmp = 0;
	tmp = bfl_atoi(cub->f);
	if (tmp < 0 || tmp > 255)
		return (BFL_LKO);
	cub->ceiling_c.r = tmp;
	cub->f_aux = bfl_strchr(cub->f, ',');
	if (!cub->f_aux)
		return (BFL_LKO);
	tmp = bfl_atoi(cub->f_aux + 1);
	if (tmp < 0 || tmp > 255)
		return (BFL_LKO);
	cub->ceiling_c.g = tmp;
	cub->f_aux = bfl_strchr(cub->f_aux + 1, ',');
	if (!cub->f_aux)
		return (BFL_LKO);
	tmp = bfl_atoi(cub->f_aux + 1);
	if (tmp < 0 || tmp > 255)
		return (BFL_LKO);
	cub->ceiling_c.b = tmp;
	return (BFL_OK);
}
