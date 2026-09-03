/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:43 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/03/17 12:28:42 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	render2(void *param)
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

void	render(void *param)
{
	t_info	*info;
	t_ray	ray;
	double	a;
	double	fa;

	info = param;
	render2(info);
	new_render_minimap(&info->screen, &info->map, &info->player);
	a = info->player.angle - round(info->player.fov * 0.5);
	fa = info->player.angle + round(info->player.fov * 0.5);
	while (a < fa)
	{
		ray = new_cast_ray(&info->screen, &info->map, &info->player,
				a * DEG2RAD);
		draw_line(info->screen.buffer, v2_create(ray.start.y, ray.start.x),
			v2_create(ray.map_check.y, ray.map_check.x), lightgreen());
		a += 0.1;
	}
	new_render_player(&info->screen, &info->player);
}
