/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:26:46 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/01/18 21:26:47 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	rotate_left(t_info *info)
{
	info->player.angle = bfl_mod(info->player.angle - 1, 360);
	log_info("Rotate left");
}

void	rotate_right(t_info *info)
{
	info->player.angle = bfl_mod(info->player.angle + 1, 360);
	log_info("Rotate right");
}
