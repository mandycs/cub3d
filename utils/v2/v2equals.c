/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2equals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:22:22 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/02/15 13:52:41 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	v2_equals(t_v2 v1, t_v2 v2)
{
	const int	epsilon = 1;

	return (v1.x >= v2.x - epsilon && v1.x <= v2.x + epsilon
		&& v1.y >= v2.y - epsilon && v1.y <= v2.y + epsilon);
}
