/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:25:51 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/01/18 21:25:51 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

t_color	get_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return ((t_color){
		.r = r,
		.g = g,
		.b = b,
		.a = a,
	});
}
