/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 22:20:39 by mancorte          #+#    #+#             */
/*   Updated: 2025/05/08 11:16:16 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_arg(int argc, char **argv, t_cub *cub)
{
	cub->fd = -1;
	cub->count = 0;
	if (argc != 2)
	{
		bfl_fprintf(STDERR, "Error in number of arguments \n");
		return (CUB_LKO);
	}
	if (ft_check_extension(argv[1]) != CUB_OK)
		return (CUB_LKO);
	cub->fd = ft_extract_path(argv[1]);
	if (cub->fd < 0)
		return (CUB_LKO);
	if (ft_read_file(cub) != CUB_OK)
		return (CUB_RIP_READ);
	if (ft_extract_text(cub) != CUB_OK)
		return (CUB_LKO);
	if (ft_check_paths(cub) != CUB_OK)
		return (CUB_LKO);
	if (ft_remove_path_spaces(cub) != CUB_OK)
	{
		cub->error = CUB_ERROR_PATH;
		return (CUB_LKO);
	}
	ft_map_functions(cub);
	return (BFL_OK);
}

int	ft_check_extension(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = bfl_strtrim(str, " ");
	if (!tmp)
		return (CUB_LKO);
	while (tmp[i] != '\0' && tmp[i] != '.')
		i++;
	if (tmp[i] == '\0')
	{
		bfl_fprintf(STDERR, "Error in extension file\n");
		free(tmp);
		return (BFL_LKO);
	}
	if (tmp[i + 1] == 'c' && tmp[i + 2] == 'u' && tmp[i + 3] == 'b')
	{
		free(tmp);
		return (BFL_OK);
	}
	free(tmp);
	bfl_fprintf(STDERR, "Error in extension file\n");
	return (BFL_LKO);
}

int	ft_extract_path(char *filename)
{
	int		fd;
	char	*tmp;

	tmp = bfl_strtrim(filename, " ");
	if (!tmp)
		return (-1);
	fd = open(tmp, O_RDONLY);
	free(tmp);
	if (fd == -1)
	{
		bfl_fprintf(STDERR, "Error in opening file\n");
		return (fd);
	}
	return (fd);
}

int	ft_read_file(t_cub *cub)
{
	cub->capacity = INITIAL_CAPACITY;
	cub->text = bfl_calloc(cub->capacity, sizeof(char *));
	if (!cub->text)
		return (CUB_RIP_MALLOC);
	cub->line = get_next_line(cub->fd);
	while (cub->line)
	{
		if (cub->count >= cub->capacity)
		{
			cub->capacity *= 2;
			cub->new_lines = bfl_realloc(cub->text, cub->count, cub->capacity,
					sizeof(char *));
			if (!cub->new_lines)
			{
				bfl_free(&cub->text, 2);
				return (CUB_RIP_MALLOC);
			}
			cub->text = cub->new_lines;
		}
		cub->text[cub->count++] = bfl_strdup(cub->line);
		bfl_free(&cub->line, 1);
		cub->line = get_next_line(cub->fd);
	}
	cub->text[cub->count] = NULL;
	return (CUB_OK);
}

int	ft_extract_text(t_cub *cub)
{
	cub->count = 0;
	if (!cub->text || !cub->text[cub->count])
	{
		cub->error = CUB_NO_TEXT;
		return (CUB_LKO);
	}
	while (cub->text[cub->count])
	{
		cub->i = 0;
		while (cub->text[cub->count] && cub->text[cub->count][cub->i]
			&& cub->flag < 6)
		{
			ft_process_texture(cub);
			if (cub->text[cub->count] && cub->text[cub->count][cub->i] == '\n')
				break ;
			cub->i++;
		}
		cub->count++;
		if (cub->flag == 6 && ft_mapextract(cub) != CUB_OK)
			return (CUB_LKO);
	}
	if (cub->height == 0 || cub->width == 0)
		return (ft_check_paths(cub));
	return (CUB_OK);
}
