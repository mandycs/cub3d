/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:49:31 by mancorte          #+#    #+#             */
/*   Updated: 2024/10/01 18:06:39 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_arg(int argc, char **argv, t_cub *cub)
{
	cub->fd = 0;
	if (argc != 2)
	{
		bfl_fprintf(STDERR, "Error in number of arguments \n");
		return (BFL_INVALID_ARGC);
	}
	if (ft_check_extension(argv[1]) != BFL_OK)
		return (BFL_LKO);
	cub->fd = ft_extract_path(argv[1]);
	if (cub->fd == BFL_LKO)
		return (BFL_LKO);
	ft_read_file(cub);
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
	return (BFL_OK);
}

int	ft_extract_path(char *filename)
{
	int	fd;

	cub->count = 0;
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
	cub->text = malloc(sizeof(char *) * cub->capacity);
	if (!cub->text)
	{
		bfl_free(cub->text, 2);
		return (BFL_RIP_MALLOC);
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
				return (BFL_RIP_MALLOC);
			}
			cub->text = cub->new_lines;
		}
		cub->text[cub->count++] = cub->line;
	}
	cub->text[cub->count] = NULL;
	return (BFL_OK);
}
