/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:59:21 by mancorte          #+#    #+#             */
/*   Updated: 2024/12/19 21:28:16 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_extension_texture(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '.')
		i++;
	if (str[i] == '\0')
	{
		bfl_fprintf(STDERR, "Error in extension file\n");
		return (BFL_LKO);
	}
	if (str[i + 1] == 'p' && str[i + 2] == 'n' && str[i + 3] == 'g')
		return (BFL_OK);
	bfl_fprintf(STDERR, "Error in extension file\n");
	return (BFL_LKO);
}

//add error log about which one fails
int	ft_extract_color_aux_f(t_cub *cub)
{
	int	tmp;
	
	tmp = 0;
	tmp = bfl_atoi(cub->f);
	if (tmp < 0 || tmp > 255)
		return(BFL_LKO);
	cub->floor_c.r = tmp;
	cub->f_aux = bfl_strchr(cub->f, ',');
	if (!cub->f_aux)
		return (BFL_LKO);
	tmp = bfl_atoi(cub->f_aux + 1);
	if (tmp < 0 || tmp > 255)
		return(BFL_LKO);
	cub->floor_c.g = tmp;
	cub->f_aux = bfl_strchr(cub->f_aux + 1, ',');
	if (!cub->f_aux)
		return (BFL_LKO);
	tmp = bfl_atoi(cub->f_aux + 1);
	if (tmp < 0 || tmp > 255)
		return(BFL_LKO);
	cub->floor_c.b = tmp;
	return (BFL_OK);
}
