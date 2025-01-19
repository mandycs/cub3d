/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 22:20:39 by mancorte          #+#    #+#             */
/*   Updated: 2025/01/19 19:26:14 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_arg(int argc, char **argv, t_cub *cub)
{
	cub->fd = 0;
	cub->count = 0;
	if (argc != 2)
	{
		bfl_fprintf(STDERR, "Error in number of arguments \n");
		return (CUB_LKO);
	}
	if (ft_check_extension(argv[1]) != CUB_OK)
		return (CUB_LKO);
	cub->fd = ft_extract_path(argv[1]);
	if (cub->fd == CUB_OK)
		return (CUB_LKO);
	if (ft_read_file(cub) != CUB_OK)
		return (CUB_RIP_READ);
	if (ft_extract_text(cub) != CUB_OK)
		return (CUB_LKO);
	if (ft_check_paths(cub) != CUB_OK)
		return (CUB_LKO);
	ft_map_functions(cub);
	return (BFL_OK);
}

int	ft_check_extension(char *str)
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
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b')
		return (BFL_OK);
	bfl_fprintf(STDERR, "Error in extension file\n");
	return (BFL_LKO);
}

int	ft_extract_path(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		bfl_fprintf(STDERR, "Error in opening file\n");
		return (BFL_LKO);
	}
	return (fd);
}

int	ft_read_file(t_cub *cub)
{
	cub->capacity = INITIAL_CAPACITY;
	cub->text = bfl_calloc(cub->capacity, sizeof(char *));
	if (!cub->text)
	{
		bfl_free(cub->text, 2);
		return (CUB_RIP_MALLOC);
	}
	while ((cub->line = get_next_line(cub->fd)))
	{
		if (cub->count >= cub->capacity)
		{
			cub->capacity *= 2;
			cub->new_lines = bfl_realloc(cub->text, cub->count, cub->capacity,
					sizeof(char *));
			if (!cub->new_lines)
			{
				bfl_free(cub->text, 2);
				return (CUB_RIP_MALLOC);
			}
			cub->text = cub->new_lines;
		}
		cub->text[cub->count++] = cub->line;
	}
	cub->text[cub->count] = NULL;
	return (CUB_OK);
}

int	ft_extract_text(t_cub *cub)
{
	cub->count = 0;
	if (!cub->text && !cub->text[cub->count])
	{
		cub->error = CUB_NO_TEXT;
		return (CUB_LKO);
	}
	while (cub->text[cub->count])
	{
		cub->i = 0;
		while (cub->text[cub->count][cub->i] && cub->text[cub->count] && cub->flag < 6)
		{
			ft_process_texture(cub);
			if (cub->text[cub->count][cub->i] == '\n')
				break ;
			cub->i++;
		}
		cub->count++;
		if (cub->flag == 6)
			if (ft_mapextract(cub) != CUB_OK)
				return (CUB_LKO);
	}
	return (CUB_OK);
}
