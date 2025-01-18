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
