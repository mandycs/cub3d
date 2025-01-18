#include "weapon.h"

static t_weapon	create_hand(void)
{
	t_weapon	weapon;

	weapon.type = HAND;
	bfl_memcpy(weapon.name, "HAND", 5);
	weapon.damage = 1;
	weapon.ammo = -1;
	weapon.max_ammo = -1;
	weapon.total_ammo = -1;
	weapon.range = 1;
	log_info("Created weapon HAND");
	return (weapon);
}

static t_weapon	create_knife(void)
{
	t_weapon	weapon;

	weapon.type = KNIFE;
	bfl_memcpy(weapon.name, "KNIFE", 6);
	weapon.damage = 2;
	weapon.ammo = -1;
	weapon.max_ammo = -1;
	weapon.total_ammo = -1;
	weapon.range = 1;
	log_info("Created weapon KNIFE");
	return (weapon);
}

static t_weapon	create_gun(void)
{
	t_weapon	weapon;

	weapon.type = GUN;
	bfl_memcpy(weapon.name, "GUN", 4);
	weapon.damage = 4;
	weapon.ammo = 16;
	weapon.max_ammo = 16;
	weapon.total_ammo = 64;
	weapon.range = 8;
	log_info("Created weapon GUN");
	return (weapon);
}

static t_weapon	create_shotgun(void)
{
	t_weapon	weapon;

	weapon.type = HAND;
	bfl_memcpy(weapon.name, "SHOTGUN", 8);
	weapon.damage = 10;
	weapon.ammo = 5;
	weapon.max_ammo = 5;
	weapon.total_ammo = 20;
	weapon.range = 3;
	log_info("Created weapon SHOTGUN");
	return (weapon);
}

bool	create_weapon(t_weapon *weapon, t_type type)
{
	if (type < 0 || type >= MAX_TYPES)
		return (false);
	if (type == HAND)
		*weapon = create_hand();
	else if (type == KNIFE)
		*weapon = create_knife();
	else if (type == GUN)
		*weapon = create_gun();
	else if (type == SHOTGUN)
		*weapon = create_shotgun();
	return (true);
}
