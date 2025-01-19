/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:24:13 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/01/19 14:24:14 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "weapon.h"

static void	reduce_ammo(t_weapon *weapon)
{
	if (weapon->total_ammo <= 0 && weapon->ammo <= 0)
		return ;
	if (weapon->ammo == 0)
		reload_ammo(weapon);
	--weapon->ammo;
	log_info("Reduce ammo");
}

void	attack(t_weapon *weapon)
{
	if (weapon->ammo == 0 && weapon->total_ammo == 0)
	{
		log_info("No ammo");
		return ;
	}
	log_info("Attack");
	reduce_ammo(weapon);
}
