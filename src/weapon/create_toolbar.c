/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_toolbar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:24:16 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/01/19 14:24:16 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "weapon.h"

bool	create_toolbar(t_toolbar *toolbar)
{
	t_type	type;

	type = 0;
	while (type < MAX_TYPES)
	{
		if (!create_weapon(&toolbar->weapons[type], type))
			return (false);
		++type;
	}
	toolbar->index = 0;
	toolbar->current_weapon = &toolbar->weapons[0];
	log_info("Created toolbar");
	return (true);
}
