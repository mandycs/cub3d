/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 02:12:40 by mancorte          #+#    #+#             */
/*   Updated: 2024/12/21 02:56:37 by mancorte         ###   ########.fr       */
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
