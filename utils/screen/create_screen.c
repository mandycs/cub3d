/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:27:00 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/01/18 21:27:00 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

bool	create_screen(t_screen *screen, mlx_t *mlx)
{
	screen->width = mlx->width;
	screen->height = mlx->height;
	screen->view = mlx_new_image(mlx, screen->width, screen->height);
	screen->buffer = mlx_new_image(mlx, screen->width, screen->height);
	if (!screen->view || !screen->buffer)
		return (false);
	log_info("Created screen");
	return (true);
}
