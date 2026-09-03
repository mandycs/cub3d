/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:43 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/03/17 12:08:07 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	render2(void *param)
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

static void	render_ray(t_screen *screen,
					t_map *map,
					t_player *player,
					double rangle)
{
	const int	size = screen->scale;
	t_ray		ray;
	double		x;
	double		y;
	double		endx;
	double		endy;

	ray = new_cast_ray(screen, map, player, rangle);
	x = ray.start.x;
	y = ray.start.y;
	if (ray.start.y / size >= size)
		y = (y - (ray.start.y - size)) * size;
	if (map->cols - ray.start.y / size < size)
		y = (2 * size - (map->cols - ray.start.y) - 1) * size;
	if (ray.start.x / size >= size)
		x = (x - (ray.start.x - size)) * size;
	if (map->rows - ray.start.x / size < size)
		x = (2 * size - (map->rows - ray.start.x) - 1) * size;

	endx = ray.map_check.x;
	endy = ray.map_check.y;

	endy = (int)ray.map_check.y + size;
	if (y <= -1)
	{
		endy = (int)ray.map_check.y + size - fmod(ray.map_check.y + 1, size);
	}
	if (endy >= size)
	{
		endy = size;
	}

	printf("=============================================\n");
	printf("ray.map_check:      %f %f\n\
ray.map_check/size: %f %f\n\
start:              %f %f\n\
end:                %f %f\n\
start/size:         %f %f\n\
end/size:           %f %f\n\
size:               %d\n",
			ray.map_check.y, ray.map_check.x,
			ray.map_check.y/size, ray.map_check.x/size,
			y, x,
			endy, endx,
			y/size, x/size,
			endy / size, endx / size,
			size);
	draw_line(screen->buffer,
			v2_create(
				y,
				x
			),
			v2_create(
				endy,
				endx
			),
		lightgreen());
}

void	render(void *param)
{
	t_info	*info;
	double	a;
	double	fa;

	info = param;
	render2(info);
	new_render_minimap(&info->screen, &info->map, &info->player);
	a = info->player.angle - round(info->player.fov * 0.5);
	fa = info->player.angle + round(info->player.fov * 0.5);
	while (a < fa)
	{
		render_ray(&info->screen, &info->map, &info->player, a * DEG2RAD);
		a += 0.1;
	}
	new_render_player(&info->screen, &info->player, &info->map);
}
