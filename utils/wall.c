/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:32:35 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/03/16 19:35:45 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_color	get_texture_color(mlx_image_t *img, int x, int y)
{
	t_color			color;
	const uint32_t	pos = ((uint32_t)y * img->width + x) * 4;

	if (x < 0 || y < 0 || x >= (int)img->width || y >= (int)img->height)
		return (black());
	color.r = img->pixels[pos + 0];
	color.g = img->pixels[pos + 1];
	color.b = img->pixels[pos + 2];
	color.a = img->pixels[pos + 3];
	return (color);
}

t_wall	init_wall(t_ray *ray, t_screen *screen, t_player *player, double rangle)
{
	const double	size = screen->scale;
	t_wall			wall;

	wall.height = (int)(screen->height * size
			/ (ray->distance * cos(rangle - (player->angle * DEG2RAD))));
	wall.draw_start = screen->height / 2 - wall.height / 2;
	if (wall.draw_start < 0)
		wall.draw_start = 0;
	wall.draw_end = wall.draw_start + wall.height;
	if (wall.draw_end >= screen->height)
		wall.draw_end = screen->height - 1;
	wall.tex_num = 0;
	if (ray->side == 0)
		wall.x = (ray->start.y + ray->distance * ray->dir.y) / size;
	else
		wall.x = (ray->start.x + ray->distance * ray->dir.x) / size;
	wall.x -= (int)wall.x;
	return (wall);
}

void	init_textures(t_wall *wall,
						t_ray *ray,
						mlx_image_t *img[4],
						t_screen *screen)
{
	if (ray->side == 0 && ray->dir.x > 0)
		wall->tex_num = 1;
	else if (ray->side == 0 && ray->dir.x <= 0)
		wall->tex_num = 0;
	if (ray->side == 1 && ray->dir.y > 0)
		wall->tex_num = 3;
	else if (ray->side == 1 && ray->dir.y <= 0)
		wall->tex_num = 2;
	wall->tex_x = (int)(wall->x * (double)img[wall->tex_num]->width);
	if ((ray->side == 0 && ray->dir.x > 0)
		|| (ray->side == 1 && ray->dir.y < 0))
		wall->tex_x = img[wall->tex_num]->width - wall->tex_x - 1;
	wall->tex_step = img[wall->tex_num]->height / (double)wall->height;
	wall->tex_pos = 0;
	if (wall->height > screen->height)
	{
		wall->tex_pos = (wall->draw_start
				- screen->height * 0.5
				+ wall->height * 0.5) * wall->tex_step;
	}
}

void	paint_wall(t_wall *wall, t_screen *screen, mlx_image_t *img[4], int x)
{
	int		y;
	t_color	color;

	y = wall->draw_start - 1;
	while (++y <= wall->draw_end)
	{
		wall->tex_y = (int)wall->tex_pos;
		if (wall->tex_y >= (int)img[wall->tex_num]->height)
			wall->tex_y = img[wall->tex_num]->height - 1;
		color = get_texture_color(img[wall->tex_num], wall->tex_x, wall->tex_y);
		put_pixel(screen->buffer, x, y, color);
		wall->tex_pos += wall->tex_step;
	}
}

void	new_render_view(t_info *info, double rangle, int x, t_color *color)
{
	t_ray	ray;
	t_wall	wall;

	ray = new_cast_ray(&info->screen, &info->map, &info->player, rangle);
	if (!ray.hit)
		return ;
	wall = init_wall(&ray, &info->screen, &info->player, rangle);
	init_textures(&wall, &ray, info->img, &info->screen);
	paint_wall(&wall, &info->screen, info->img, x);
	if (wall.draw_start > 0)
		draw_line(info->screen.buffer, v2_create(x, 0),
			v2_create(x, wall.draw_start - 1), color[1]);
	if (wall.draw_end < info->screen.height - 1)
		draw_line(info->screen.buffer, v2_create(x, wall.draw_end + 1),
			v2_create(x, info->screen.height - 1), color[0]);
}
