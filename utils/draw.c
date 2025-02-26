/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:33 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/02/26 06:10:19 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	set_color(uint8_t *pixel, t_color color)
{
	pixel[0] = color.r;
	pixel[1] = color.g;
	pixel[2] = color.b;
	pixel[3] = color.a;
}

void	put_pixel(mlx_image_t *img, int x, int y, t_color color)
{
	int	pos;

	pos = y * img->width + x;
	if (pos < 0 || pos >= (int)(img->width * img->height))
	{
		log_error("Tried to put pixel, but is out of bounds!");
		return ;
	}
	set_color(&img->pixels[pos * sizeof(int)], color);
}

void	draw_rectangle(mlx_image_t *img, t_v2 position, t_v2 size,
		t_color color)
{
	int	i;
	int	j;

	i = position.x - 1;
	while (++i < position.x + size.x)
	{
		j = position.y - 1;
		while (++j < position.y + size.y)
		{
			if (i < 0 || i >= (int)img->width || j < 0 || j >= (int)img->height)
				return ;
			put_pixel(img, i, j, color);
		}
	}
}

void	draw_line(mlx_image_t *img, t_v2 start, t_v2 end, t_color color)
{
	int		step;
	t_v2	increment;
	t_v2	p;
	int		i;

	if (v2_equals(start, end))
		return ;
	step = calculate_step(end.x - start.x, end.y - start.y);
	increment.x = (end.x - start.x) / step;
	increment.y = (end.y - start.y) / step;
	p = start;
	i = -1;
	while (++i <= step)
	{
		if (p.x < 0 || p.x >= img->width || p.y < 0 || p.y >= img->height)
			return ;
		put_pixel(img, p.x, p.y, color);
		p.x += increment.x;
		p.y += increment.y;
	}
}
