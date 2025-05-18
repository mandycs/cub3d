/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:43 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/05/18 17:19:16 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	render(void *param)
{
	t_info	*info;
	double	fov;
	double	step_view;
	double	rangle_view;
	int		x;

	info = param;
	fov = info->player.fov * DEG2RAD;
	step_view = fov / info->screen.width;
	rangle_view = info->player.angle * DEG2RAD - (fov * 0.5);
	x = -1;
	while (++x < info->screen.width)
	{
		new_render_view(info, fmod(rangle_view + (x * step_view), 2 * M_PI), x,
			(t_color [2]){info->floor_color, info->ceiling_color});
	}
}
