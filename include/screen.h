/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:23:29 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/02/15 17:58:36 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H

/* @------------------------------------------------------------------------@ */
/* |                            Include Section                             | */
/* @------------------------------------------------------------------------@ */

# include "MLX42.h"
# include "cub_log.h"

/* @------------------------------------------------------------------------@ */
/* |                            Typedef Section                             | */
/* @------------------------------------------------------------------------@ */

typedef struct s_screen	t_screen;

/* @------------------------------------------------------------------------@ */
/* |                             Enum Section                               | */
/* @------------------------------------------------------------------------@ */

struct s_screen
{
	mlx_image_t	*view;
	mlx_image_t	*buffer;
	int			width;
	int			height;
	int			scale;
};

/* @------------------------------------------------------------------------@ */
/* |                           Function Section                             | */
/* @------------------------------------------------------------------------@ */

bool	create_screen(t_screen *screen, mlx_t *mlx);

#endif // SCREEN_H
