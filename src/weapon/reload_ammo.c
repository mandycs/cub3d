/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_ammo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:24:20 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/01/19 14:24:21 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "weapon.h"

void	reload_ammo(t_weapon *weapon)
{
	if (weapon->max_ammo > weapon->total_ammo)
	{
		weapon->ammo = weapon->total_ammo;
		weapon->total_ammo = 0;
	}
	else
	{
		weapon->ammo = weapon->max_ammo;
		weapon->total_ammo -= weapon->max_ammo;
	}
	log_info("Reload ammo");
}
