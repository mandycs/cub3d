/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_weapon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:24:22 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/01/19 14:24:26 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "weapon.h"

void	switch_weapon(t_toolbar *toolbar, t_type type)
{
	toolbar->current_weapon = &toolbar->weapons[type];
}
