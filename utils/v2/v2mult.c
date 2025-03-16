/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2mult.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:25:07 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/02/15 13:53:42 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_v2	v2_mult(t_v2 v1, t_v2 v2)
{
	return ((t_v2){
		.x = v1.x * v2.x,
		.y = v1.y * v2.y,
	});
}

t_v2	v2_mult_scalar(t_v2 v1, double scalar)
{
	return ((t_v2){
		.x = v1.x * scalar,
		.y = v1.y * scalar,
	});
}
