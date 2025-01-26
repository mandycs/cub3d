/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:22:22 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/01/19 14:22:22 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

/* @------------------------------------------------------------------------@ */
/* |                            Include Section                             | */
/* @------------------------------------------------------------------------@ */

# include "BFL.h"
# include "cub_log.h"
# include <stdbool.h>

/* @------------------------------------------------------------------------@ */
/* |                            Typedef Section                             | */
/* @------------------------------------------------------------------------@ */

typedef enum e_type			t_type;
typedef struct s_weapon		t_weapon;
typedef struct s_toolbar	t_toolbar;

/* @------------------------------------------------------------------------@ */
/* |                             Enum Section                               | */
/* @------------------------------------------------------------------------@ */

enum e_type
{
	HAND,
	KNIFE,
	GUN,
	SHOTGUN,
	MAX_TYPES,
};

/* @------------------------------------------------------------------------@ */
/* |                            Struct Section                              | */
/* @------------------------------------------------------------------------@ */

struct s_weapon
{
	t_type	type;
	char	name[32];
	int		damage;
	int		ammo;
	int		max_ammo;
	int		total_ammo;
	int		range;
};

struct s_toolbar
{
	t_weapon	weapons[MAX_TYPES];
	int			index;
	t_weapon	*current_weapon;
};

/* @------------------------------------------------------------------------@ */
/* |                           Function Section                             | */
/* @------------------------------------------------------------------------@ */

bool	create_weapon(t_weapon *weapon_address, t_type type);
void	attack(t_weapon *weapon);
void	reload_ammo(t_weapon *weapon);
void	switch_weapon(t_toolbar *toolbar, t_type type);
bool	create_toolbar(t_toolbar *toolbar);

#endif // WEAPON_H
