/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:29:36 by mancorte          #+#    #+#             */
/*   Updated: 2025/03/16 21:30:54 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int ft_remove_path_spaces_second(t_cub *cub)
{
	char	*tmp;

	tmp = bfl_strtrim(cub->we, " ");
	free(cub->we);
	if (!tmp)
		return (CUB_LKO);
	cub->we = bfl_strdup(tmp);
	free(tmp);
	tmp = bfl_strtrim(cub->ea, " ");
	free(cub->ea);
	if (!tmp)
		return (CUB_LKO);
	cub->ea = bfl_strdup(tmp);
	free(tmp);
	return (!cub->we && !cub->ea);
}