/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:46:31 by mancorte          #+#    #+#             */
/*   Updated: 2024/10/03 00:10:58 by mancorte         ###   ########.fr       */
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
enum					e_exit_status_cub
{
	CUB_OK = 0,     /**< 0 */
	CUB_LKO,        /**< 1 */
	CUB_RIP_MALLOC, /**< Amount of enums */
	CUB_RIP_READ,
	CUB_NO_TEXT,
	CUB_NO_PATH,
	CUB_ERROR_NO_PATH,
	CUB_ERROR_SO_PATH,
	CUB_ERROR_WE_PATH,
	CUB_ERROR_EA_PATH,
	CUB_ERROR_COLOR,
	CUB_ERROR_MAP,

};
/* @------------------------------------------------------------------------@ */
/* |                            Struct Section                              | */
/* @------------------------------------------------------------------------@ */
struct					s_cub
{
	int					fd;
	int					capacity;
	int					count;
	int					i;
	int					j;
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
	char				*f_aux;
	char				*c;
	int					fd_no;
	int					fd_so;
	int					fd_we;
	int					fd_ea;
	int					f_r;
	int					f_g;
	int					f_b;
	int					c_r;
	int					c_g;
	int					c_b;
	int					error;
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
void					ft_extract_path_texture(t_cub *cub, int flag);
int						ft_extract_color(t_cub *cub, int flag);
int						ft_extract_color_aux(t_cub *cub, int flag);
int						ft_extract_map(t_cub *cub);
void					ft_print_paths(t_cub *cub);
void					ft_free_cub(t_cub *cub);
void					initialize_cub(t_cub *cub);
void					ft_process_texture(t_cub *cub);
int						ft_check_paths(t_cub *cub);
int						ft_open_file(char *filename, int *fd, int flag, t_cub *cub);
int						ft_check_map(t_cub *cub);
int						ft_valid_color(t_cub *cub);
void					ft_check_error(t_cub *cub);
void					ft_paths_close(t_cub *cub);
void					ft_close_fd(t_cub *cub);
void					ft_check_error(t_cub *cub);
void					ft_check_error_2(t_cub *cub);
#endif
