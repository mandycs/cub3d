/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:27:00 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/02/15 18:08:55 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

bool	create_screen(t_screen *screen, mlx_t *mlx)
{
	const int	pixel_size = mlx->width / 16;

	screen->width = mlx->width;
	screen->height = mlx->height;
	screen->view = mlx_new_image(mlx, screen->width, screen->height);
	screen->buffer = mlx_new_image(mlx, screen->width, screen->height);
	if (!screen->view || !screen->buffer)
		return (false);
	screen->scale = pixel_size / 4;
	log_info("Created screen");
	return (true);
}
