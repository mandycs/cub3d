/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:46:31 by mancorte          #+#    #+#             */
/*   Updated: 2024/10/02 01:13:40 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* @------------------------------------------------------------------------@ */
/* |                            Define Section                              | */
/* @------------------------------------------------------------------------@ */
# define INITIAL_CAPACITY 16
/* @------------------------------------------------------------------------@ */
/* |                            Include Section                             | */
/* @------------------------------------------------------------------------@ */

# include "BFL.h"
# include <fcntl.h>
# include <stdio.h>

/* @------------------------------------------------------------------------@ */
/* |                            Typedef Section                             | */
/* @------------------------------------------------------------------------@ */
typedef struct s_cub	t_cub;
/* @------------------------------------------------------------------------@ */
/* |                             Enum Section                               | */
/* @------------------------------------------------------------------------@ */

/* @------------------------------------------------------------------------@ */
/* |                            Struct Section                              | */
/* @------------------------------------------------------------------------@ */
struct					s_cub
{
	int					fd;
	int					capacity;
	int					count;
	int					i;
	char				**text;
	char				**map;
	int					tmp;
	int					len;
	char				*line;
	char				**new_lines;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				*f;
	char				*c;
	int					fd_no;
	int					fd_so;
	int					fd_we;
	int					fd_ea;
	int					fd_f;
	int					fd_c;
};
/* @------------------------------------------------------------------------@ */
/* |                           Function Section                             | */
/* @------------------------------------------------------------------------@ */

void					ribanab(void);
int						ft_check_arg(int argc, char **argv, t_cub *cub);
int						ft_check_extension(char *str);
int						ft_extract_path(char *filename);
int						ft_read_file(t_cub *cub);
void					ft_print_map(t_cub *cub);
int						ft_extract_text(t_cub *cub);
int						ft_valid_char(t_cub *cub);
void					ft_extract_path_texture(t_cub *cub, int flag);
void					ft_extract_color(t_cub *cub, int flag);
int						ft_extract_map(t_cub *cub);
void					ft_print_paths(t_cub *cub);
void					ft_free_cub(t_cub *cub);
void					initialize_cub(t_cub *cub);
void					ft_process_texture(t_cub *cub);
int						ft_check_paths(t_cub *cub);
int						ft_open_file(char *filename, int *fd);
#endif
