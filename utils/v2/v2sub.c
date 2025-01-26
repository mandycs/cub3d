/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2sub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:25:08 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/01/18 21:25:19 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_v2	v2_sub(t_v2 *v1, t_v2 *v2)
{
	return ((t_v2){
		.x = v1->x - v2->x,
		.y = v1->y - v2->y,
	});
}

t_v2	v2_sub_scalar(t_v2 *v1, double scalar)
{
	return ((t_v2){
		.x = v1->x - scalar,
		.y = v1->y - scalar,
	});
}
