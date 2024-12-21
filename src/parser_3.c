/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 22:25:03 by mancorte          #+#    #+#             */
/*   Updated: 2024/12/21 02:08:19 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// CAMBIAR LA FUNCION OPEN EN BASE A LO DE CUB AÑADIDO
int	ft_check_paths(t_cub *cub)
{
	if (cub->no == NULL || cub->so == NULL || cub->we == NULL || cub->ea == NULL
		|| cub->f == NULL || cub->c == NULL)
	{
		bfl_fprintf(STDERR, "Error (Missing path/color)\n");
		cub->error = CUB_NO_PATH;
		return (CUB_LKO);
	}
	ft_clean_paths(cub);
	if (ft_open_file(cub->no, &cub->fd_no, 6, cub) != CUB_OK)
		return (CUB_LKO);
	if (ft_open_file(cub->so, &cub->fd_so, 7, cub) != CUB_OK)
		return (CUB_LKO);
	if (ft_open_file(cub->we, &cub->fd_we, 8, cub) != CUB_OK)
		return (CUB_LKO);
	if (ft_open_file(cub->ea, &cub->fd_ea, 9, cub) != CUB_OK)
		return (CUB_LKO);
	return (CUB_OK);
}

int	ft_open_file(char *filename, int *fd, int flag, t_cub *cub)
{
	if (ft_check_extension_texture(filename))
	{
		bfl_fprintf(STDERR, "Error in extension in file '%s'\n", filename);
		return (CUB_LKO);
	}
	printf( "%s",filename);
	*fd = open("./test.png", O_RDONLY);
	if (*fd == -1)
	{
		printf("El fd es %d\n", *fd);
		cub->error = flag;
		bfl_fprintf(STDERR, "Error in opening file '%s'\n", filename);
		return (BFL_LKO);
	}
	return (BFL_OK);
}

// FALTA QUE SI NO HAY MAPA DEVUELVA ERROR
int	ft_check_map(t_cub *cub)
{
	cub->i = 0;
	if (!cub->map[cub->i])
		return (CUB_ERROR_NO_MAP);
	while (cub->map[cub->i])
	{
		cub->j = 0;
		while (cub->map[cub->i][cub->j])
		{
			if (cub->map[cub->i][cub->j] != '1'
				&& cub->map[cub->i][cub->j] != '0'
				&& bfl_isspace(cub->map[cub->i][cub->j]) == 0
				&& cub->map[cub->i][cub->j] != 'N'
				&& cub->map[cub->i][cub->j] != 'S'
				&& cub->map[cub->i][cub->j] != 'W'
				&& cub->map[cub->i][cub->j] != 'E')
			{
				cub->error = CUB_ERROR_MAP;
				bfl_fprintf(STDERR, "Error in map (Invalid char)\n");
				return (CUB_LKO);
			}
			cub->j++;
		}
		cub->i++;
	}
	return (CUB_OK);
}

void	ft_map_len(t_cub *cub)
{
	cub->i = 0;
	cub->len = 0;
	while (cub->map[cub->i])
	{
		cub->tmp = bfl_strlen(cub->map[cub->i]);
		if (cub->tmp > cub->len)
			cub->len = cub->tmp;
		cub->i++;
	}
}
